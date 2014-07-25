#include "menu.h"
#include "ConteneurTexture.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include "configuration.h"

#include <SDL/SDL_ttf.h>

Menu::Menu(std::string imageFond)
{
    this->imageFond = imageFond;
    this->conteneurTextures.ajouter(this->imageFond);
}

Menu::~Menu()
{
    this->conteneurTextures.supprimer(this->imageFond);

    // Liberation des boutons
    for (Boutons::iterator element = this->listeBoutons.begin(); element != listeBoutons.end(); element++)
    {
        delete *element;
    }
}

void Menu::dessiner(void)
{
    // En 2D
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);

    // Definition de la fenetre
    gluOrtho2D(0.0, (GLdouble)LARGEUR_FENETRE, 0.0, (GLdouble)HAUTEUR_FENETRE);

    // Desactivation du test de prophondeur
    glDisable(GL_DEPTH_TEST);

    // Vidage de l'image
    glClear(GL_COLOR_BUFFER_BIT);

    // Dessin de fond du menu
    this->dessinerFond();

    // Dessin des boutons
    this->dessinerBoutons();

    // Affichage du dessin
    glFlush();
    SDL_GL_SwapBuffers();

}

void Menu::dessinerFond(void)
{
    // Selection de l'image de fond
    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture(this->imageFond).texture);

    // Application de l'image de fond
    glBegin(GL_QUADS);
        glTexCoord2d(0, 0); glVertex2f(0, HAUTEUR_FENETRE);
        glTexCoord2d(0, 1); glVertex2f(0, 0);
        glTexCoord2d(1, 1); glVertex2f(LARGEUR_FENETRE, 0);
        glTexCoord2d(1, 0); glVertex2f(LARGEUR_FENETRE, HAUTEUR_FENETRE);
    glEnd();
}

void Menu::dessinerBoutons(void)
{
    // Dessin des boutons
    for (Boutons::iterator element = this->listeBoutons.begin(); element != listeBoutons.end(); element++)
    {
        (*element)->dessiner();
    }
}

void Menu::ajouterBouton(std::string texte, sint32 x, sint32 y, sint32 code)
{
    this->listeBoutons.insert( new Bouton(texte, x, y, code) );
}

