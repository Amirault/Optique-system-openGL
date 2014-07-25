#ifndef QUAI_H
#define QUAI_H

#include "Point.h"

class Quai
{
    public:
        Quai();                     //constructeur
        virtual ~Quai();            //destructeur
        Quai(const Quai& other);    //copy

        //Getter / Setter
        float Gethauteur() { return hauteur; }
        void Sethauteur(float val) { hauteur = val; }
        float Getlargeur() { return largeur; }
        //void Setlargeur(float val) { largeur = val; }
        float Getlongeur() { return longueur; }
        //void Setlongeur(float val) { longueur = val; }
        float Getinclinaison() { return inclinaison; }
        void Setinclinaison(float val) { inclinaison = val; }
        unsigned int Getcouleur() { return couleur; }
        void Setcouleur(unsigned int val) { couleur = val; }
        unsigned int Getmateriaux() { return materiaux; }
        void Setmateriaux(unsigned int val) { materiaux = val; }

        //Methodes
        void ChangerCouleur(unsigned int valCouleur);
        void ChangerMateriaux(unsigned int valMateriaux);
        void ChangerInclinaison(float valInclinaison);
        void ChangerHauteur(float valHauteur);
        void DessinerQuai();
        const float valAugmente = (float) 10.00/100.00, valDiminue = (float) 10.00/100.00;
        Point *coordQuai;
        float hauteur;

    protected:

    private:

        const float largeur = (float)300/100;      //en cm
        const float longueur = (float)2000/100;   //20000/100;
        float inclinaison;
        unsigned int couleur;
        unsigned int materiaux;
};

#endif // QUAI_H
