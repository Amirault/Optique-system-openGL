#include "init.h"
#include "configuration.h"

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

void initSDL(void)
{
    // Démarrage de la SDL avec le module vidéo
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    //SDL_FULLSCREEN
    // Création de la fenetre initialisée pour fonctionner avec OpenGL
    SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_OPENGL);

    // Titre de l'application
    SDL_WM_SetCaption(TITRE_APPLICATION, NULL);
}

void initOpenGL(void)
{
    //glEnable(GL_CULL_FACE); // Activer le masquage des faces cachées
    glEnable(GL_DEPTH_TEST);
    glCullFace(GL_BACK); // Face cachées = faces arrières
    glFrontFace(GL_CCW); // Face avant = sens trigo

    // Couleur rgba de vidage de l'écran
    glClearColor(0, 0, 0, 0);

    // Définition de la fenetre
    glViewport(0, 0, LARGEUR_FENETRE, HAUTEUR_FENETRE);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Définition de la zone visible
    gluPerspective(ANGLE_VISION, (GLdouble) LARGEUR_FENETRE / (GLdouble)HAUTEUR_FENETRE, PRET, LOIN);
}

