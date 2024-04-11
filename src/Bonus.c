#include "../include/Bonus.h"

float bonusSpeed = 0.01f;

Bonus bonuses[MAX_BONUSES];
int bonusCount = 0;

void drawBonus(Bonus bonus)
{
    glPushMatrix();
    glTranslatef(bonus.x, bonus.y, bonus.z);

    switch (bonus.type)
    {
    case BONUS_ADD_LIFE:
        glColor3f(1.0f, 0.0f, 0.0f);
        break;
    case BONUS_STICKY:
        glColor3f(1.0f, 1.0f, 1.0f);
        break;
    default:
        glColor3f(0.2f, 1.0f, 1.0f);
        break;
    }

    glutSolidCube(0.1f);
    glPopMatrix();
}

void drawBonuses()
{
    for (int i = 0; i < bonusCount; i++)
    {
        if (bonuses[i].isActive)
        {
            drawBonus(bonuses[i]);
        }
    }
}

int checkRacketBonusCollision(Bonus bonus)
{
    float minX = racketX - racketWidth / 2.0f;
    float maxX = racketX + racketWidth / 2.0f;
    float minY = racketY - racketHeight / 2.0f;
    float maxY = racketY + racketHeight / 2.0f;

    if (!bonus.isActive)
    {
        return 0;
    }

    float bonusMinX = bonus.x - 0.1f / 2.0f;
    float bonusMaxX = bonus.x + 0.1f / 2.0f;
    float bonusMinY = bonus.y - 0.1f / 2.0f;
    float bonusMaxY = bonus.y + 0.1f / 2.0f;

    int collisionX = (minX <= bonusMaxX && maxX >= bonusMinX);
    int collisionY = (minY <= bonusMaxY && maxY >= bonusMinY);
    int collisionZ = (fabs(racketZ - bonus.z) <= 0.1f);

    return collisionX && collisionY && collisionZ;
}

void generateBonus()
{
    if (bonusCount < MAX_BONUSES)
    {
        float corridorWidth = 2.0f;
        float corridorHeight = 2.0f;

        Bonus newBonus;
        newBonus.x = ((float)rand() / (float)RAND_MAX) * corridorWidth - corridorWidth / 2.0f;
        newBonus.y = ((float)rand() / (float)RAND_MAX) * corridorHeight - corridorHeight / 2.0f;
        newBonus.z = -5.0f;
        newBonus.isActive = 1;

        newBonus.type = (BonusType)(rand() % 3);

        bonuses[bonusCount++] = newBonus;
    }
}

void updateBonuses()
{
    for (int i = 0; i < bonusCount; i++)
    {
        if (bonuses[i].isActive)
        {
            bonuses[i].z += bonusSpeed;
            if (bonuses[i].z > 1.0f)
            {
                bonuses[i].isActive = 0;
            }
        }
    }
}
