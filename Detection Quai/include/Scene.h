#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <SDL/SDL.h>
#include <math.h>
#include "Train.h"
#include "Quai.h"

class Scene
{
    private:
        void gererEvenements(void);
        void animer(void);
        void dessiner(void);
        void afficher(void);
        bool continuer = true;
        bool timerCinematique();
        int movXCam = 0;
        int movYCam = 10;
        int movZCam = 20;
        int rotateXCam = 0;
        int rotateYCam = 0;
        int tempo = 0;
        bool onclick = false;
        int timerDerniereVal;
        const int timerInterval = 10;
        void initSDL(void);
        void initOpenGL(void);

        Train *monTrain;
        Quai *monQuai;

    public:
        Scene();
        ~Scene();
        void executer();
};

#endif // SCENE_H_INCLUDED
