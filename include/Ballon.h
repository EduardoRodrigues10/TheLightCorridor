#ifndef __BALLON__
#define __BALLON__

#include "../include/Couloir.h"
#include "../include/Obstacle.h"
#include "../include/Raquette.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define M_PI 3.14159265359

typedef struct
{
    float x;
    float y;
} Vector2D;

extern Obstacle obstacles[MAX_OBSTACLES];
extern float racketX;
extern float racketY;
extern float racketZ;
extern float racketWidth;
extern float racketHeight;

extern int ballAttached;

/* Dessine une sphere */
void drawSphere(float radius, int stacks, int slices);

/* Dessine le ballon du jeu */
void drawBall();

/* Detecte si le ballon cogne un obstacle */
int checkObstacleCollision(float x, float y, float z, float width, float height, float depth);

/* Detecte si le ballon est aller trop loin sans cogner d'obstacle, dans ce cas la on detecte une fin a la trajectoire, pour qu'il revienne */
Vector2D isBallCollidingWithFixedObstacle();

/* Detecte si le ballon cogne contre la raquette du joueur */
int checkRacketCollision();

/* Reinitialise la position de la balle coller à la raquette du joueur */
void resetBall();

#endif