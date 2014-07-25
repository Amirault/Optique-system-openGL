#ifndef CONTENEURTEXTURES_H_INCLUDED
#define CONTENEURTEXTURES_H_INCLUDED

#include "types.h"
#include <map>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>

class ConteneurTextures
{
    private:
        struct Texture
        {
            GLuint texture;
            uint32 compteur;
            sint32 largeur;
            sint32 hauteur;
        };

        typedef std::map<std::string, Texture> Textures;

        static Textures textures;
        void chargerTexture(const char* nomFichier, GLuint* texture, sint32* largeur, sint32* hauteur);

    public:
        Texture ajouter(std::string nomFichier);
        void supprimer(std::string nomFichier);
        Texture texture(std::string nomFichier);
};

#endif // CONTENEURTEXTURES_H_INCLUDED

