#include "../include/Interaction.h"

void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos)
{
    float newX = (xpos / 800) * 2.0f - 1.0f;
    float newY = 1.0f - (ypos / 600) * 2.0f;

    float oldRacketX = racketX;
    float oldRacketY = racketY;

    racketX = newX;
    racketY = newY;

    if (racketX - racketWidth / 2.0f < -1.0f)
        racketX = -1.0f + racketWidth / 2.0f;
    if (racketX + racketWidth / 2.0f > 1.0f)
        racketX = 1.0f - racketWidth / 2.0f;
    if (racketY - racketHeight / 2.0f < -1.0f)
        racketY = -1.0f + racketHeight / 2.0f;
    if (racketY + racketHeight / 2.0f > 1.0f)
        racketY = 1.0f - racketHeight / 2.0f;

    for (int i = 0; i < obstacleCount; i++)
    {
        if (checkRacketObstacleCollision(obstacles[i].x, obstacles[i].y, obstacles[i].z, obstacles[i].width, obstacles[i].height, 0.1f))
        {
            racketX = oldRacketX;
            racketY = oldRacketY;
            obstaclesMoving = 0;
            break;
        }
        else
        {
            obstaclesMoving = 1;
        }
    }
}

void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        // Le bouton droit de la souris a été appuyé
        if (ballAttached == 1)
        {
            ballAttached = 0;
            ballVX = 0.01f;
            ballVY = 0.01f;
            ballVZ = -0.05f;
        }
    }
}
