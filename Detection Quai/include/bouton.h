#ifndef BOUTON_H_INCLUDED
#define BOUTON_H_INCLUDED

#include "types.h"
#include <string>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "ConteneurTexture.h"

#define BOUTON_CLIQUE SDL_USEREVENT

class Bouton
{
    public:
        Bouton(std::string texte, sint32 x, sint32 y, sint32 code);
        ~Bouton();
        void dessiner(void);

    private:
        enum Etat {SURVOLE, ENFONCE, PAS_SURVOLE};
        Bouton::Etat etat;
        //SDL_Rect position;
        GLuint textureTexte;
        ConteneurTextures conteneurTextures;
        sint32 positionX, positionY;
        uint32 largeurTexte, hauteurTexte;
        sint32 code;

        GLuint creerTextureTexte(std::string texte);
        Bouton::Etat lectureEtatBouton(void);
        void dessinerFond(std::string image);
        void dessinerTexte(void);
};

#endif // BOUTON_H_INCLUDED

