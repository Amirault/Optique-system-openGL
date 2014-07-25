#ifndef FAISCEAULASER_H
#define FAISCEAULASER_H
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <SDL/SDL.h>
#include <cmath>

class faisceauLaser
{
    public:
        faisceauLaser();                                //constructeur
        virtual ~faisceauLaser();                       //destructeur
        faisceauLaser(const faisceauLaser& other);      //copy

        //Getter / Setter
        unsigned int Getcouleur() { return couleur; }
        void Setcouleur(unsigned int val) { couleur = val; }
        unsigned int Getforme() { return forme; }
        void Setforme(unsigned int val) { forme = val; }
        float Getintensite() { return intensite; }
        void Setintensite(float val) { intensite = val; }
        float Getdirection() { return direction; }
        //void Setdirection(float val) { direction = val; }

        //Methodes
        void Allumer(GLfloat hauteur_Quai,GLfloat x,GLfloat y,GLfloat z,GLfloat largeur_laser);
        void Eteindre();

    protected:

    private:
        unsigned int couleur;       //CONST RED
        unsigned int forme;         //cylindre
        float intensite;            //varie entre 0 et 1
        const float direction = 20; //en degres
};

#endif // FAISCEAULASER_H

