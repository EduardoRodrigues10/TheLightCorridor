#ifndef __JEU__
#define __JEU__

#include "../include/Bonus.h"
#include "../include/Menu.h"

extern float ballX;
extern float ballZ;
extern float ballY;
extern float ballVY;
extern float ballVX;
extern float ballVZ;
extern float SavedBallVZ;

extern int currentLevel;
extern double levelUpDisplayTime;
extern int nextSeuilScore;
extern int score;

extern int isGameOver;
extern int isGameComplete;

extern float bonusTimer;
extern float bonusSpeed;
extern Bonus bonuses[MAX_BONUSES];
extern int bonusCount;

extern float obstacleZ;

extern Obstacle obstacles[MAX_OBSTACLES];
extern int obstacleCount;
extern double lastObstacleGenerationTime;
extern double obstacleGenerationInterval;
extern int fixedObstacleHealth;

extern float lineSpacing;
extern float lineOffset;

extern const int sphereResolution;

/* Boucle principale du jeu, ou tous les evenements sont gérer */
void updateGameLogic();

/* Dessine les vies restantes du joueur */
void drawLives();


#endif