#ifndef LASER_H
#define LASER_H
#include "faisceauLaser.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SDL/SDL.h>

class Laser
{
    public:
        Laser();                    //constructeur
        virtual ~Laser();           //destructeur
        Laser(const Laser& other);  //copy
        faisceauLaser* faisceauLaserQuai;

        void DessinerLaser();

        unsigned int couleur;           //ROUGE
        unsigned int forme;             //cylindre
        const float hauteur = (float) 10/100;    //cm
        const float largeur = (float) 30/100;
        const float longueur = (float) 10/100;  //

    protected:

    private:
};

#endif // LASER_H
