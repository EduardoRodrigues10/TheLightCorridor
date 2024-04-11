#ifndef __COULOIR__
#define __COULOIR__

extern float ballX;
extern float ballY;
extern float ballRadius;

/* Dessine le couloir du jeu */
void drawCorridor();

/* Detecte que la balle cogne un des murs du couloir */
int checkCorridorCollision();

#endif