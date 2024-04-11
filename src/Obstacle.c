#include "../include/Obstacle.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <time.h>

float obstacleZ = -3.0f;

Obstacle obstacles[MAX_OBSTACLES];
int obstacleCount = 0;
double lastObstacleGenerationTime = 0.0;
double obstacleGenerationInterval = 5.0;
int fixedObstacleHealth = 100;

void initObstacles()
{
    Obstacle fixedObstacle;
    fixedObstacle.x = 0.0f;
    fixedObstacle.y = 0.0f;
    fixedObstacle.z = -10.0f;
    fixedObstacle.width = 5.0f;
    fixedObstacle.height = 3.0f;

    obstacles[obstacleCount++] = fixedObstacle;
}

float randomFloat(float min, float max)
{
    float random = (float)rand() / (float)RAND_MAX;
    return min + random * (max - min);
}

void initRandom()
{
    srand(time(NULL));
}

void generateObstacle()
{
    if (obstacleCount < MAX_OBSTACLES)
    {
        Obstacle newObstacle;
        newObstacle.z = -5.0f;

        int wall = rand() % 2;
        if (wall == 0)
        {
            newObstacle.y = 0.0f;
            newObstacle.width = 2.0f * (1.0f / 3.0f);
            newObstacle.height = 2.0f;

            int wallL_R = rand() % 2;
            float obstacleX;
            if (wallL_R == 0)
            {
                obstacleX = -1.0f + newObstacle.width / 2.0f;
            }
            else
            {
                obstacleX = 1.0f - newObstacle.width / 2.0f;
            }
            newObstacle.x = obstacleX;
        }
        else
        {
            newObstacle.x = 0.0f;
            newObstacle.width = 2.0f;
            newObstacle.height = 2.0f * (1.0f / 3.0f);

            int wallP_S = rand() % 2;
            float obstacleY;
            if (wallP_S == 0)
            {
                obstacleY = -1.0f + newObstacle.height / 2.0f;
            }
            else
            {
                obstacleY = 1.0f - newObstacle.height / 2.0f;
            }
            newObstacle.y = obstacleY;
        }
        obstacles[obstacleCount++] = newObstacle;
    }
}

void drawObstacle(float x, float y, float z, float width, float height, float depth)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, depth);

    glBegin(GL_QUADS);

    // Face avant
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    // Face arrière
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // Face gauche
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    // Face droite
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);

    // Face supérieure
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // Face inférieure
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    glEnd();

    glPopMatrix();
}

void drawObstacles()
{
    for (int i = 0; i < obstacleCount; i++)
    {
        Obstacle obstacle = obstacles[i];
        if (i == 0)
        { // Si c'est l'obstacle fixe
            glColor3f(0.0f, 0.0f, 0.0f);
            drawObstacle(obstacle.x, obstacle.y, obstacle.z, 8.0f, 8.0f, 0.1f);
        }
        else
        {
            glColor3f(0.0f, 1.0f, 0.0f);
            drawObstacle(obstacle.x, obstacle.y, obstacle.z, obstacle.width, obstacle.height, 0.1f);
        }
    }
}
