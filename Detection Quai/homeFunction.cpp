#include "homeFunction.h"


#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SDL/SDL.h>

void cube(double longueur, double largeur, double hauteur)
{
//face avant position z comune
    glBegin(GL_QUADS);

    glColor3ub(255,255,0); //face avant rouge
    glVertex3d(0, 0, 0);                    //1
    glVertex3d(longueur, 0, 0);             //2
    glVertex3d(longueur, hauteur, 0);       //3
    glVertex3d(0, hauteur, 0);              //4

    glColor3ub(0,255,0); //face arriere verte
    glVertex3d(0, 0, -largeur);             //1'
    glVertex3d(longueur, 0, -largeur);      //2'
    glVertex3d(longueur, hauteur, -largeur);//3'
    glVertex3d(0, hauteur, -largeur);       //4'

    glColor3ub(0,0,255); //face coté gauche bleue
    glVertex3d(0, 0, 0);
    glVertex3d(0, 0, -largeur);
    glVertex3d(0, hauteur, -largeur);
    glVertex3d(0, hauteur, 0);

    glColor3ub(255,255,0); //face coté droit jaune
    glVertex3d(longueur, hauteur, 0);       //3
    glVertex3d(longueur, 0, 0);             //2
    glVertex3d(longueur, 0, -largeur);      //2'
    glVertex3d(longueur, hauteur, -largeur);//3'

    glColor3ub(0,255,255); //face haut cyan
    glVertex3d(0, hauteur, 0);              //4
    glVertex3d(longueur, hauteur, 0);       //3
    glVertex3d(longueur, hauteur, -largeur);//3'
    glVertex3d(0, hauteur, -largeur);       //4'

    glColor3ub(255,0,255); //face bas magenta
    glVertex3d(0, 0, 0);                    //1
    glVertex3d(longueur, 0, 0);             //2
    glVertex3d(longueur, 0, -largeur);      //2'
    glVertex3d(0, 0, -largeur);             //1'

    glEnd();
}
