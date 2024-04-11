#include "../include/Raquette.h"
#include "../include/Ballon.h"
#include <math.h>

#define MAX_BONUSES 10

typedef enum
{
    BONUS_ADD_LIFE,
    BONUS_STICKY,
    BONUS_RACKET_SIZE,
} BonusType;

typedef struct
{
    float x, y, z;
    int isActive;
    BonusType type;
} Bonus;

extern float ballX;
extern float ballZ;
extern float ballY;
extern float racketX;
extern float racketY;
extern float racketZ;
extern float racketWidth;
extern float racketHeight;
extern double racketSizeBonusStartTime;

/* Dessine un bonus */
void drawBonus(Bonus bonus);

/* Dessine tous les bonus */
void drawBonuses();

/* Detecte si la raquette traverse un bonus */
int checkRacketBonusCollision(Bonus bonus);

/* Fonction qui sert a générer tous les bonus */
void generateBonus();

/* Activation des effets des bonus attrapés par le joueur */
void updateBonuses();