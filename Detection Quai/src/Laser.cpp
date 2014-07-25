#include "Laser.h"


Laser::Laser()
{
    faisceauLaserQuai = new faisceauLaser();//ctor
}

Laser::~Laser()
{
    //dtor
}

Laser::Laser(const Laser& other)
{
    //copy ctor
}

void Laser::DessinerLaser()
{
    //face avant position z comune
    glBegin(GL_QUADS);

    glColor3ub(255,0,0); //face rouge
    glVertex3d(this->longueur,this->hauteur,this->largeur);
    glVertex3d(this->longueur,this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,this->hauteur,this->largeur);

    glColor3ub(255,0,0); //face verte
    glVertex3d(this->longueur,-this->hauteur,this->largeur);
    glVertex3d(this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(this->longueur,this->hauteur,-this->largeur);
    glVertex3d(this->longueur,this->hauteur,this->largeur);

    glColor3ub(255,0,0); //face bleue
    glVertex3d(-this->longueur,-this->hauteur,this->largeur);
    glVertex3d(-this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(this->longueur,-this->hauteur,this->largeur);

    glColor3ub(255,0,0); //face jaune
    glVertex3d(-this->longueur,this->hauteur,this->largeur);
    glVertex3d(-this->longueur,this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,-this->hauteur,this->largeur);

    glColor3ub(255,0,0); //face cyan
    glVertex3d(this->longueur,this->hauteur,-this->largeur);
    glVertex3d(this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,-this->hauteur,-this->largeur);
    glVertex3d(-this->longueur,this->hauteur,-this->largeur);

    glColor3ub(255,0,0); //face magenta
    glVertex3d(this->longueur,-this->hauteur,this->largeur);
    glVertex3d(this->longueur,this->hauteur,this->largeur);
    glVertex3d(-this->longueur,this->hauteur,this->largeur);
    glVertex3d(-this->longueur,-this->hauteur,this->largeur);

    glEnd();
}
