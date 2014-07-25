#include "Scene.h"
#include "Configuration.h"

Scene::Scene()
{
    //ctor
    timerDerniereVal = 0;
    monTrain = new Train();
    monQuai = new Quai();

}

Scene::~Scene()
{
    //dtor
}

void Scene::gererEvenements(void)
{
    SDL_Event evenement;

    while (SDL_PollEvent(&evenement))
    {
        switch(evenement.type)
        {
            case SDL_KEYDOWN:
                 switch (evenement.key.keysym.sym)
                {
                    case SDLK_a:
                        this->movXCam++;
                        break;
                    case SDLK_d:
                        this->movXCam--;
                        break;
                    case SDLK_q:
                        this->movYCam--;
                        break;
                    case SDLK_e:
                        this->movYCam++;
                    case SDLK_s:
                        this->movZCam++;
                        break;
                    case SDLK_w: // z en ascii
                        this->movZCam--;
                        break;
                    case SDLK_l: //Lancer le laser
                        //this->movZCam--;
                        break;
                    case SDLK_p: //Augmenter la hauteur du quai
                        if((monQuai->Gethauteur() + monQuai->valAugmente) <= 51.00/100.00)
                            monQuai->Sethauteur(monQuai->Gethauteur() + monQuai->valAugmente);
                        break;
                    case SDLK_n: //Diminuer la hauteur du quai
                        if((monQuai->Gethauteur() - monQuai->valAugmente) >= 00.00)
                            monQuai->Sethauteur(monQuai->Gethauteur() - monQuai->valDiminue);
                        //this->movZCam--;
                        break;
                    case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                        continuer = FALSE;
                        break;
                }
                break;
                  /* Enfoncement bouton souris */
            case SDL_MOUSEBUTTONDOWN:
                this->onclick = true;
                this->movYCam = evenement.motion.xrel;
                this->movXCam = evenement.motion.yrel;
                break;
            case SDL_MOUSEBUTTONUP:
                this->onclick = false;
                break;
            case SDL_MOUSEMOTION:
                if (onclick)
                {
                    this->rotateYCam += evenement.motion.xrel;
                    this->rotateXCam += evenement.motion.yrel;
                }
            break;
            case SDL_QUIT:
                this->continuer = FALSE;
                break;
            default:
                break;
        }

    }
}

void Scene::animer(void)
{
    if(timerCinematique() == true)
    {
        monTrain->Deplacer(0.1);
        //monQuai->Sethauteur(monQuai->Gethauteur() + 0.004);
        //monQuai->coordQuai->Setz(monQuai->coordQuai->Getz() + 0.002);
        //monQuai->ChangerHauteur(monQuai->Gethauteur() + 0.04);
    }
    else
        monTrain->Arreter();
}

void Scene::afficher(void)
{
    glFlush();
    SDL_GL_SwapBuffers();
}

void Scene::dessiner(void)
{
    /* Effacement de l'image avec la couleur de fond */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Selection / Initialisation de la matrice de transformation des objets */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotated(this->rotateXCam,1,0,0); //la scène est tournée autour de l'axe X
    glRotated(this->rotateYCam,0,1,0);  //la scène est tournée autour de l'axe Y
    /* Placement de la camera */
    gluLookAt(this->movXCam, this->movYCam, this->movZCam, 0, 0, 0, 0, 1, 0);

    glPushMatrix();
        glTranslatef(monTrain->coordTrain->Getx(), monTrain->coordTrain->Gety(), monTrain->coordTrain->Getz());
        monTrain->DessinerTrain();
        glTranslatef(monTrain->coordLaser->Getx(), monTrain->coordLaser->Gety(), monTrain->coordLaser->Getz());
        monTrain->laserPorte->DessinerLaser();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(monQuai->coordQuai->Getx(), monQuai->coordQuai->Gety(), monQuai->coordQuai->Getz());
        monQuai->DessinerQuai();
    glPopMatrix();
    glPushMatrix();
        monTrain->laserPorte->faisceauLaserQuai->Allumer(monQuai->hauteur,monTrain->coordLaser->Getx(),monTrain->coordLaser->Gety(),monTrain->coordLaser->Getz(),monTrain->laserPorte->largeur);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(monTrain->coordTrain->Getx(), monTrain->coordTrain->Gety(), monTrain->coordTrain->Getz());
        monTrain->rampePorte->Sortir(monQuai->hauteur,monTrain->coordRampe->Getx(),monTrain->coordRampe->Gety(),monTrain->coordRampe->Getz());
    glPopMatrix();
}

bool Scene::timerCinematique()
{
    int retour = SDL_GetTicks();

    if((timerDerniereVal + timerInterval) < retour)
    {
        timerDerniereVal = retour;
        return true;
    }
    return false;
}

void Scene::executer()
{
    this->initSDL();
    this->initOpenGL();
    this->continuer = TRUE;

    while(this->continuer)
    {
        gererEvenements();
        animer();
        dessiner();
        afficher();
    }
    SDL_Quit();
}
void Scene::initOpenGL(void)
{
//glEnable(GL_CULL_FACE); // Activer le masquage des faces cachées
    glEnable(GL_DEPTH_TEST);
    glCullFace(GL_BACK); // Face cachées = faces arrières
    glFrontFace(GL_CCW); // Face avant = sens trigo

    // Couleur rgba de vidage de l'écran
    glClearColor(0, 0, 0, 0);

    // Définition de la fenetre
    glViewport(0, 0, LARGEUR_FENETRE, HAUTEUR_FENETRE);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Définition de la zone visible
    gluPerspective(ANGLE_VISION, (GLdouble) LARGEUR_FENETRE / (GLdouble)HAUTEUR_FENETRE, PRET, LOIN);
}
void Scene::initSDL(void)
{
    // Démarrage de la SDL avec le module vidéo
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Création de la fenetre initialisée pour fonctionner avec OpenGL
    SDL_Surface * fenetre = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_OPENGL);

    // Titre de l'application
    SDL_WM_SetCaption(TITRE_APPLICATION, NULL);
}

