#include "Rampe.h"

Rampe::Rampe()
{
    //ctor
}

Rampe::~Rampe()
{
    //dtor
}

Rampe::Rampe(const Rampe& other)
{
    //copy ctor
}


void Rampe::Sortir(GLfloat hauteur_Quai,GLfloat x, GLfloat y,GLfloat z)
{
     //on trace la descente de la plaque
    //GLfloat Z_plaque = ((float)hauteur_Quai*(float)longueur/(float)((float)5/(float)100));  //on prend une sortie max de 150 et une hauteur de quai max de 5
    GLfloat Z_plaque = (float)3*(((float)50/(float)100) - ((float)hauteur_Quai)) ;
    GLfloat Y_plaque = ((float)tan((18.43*3.14)/180)*(float)-Z_plaque);
    glBegin(GL_QUADS);
    glColor3f(153, 153, 153);
    glVertex3f(x,y,z);                        //On fixe le point haut gauche
    glVertex3f(x,Y_plaque ,Z_plaque );      //On fixe le point bas gauche en fonction de yQuai
    glVertex3f(x+largeur,Y_plaque ,Z_plaque );      //On fixe le point bas droit en fonction de yQuai
    glVertex3f(x+largeur, y, z);      //On fixe le point haut droit
    glEnd();
}

void Rampe::Rentrer()
{

}

void Rampe::Incliner(float valInclinaison)
{

}
