#include "init.h"
#include "Simulation.h"
#include <SDL/SDL.h>

int main( int argc, char* argv[] )
{
    // Execution de la scene
    Simulation* simu = new Simulation();
    simu->executer();

    return 0;
}
