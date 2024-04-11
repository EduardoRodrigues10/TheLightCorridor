#include "../include/Raquette.h"
#include "../include/Obstacle.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

float racketX = 0.0f;
float racketY = -0.9f;
float racketZ = -0.8f;
float racketWidth = 0.4f;
float racketHeight = 0.4f;
double racketSizeBonusStartTime = 0.0;

void drawRaquette()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(racketX, racketY, racketZ);
    glScalef(racketWidth, racketHeight, 1.0f);

    glBegin(GL_LINE_STRIP);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glEnd();

    glPopMatrix();
}

int checkRacketObstacleCollision(float obstacleX, float obstacleY, float obstacleZ, float obstacleWidth, float obstacleHeight, float obstacleThickness)
{
    float racketLeft = racketX - racketWidth / 2.0f;
    float racketRight = racketX + racketWidth / 2.0f;
    float racketTop = racketY + racketHeight / 2.0f;
    float racketBottom = racketY - racketHeight / 2.0f;
    float racketThickness = 1.0f;

    float obstacleLeft = obstacleX - obstacleWidth / 2.0f;
    float obstacleRight = obstacleX + obstacleWidth / 2.0f;
    float obstacleTop = obstacleY + obstacleHeight / 2.0f;
    float obstacleBottom = obstacleY - obstacleHeight / 2.0f;

    int xAxisCollision = (racketLeft < obstacleRight && racketRight > obstacleLeft) ? 1 : 0;
    int yAxisCollision = (racketTop > obstacleBottom && racketBottom < obstacleTop) ? 1 : 0;
    int zAxisCollision = (racketZ < obstacleZ + obstacleThickness && racketZ + racketThickness > obstacleZ) ? 1 : 0;

    int notBehindObstacle = (racketZ > obstacleZ) ? 1 : 0;

    if (xAxisCollision && yAxisCollision && zAxisCollision && notBehindObstacle)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
