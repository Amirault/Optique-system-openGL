#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <SDL/SDL.h>

class Simulation
{
    public:
        Simulation();
        ~Simulation();

        void executer(void);
        void initSDL(void);
};

#endif // JEU_H_INCLUDED

