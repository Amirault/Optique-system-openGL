#ifndef RAMPE_H
#define RAMPE_H
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SDL/SDL.h>
#include <cmath>

class Rampe
{
    public:
        Rampe();                    //constructeur
        virtual ~Rampe();           //destructeur
        Rampe(const Rampe& other);  //copy

        //Getter / Setter
        float Getlongeur() { return longueur; }
        //void Setlongeur(float val) { longueur = val; }
        float Getlargeur() { return largeur; }
        //void Setlargeur(float val) { largeur = val; }
        float Getepaisseur() { return epaisseur; }
        //void Setepaisseur(float val) { epaisseur = val; }
        unsigned int Getmateriel() { return materiel; }
        void Setmateriel(unsigned int val) { materiel = val; }
        unsigned int Getcouleur() { return couleur; }
        void Setcouleur(unsigned int val) { couleur = val; }
        float Getinclinaison() { return inclinaison; }
        //void Setinclinaison(float val) { inclinaison = val; }

        //Methodes
        void Sortir (GLfloat hauteur_Quai,GLfloat x, GLfloat y,GLfloat z);
        void Rentrer();
        void Incliner(float valInclinaison);

    protected:

    private:
        const float longueur = (float)150/(float)100;
        const float largeur = (float)200/(float)100;      //cm
        const float epaisseur = (float)5/(float)100;
        unsigned int materiel;          //metal
        unsigned int couleur;           //gris
        const float inclinaison = (float)20/(float)100;   //degres
};

#endif // RAMPE_H
