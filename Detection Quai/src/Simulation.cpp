#include "Simulation.h"
#include <SDL/SDL.h>
#include "configuration.h"
#include "scene.h"
#include "menu.h"
#include <SDL/SDL_ttf.h>

Simulation::Simulation()
{

}

Simulation::~Simulation()
{

}

void Simulation::executer(void)
{
    // Creation de la fenetre avec SDL
    this->initSDL();

    // Generation des codes de bouton
    enum {BOUTON_JOUER, BOUTON_QUITTER};

    // Création du menu
    Menu menu("fond_menu.bmp");
    menu.ajouterBouton("Simuler", LARGEUR_FENETRE/4 + LARGEUR_FENETRE/2, 200, BOUTON_JOUER);
    menu.ajouterBouton("Quitter", LARGEUR_FENETRE/4 + LARGEUR_FENETRE/2, 250, BOUTON_QUITTER);

    // Boucle d'exécution du jeu
    bool8 continuer = TRUE;
    while(continuer)
    {
        // Affichage du menu
        menu.dessiner();

        // Gestion des évènements
        SDL_Event evenement;
        SDL_WaitEvent(&evenement);
        switch(evenement.type)
        {
            // Quitter
            case SDL_QUIT:
                continuer = FALSE;
                break;
            // Un bouton a ete clique
            case BOUTON_CLIQUE:
                switch(evenement.user.code)
                {
                    case BOUTON_JOUER:
                        {
                            // Arret de SDL_ttf
                            TTF_Quit();
                            // Arret de la SDL
                            SDL_Quit();
                            // Execution de la scène
                            Scene* scene = new Scene();
                            scene->executer();
                        }
                        break;
                    case BOUTON_QUITTER:
                        continuer = FALSE;
                        break;
                }
                break;
        }
    }


}

void Simulation::initSDL(void)
{
    // Démarrage de la SDL avec le module vidéo
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    TTF_Init();


    // Création de la fenetre initialisée pour fonctionner avec OpenGL
    SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_OPENGL| SDL_FULLSCREEN);

    // Titre de l'application
    SDL_WM_SetCaption(TITRE_APPLICATION, NULL);
}

