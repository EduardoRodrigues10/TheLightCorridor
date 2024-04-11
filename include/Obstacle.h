#ifndef __OBSTACLE__
#define __OBSTACLE__

#define MAX_OBSTACLES 100

typedef struct
{
    float x, y, z;
    float width, height;
} Obstacle;

/* Initialise l'obstacle fixe du jeu (Si le ballon vient à partir trop loin sans collision) */
void initObstacles();

/* Renvoie un float au hasard */
float randomFloat(float min, float max);

/* Initialise la graine */
void initRandom();

/* Cette fonction genere un obstacle si cela est possible */
void generateObstacle();

/* Dessine un obstacle */
void drawObstacle(float x, float y, float z, float width, float height, float depth);

/* Dessine tous les obstacles de la scéne */
void drawObstacles();

#endif