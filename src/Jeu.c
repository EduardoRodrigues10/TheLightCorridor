#include "../include/Jeu.h"

int obstaclesMoving = 1;
int ballAttached = 1;
int lives = 5;
double timeBoss = -1;
int nextSeuilScore;

void updateGameLogic()
{
    nextSeuilScore = ((score / 50) + 1) * 50;

    if (currentLevel == 10)
    {
        timeBoss = glfwGetTime();
    }

    if (timeBoss >= 0)
    {
        drawBoss();
    }

    // Détecter les collisions avec le couloir
    if (checkCorridorCollision())
    {
        ballVX = -ballVX;
        ballVY = -ballVY;
    }

    // Détecter les collisions avec les obstacles
    for (int i = 1; i < obstacleCount; i++)
    {
        Obstacle obstacle = obstacles[i];
        if (checkObstacleCollision(obstacle.x, obstacle.y, obstacle.z, obstacle.width, obstacle.height, 0.1f))
        {
            ballVZ = -ballVZ;
            break;
        }
    }

    // Détecter les collisions avec les bonus
    for (int i = 0; i < bonusCount; i++)
    {
        if (checkRacketBonusCollision(bonuses[i]))
        {
            switch (bonuses[i].type)
            {
            case BONUS_ADD_LIFE:
                lives++;
                break;
            case BONUS_STICKY:
                ballVZ += ballVZ;
                resetBall();
                break;
            case BONUS_RACKET_SIZE:
                racketWidth = 0.6f;
                racketHeight = 0.6f;
                racketSizeBonusStartTime = glfwGetTime();
                break;
            }
            bonuses[i].isActive = 0;
            bonuses[i] = bonuses[--bonusCount];
            break;
        }
    }

    double currentTime = glfwGetTime();

    if (racketWidth >= 0.6f && racketHeight >= 0.6f && currentTime - racketSizeBonusStartTime >= 7.0)
    {
        racketWidth = 0.4f;
        racketHeight = 0.4f;
    }

    if (ballAttached == 0)
    {
        ballX += ballVX;
        ballY += ballVY;
        ballZ += ballVZ;
    }
    else
    {
        ballX = racketX;
        ballY = racketY;
    }

    if (ballZ > 1.0f)
    {
        lives--;

        if (lives > 0)
        {
            resetBall();
        }
        else
        {
            isGameOver = 1;
        }
    }

    obstacleZ += 0.03f;

    if (obstacleZ > 2.0f)
    {
        obstacleZ = -3.0f;
    }

    if (checkRacketCollision())
    {
        float angle = atan2f(ballVZ, ballVX);
        float normalAngle = atan2f(racketY - ballY, racketX - ballX);
        float reflectionFactor = 0.5f;
        float reflectionAngle = angle + reflectionFactor * (normalAngle - angle);

        float speed = sqrtf(ballVX * ballVX + ballVZ * ballVZ);
        ballVX = speed * cosf(reflectionAngle);
        ballVZ = speed * sinf(reflectionAngle);

        ballVY = -ballVY;
    }

    Vector2D collisionPoint = isBallCollidingWithFixedObstacle();

    if (collisionPoint.x != 0.0f || collisionPoint.y != 0.0f)
    {
        ballVX = -ballVX;
        ballVZ = -ballVZ;

        if (currentLevel >= 10)
        {
            fixedObstacleHealth -= 10;
            if (fixedObstacleHealth <= 0)
            {
                isGameComplete = 1;
            }
        }
        else
        {
            score += 10;
            if (score >= nextSeuilScore)
            {
                ballVZ *= 1.2f;
                SavedBallVZ = ballVZ;
                nextSeuilScore += 50;
                currentLevel++;
                levelUpDisplayTime = glfwGetTime();
            }
        }
    }

    if (currentTime - levelUpDisplayTime <= 3.0)
    {
        drawLevelUp();
    }

    if (currentLevel < 10)
    {
        if (currentTime - lastObstacleGenerationTime >= 3.0)
        {
            generateObstacle();
            lastObstacleGenerationTime = currentTime;
        }
    }
    else
    {
        obstaclesMoving = 0;
    }

    static double lastBonusGenerationTime = 0;
    if (currentLevel < 2 && currentTime - lastBonusGenerationTime >= 45.0)
    {
        generateBonus();
        lastBonusGenerationTime = currentTime;
    }

    if (obstaclesMoving)
    {
        for (int i = 0; i < obstacleCount; i++)
        {
            if (i > 0)
            {
                obstacles[i].z += 0.01f;
            }

            if (i > 0 && obstacles[i].z > 1.0f)
            {
                obstacles[i] = obstacles[--obstacleCount];
            }
        }

        updateBonuses();

        lineOffset -= 0.01f;
        if (lineOffset < lineSpacing)
        {
            lineOffset += lineSpacing;
        }
    }
}

void drawLives()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    float startX = -0.95f;
    float startY = 0.73f;
    float scaleFactor = 0.3f;

    for (int i = 0; i < lives; ++i)
    {
        glPushMatrix();
        glTranslatef(startX + i * (ballRadius * 3.0f * scaleFactor), startY, -0.8f);
        drawSphere(ballRadius * scaleFactor, sphereResolution, sphereResolution);
        glPopMatrix();
    }
}
