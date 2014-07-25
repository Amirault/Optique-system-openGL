#ifndef TRAIN_H
#define TRAIN_H

#include "Laser.h"
#include "Porte.h"
#include "Rampe.h"
#include "Point.h"

class Train
{
    public:
        Train();                    //constructeur
        virtual ~Train();           //destructeur
        Train(const Train& other);  //copy

        //Getter / Setter
        float Getlongeur() { return longueur; }
        //void Setlongeur(float val) { longueur = val; }
        float Getlargeur() { return largeur; }
        //void Setlargeur(float val) { largeur = val; }
        float Gethauteur() { return hauteur; }
        //void Sethauteur(float val) { hauteur = val; }
        float Getvitesse() { return vitesse; }
        void Setvitesse(float val) { vitesse = val; }

        //Methodes
        void Deplacer(double vitesseDeplacement);
        void Arreter();
        void OuverturePortes();
        void FermeturesPortes();
        void DeploiementRampes();
        void RenterRampes();
        void DessinerTrain();
        Point *coordTrain, *coordArriverTrain;
        Point *coordLaser;
        Point *coordRampe;

        Laser *laserPorte;
        Porte *porteDroite, *porteGauche;
        Rampe *rampePorte;

    protected:

    private:
        const float longueur = 1200/100;
        const float largeur = 300/100;
        const float hauteur = 250/100;
        float vitesseDepart;
        float vitesse;

};

#endif // TRAIN_H
