#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>
#include "ConteneurTexture.h"
#include "bouton.h"
#include <set>

class Menu
{
    public:
        Menu(std::string imageFond);
        ~Menu();
        void dessiner(void);
        void ajouterBouton(std::string texte, sint32 x, sint32 y, sint32 code);

    private:
        std::string imageFond;
        ConteneurTextures conteneurTextures;
        typedef std::set<Bouton*> Boutons;
        Boutons listeBoutons;

        void dessinerFond(void);
        void dessinerBoutons(void);
};

#endif // MENU_H_INCLUDED

