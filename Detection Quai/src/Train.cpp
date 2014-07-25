#include "Train.h"

#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SDL/SDL.h>

#include "homeFunction.h"

Train::Train()
{
    //ctor
    vitesseDepart = 20; // km/h
    coordTrain = new Point(-15.0, 0.0, 0.0);
    coordArriverTrain = new Point(0.0, 0.0, 0.0);
    laserPorte = new Laser();
    coordLaser = new Point((longueur - (200/100)), (hauteur - (20/100)), laserPorte->largeur);
    rampePorte  = new Rampe();
    coordRampe = new Point((float)longueur - ((float)430/(float)100),(float)hauteur - ((float)200/(float)100), 0);


}

Train::~Train()
{
    //dtor
}

Train::Train(const Train& other)
{
    //copy ctor
}


void Train::Deplacer(double vitesseDeplacement)
{
    if((coordArriverTrain->Getx() - coordTrain->Getx()) > 0)
    {
        coordTrain->Setx(coordTrain->Getx() + vitesseDeplacement);
        //coordLaser->Setx(coordLaser->Getx() + vitesseDeplacement);
    }
    //else
      //  Arreter();
}

void Train::Arreter()
{

}

void Train::OuverturePortes()
{

}

void Train::FermeturesPortes()
{

}

void Train::DeploiementRampes()
{

}

void Train::RenterRampes()
{

}

void Train::DessinerTrain()
{
    cube(this->longueur, this->largeur, this->hauteur);
    /*
    //face avant position z comune
    glBegin(GL_QUADS);

    glColor3ub(255,0,0); //face rouge
    glVertex3d(this->longueur,this->hauteur,this->largeur);
    glVertex3d(this->longueur,this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,this->hauteur,this->largeur);

    glColor3ub(0,255,0); //face verte
    glVertex3d(this->longueur,-this->hauteur,this->largeur);
    glVertex3d(this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(this->longueur,this->hauteur,-this->largeur);
    glVertex3d(this->longueur,this->hauteur,this->largeur);

    glColor3ub(0,0,255); //face bleue
    glVertex3d(-this->longueur,-this->hauteur,this->largeur);
    glVertex3d(-this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(this->longueur,-this->hauteur,this->largeur);

    glColor3ub(255,255,0); //face jaune
    glVertex3d(-this->longueur,this->hauteur,this->largeur);
    glVertex3d(-this->longueur,this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,-this->hauteur,this->largeur);

    glColor3ub(0,255,255); //face cyan
    glVertex3d(this->longueur,this->hauteur,-this->largeur);
    glVertex3d(this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,this->hauteur,-this->largeur);

    glColor3ub(255,0,255); //face magenta
    glVertex3d(this->longueur,-this->hauteur,this->largeur);
    glVertex3d(this->longueur,this->hauteur,this->largeur);
    glVertex3d(-this->longueur,this->hauteur,this->largeur);
    glVertex3d(-this->longueur,-this->hauteur,this->largeur);

    glEnd();
    */
}
