#include "bouton.h"
#include <SDL/SDL_ttf.h>
#include "configuration.h"

Bouton::Bouton(std::string texte, sint32 x, sint32 y, sint32 code)
{
    // Position du bouton
    this->positionX = x;
    this->positionY = y;
    this->etat = PAS_SURVOLE;

    this->code = code;

    // Creation de la texture du texte
    this->textureTexte = this->creerTextureTexte(texte);

    // Chargement des trois images du bouton
    this->conteneurTextures.ajouter("bouton_pas_survole.bmp");
    this->conteneurTextures.ajouter("bouton_survole.bmp");
    this->conteneurTextures.ajouter("bouton_enfonce.bmp");
}

Bouton::~Bouton()
{
    glDeleteTextures(1, &this->textureTexte);

    // Chargement des trois images du bouton
    this->conteneurTextures.supprimer("bouton_pas_survole.bmp");
    this->conteneurTextures.supprimer("bouton_survole.bmp");
    this->conteneurTextures.supprimer("bouton_enfonce.bmp");
}

GLuint Bouton::creerTextureTexte(std::string texte)
{
    // Chargement de la police du bouton
    TTF_Font* police = TTF_OpenFont("test.ttf", 35);
    if (NULL == police)
    {
        printf("Impossible de charger le fichier Cartonsix NC.ttf");
    }

    // Creation de l'image du texte avec la police associee
    SDL_Color couleurTexte = {50, 50, 50};
    SDL_Surface* texteBouton = TTF_RenderText_Blended(police, texte.c_str(), couleurTexte);
    if (NULL == texteBouton)
    {
        printf("Impossible de créer le texte du bouton");
    }

    // Liberation de la police
    TTF_CloseFont(police);

    // Activation de la transparence
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Generation de la texture pour le texte du bouton
    GLuint textureTexte;
    glGenTextures( 1, &textureTexte );

    // Selection de la texture generee
    glBindTexture( GL_TEXTURE_2D, textureTexte );

    // Parametrage
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // Detection du codage des pixels
    GLenum codagePixel;
    if (texteBouton->format->Rmask == 0x000000ff)
    {
        codagePixel = GL_RGBA;
    }
    else
    {
        #ifndef GL_BGRA
            #define GL_BGRA 0x80E1
        #endif
        codagePixel = GL_BGRA;
    }

    // Chargement de la texture du texte precedament creee
    glTexImage2D( GL_TEXTURE_2D, 0, 4, texteBouton->w, texteBouton->h, 0,
                  codagePixel, GL_UNSIGNED_BYTE, texteBouton->pixels );

    //Recuperation des dimentions du texte
    this->largeurTexte = texteBouton->w;
    this->hauteurTexte = texteBouton->h;

    // Liberation de l'image du texte du bouton
    SDL_FreeSurface( texteBouton );

    return textureTexte;
}

void Bouton::dessiner(void)
{
    // Lecture de l'etat du bouton
    Bouton::Etat etatBouton = this->lectureEtatBouton();

    // Si le bouton a ete clique
    if (SURVOLE == etatBouton // Etat actuel
     && ENFONCE == this->etat // Etat precedent
     )
    {
        // On genere un evenement
        SDL_Event evenement;
        evenement.type = BOUTON_CLIQUE;
        evenement.user.code = this->code;
        SDL_PushEvent(&evenement);
    }

    // On memorise l'etat du bouton
    this->etat = etatBouton;

    // Affichage de l'image du bouton en fonction de son etat
    switch(this->etat)
    {
        case PAS_SURVOLE:
            this->dessinerFond("bouton_pas_survole.bmp");
            break;

        case SURVOLE:
            this->dessinerFond("bouton_survole.bmp");
            break;

        case ENFONCE:
            this->dessinerFond("bouton_enfonce.bmp");
            break;
    }

    // Dessin du texte du bouton
    this->dessinerTexte();
}

Bouton::Etat Bouton::lectureEtatBouton(void)
{
    // Lecture de l'etat de la souris
    sint32 x, y;
    bool8 boutonEnfonce;
    if( 0 != (SDL_GetMouseState((int*)&x, (int*)&y) & SDL_BUTTON(SDL_BUTTON_LEFT)) )
    {
        boutonEnfonce = TRUE;
    }
    else
    {
        boutonEnfonce = FALSE;
    }

    // Recuperation des dimensions du bouton
    uint32 largeurBouton = this->conteneurTextures.texture("bouton_pas_survole.bmp").largeur;
    uint32 hauteurBouton = this->conteneurTextures.texture("bouton_pas_survole.bmp").hauteur;

    // Si la souris est sur le bouton
    if(x > this->positionX - (sint32)(largeurBouton/2) && x < this->positionX + (sint32)(largeurBouton/2)
       && y > this->positionY - (sint32)(hauteurBouton/2) && y < this->positionY + (sint32)(hauteurBouton/2))
    {
        if(TRUE == boutonEnfonce)
        {
            return ENFONCE;
        }
        else
        {
            return SURVOLE;
        }
    }
    else
    {
        return PAS_SURVOLE;
    }
}

void Bouton::dessinerFond(std::string image)
{
    // Selection de l'image du bouton
    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture(image).texture);

    // Recuperation des dimentions du boutons
    uint32 largeurBouton = this->conteneurTextures.texture(image).largeur;
    uint32 hauteurBouton = this->conteneurTextures.texture(image).hauteur;

    // Application de l'image du bouton
    glBegin(GL_QUADS);
        glTexCoord2i(0, 0); glVertex2i( this->positionX - (largeurBouton/2), HAUTEUR_FENETRE - this->positionY + (hauteurBouton/2));
        glTexCoord2i(0, 1); glVertex2i( this->positionX - (largeurBouton/2), HAUTEUR_FENETRE - this->positionY - (hauteurBouton/2));
        glTexCoord2i(1, 1); glVertex2i( this->positionX + (largeurBouton/2), HAUTEUR_FENETRE - this->positionY - (hauteurBouton/2));
        glTexCoord2i(1, 0); glVertex2i( this->positionX + (largeurBouton/2), HAUTEUR_FENETRE - this->positionY + (hauteurBouton/2));
    glEnd();
}

void Bouton::dessinerTexte(void)
{
    // Selection de la texture du texte
    glBindTexture( GL_TEXTURE_2D, this->textureTexte );

    // Application du texte
    glBegin(GL_QUADS);
        glTexCoord2i(0, 0); glVertex2i( this->positionX - (this->largeurTexte/2), HAUTEUR_FENETRE - this->positionY + (this->hauteurTexte/2));
        glTexCoord2i(0, 1); glVertex2i( this->positionX - (this->largeurTexte/2), HAUTEUR_FENETRE - this->positionY - (this->hauteurTexte/2));
        glTexCoord2i(1, 1); glVertex2i( this->positionX + (this->largeurTexte/2), HAUTEUR_FENETRE - this->positionY - (this->hauteurTexte/2));
        glTexCoord2i(1, 0); glVertex2i( this->positionX + (this->largeurTexte/2), HAUTEUR_FENETRE - this->positionY + (this->hauteurTexte/2));
    glEnd();
}



