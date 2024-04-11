#ifndef __RAQUETTE__
#define __RAQUETTE__

/* Dessine la raquette du joueur */
void drawRaquette();

/* Detecte une collison entre la raquette et un obstacle de la scène */
int checkRacketObstacleCollision(float obstacleX, float obstacleY, float obstacleZ, float obstacleWidth, float obstacleHeight, float obstacleThickness);

#endif