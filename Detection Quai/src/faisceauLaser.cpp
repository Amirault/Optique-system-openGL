#include "faisceauLaser.h"


faisceauLaser::faisceauLaser()
{
    //ctor
    intensite = 1;  //varie entre 0 et 1
}

faisceauLaser::~faisceauLaser()
{
    //dtor
}

faisceauLaser::faisceauLaser(const faisceauLaser& other)
{
    //copy ctor
}

void faisceauLaser::Allumer(GLfloat hauteur_Quai,GLfloat x, GLfloat y,GLfloat z,GLfloat largeur_laser)
{
    GLfloat xQ= (float)x-(float)(tan((29.5*3.14)/180)*(float)(y-((float)50/(float)100)-hauteur_Quai));     // on d�termine la valeur de x quai en tenant compte de la hauteur du quai
    GLfloat yQ=  -(((float)50/(float)100)-hauteur_Quai);     // on d�termine la valeur de y en tenant compte de la hauteur du quai
    GLfloat zQ= (float)largeur_laser;
    GLfloat xt= (float)xQ - (float)(x - xQ);          //on d�termine la potition x train du retour laser
    GLfloat yt= (float)y;    //on d�termine la potition y train du retour laser
    GLfloat zt= (float)largeur_laser;    //on d�termine la potition z train du retour laser

    //On trace le laser 1
    glBegin(GL_LINES);
    glVertex3f(x,y,(float)largeur_laser);
    glVertex3f(xQ,yQ,zQ);
    glEnd();


    //on trace le retour du laser sur le train
    glBegin(GL_LINES);
    glVertex3f(xQ,yQ,zQ);
    glVertex3f(xt,yt,zt);
    fprintf(stdout,"%f",xt);
    glEnd();
}

void faisceauLaser::Eteindre()
{

}
