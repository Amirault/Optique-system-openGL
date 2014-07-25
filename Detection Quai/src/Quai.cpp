#include "Quai.h"
#include "homeFunction.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SDL/SDL.h>

Quai::Quai()
{
    //ctor
    hauteur = (float) 50/100;
    inclinaison = 0;          //en degré
    couleur;           //gris
    materiaux;         //beton

    coordQuai = new Point(0.0, (float)-50/100, (float)300/100);
}

Quai::~Quai()
{
    //dtor
}

Quai::Quai(const Quai& other)
{
    //copy ctor
}


void Quai::ChangerCouleur(unsigned int valCouleur)
{

}

void Quai::ChangerMateriaux(unsigned int valMateriaux)
{

}

void Quai::ChangerInclinaison(float valInclinaison)
{

}

void Quai::ChangerHauteur(float valHauteur)
{

}

void Quai::DessinerQuai()
{
     cube(longueur,largeur,hauteur);
}
