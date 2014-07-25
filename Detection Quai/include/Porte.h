#ifndef PORTE_H
#define PORTE_H


class Porte
{
    public:
        Porte();                    //constructeur
        virtual ~Porte();           //destructeur
        Porte(const Porte& other);  //copy

        //Getter / Setter
        float Gethauteur() { return hauteur; }
        //void Sethauteur(float val) { hauteur = val; }
        float Getlargeur() { return largeur; }
        //void Setlargeur(float val) { largeur = val; }
        float Getepaisseur() { return epaisseur; }
        //void Setepaisseur(float val) { epaisseur = val; }

        //Methodes
        void Ouvrir();
        void Fermet();

    protected:

    private:
        const float hauteur = 200;  //cm
        const float largeur = 100;
        const float epaisseur = 5;
};

#endif // PORTE_H
