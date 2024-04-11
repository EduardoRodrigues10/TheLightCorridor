#include "../include/Ballon.h"

const int sphereResolution = 20;

float ballX = 0.0f;
float ballY = 0.0f;
float ballZ = -1.5f;
float ballVX = 0.01f;
float ballVY = 0.01f;
float ballVZ = -0.07f;
float SavedBallVZ = -0.07f;
float ballRadius = 0.1f;

void drawSphere(float radius, int stacks, int slices)
{
    for (int stack = 0; stack < stacks; ++stack)
    {
        float stackAngle1 = M_PI * (-0.5f + (float)stack / (float)stacks);
        float stackAngle2 = M_PI * (-0.5f + (float)(stack + 1) / (float)stacks);

        float y1 = radius * sinf(stackAngle1);
        float y2 = radius * sinf(stackAngle2);

        float stackRadius1 = radius * cosf(stackAngle1);
        float stackRadius2 = radius * cosf(stackAngle2);

        glBegin(GL_TRIANGLE_STRIP);
        for (int slice = 0; slice <= slices; ++slice)
        {
            float sliceAngle = 2 * M_PI * (float)slice / (float)slices;

            float x = cosf(sliceAngle);
            float z = sinf(sliceAngle);

            glNormal3f(x, y1, z);
            glVertex3f(x * stackRadius1, y1, z * stackRadius1);

            glNormal3f(x, y2, z);
            glVertex3f(x * stackRadius2, y2, z * stackRadius2);
        }
        glEnd();
    }
}

void drawBall()
{
    glColor3f(0.0f, 0.39f, 0.0f);
    glPushMatrix();
    glTranslatef(ballX, ballY, ballZ);
    drawSphere(ballRadius, sphereResolution, sphereResolution);
    glPopMatrix();
}

int checkObstacleCollision(float x, float y, float z, float width, float height, float depth)
{
    float minX = x - width / 2.0f;
    float maxX = x + width / 2.0f;
    float minY = y - height / 2.0f;
    float maxY = y + height / 2.0f;
    float minZ = z - depth / 2.0f;
    float maxZ = z + depth / 2.0f;

    if (ballX + ballRadius > minX && ballX - ballRadius < maxX &&
        ballY + ballRadius > minY && ballY - ballRadius < maxY &&
        ballZ + ballRadius > minZ && ballZ - ballRadius < maxZ)
    {
        return 1;
    }
    return 0;
}

Vector2D isBallCollidingWithFixedObstacle()
{
    Obstacle fixedObstacle = obstacles[0];
    float halfObstacleWidth = 2.5f;
    float halfObstacleHeight = 1.5f;

    Vector2D collisionPoint = {0.0f, 0.0f};

    if ((ballX + ballRadius > fixedObstacle.x - halfObstacleWidth) &&
        (ballX - ballRadius < fixedObstacle.x + halfObstacleWidth) &&
        (ballY + ballRadius > fixedObstacle.y - halfObstacleHeight) &&
        (ballY - ballRadius < fixedObstacle.y + halfObstacleHeight) &&
        (ballZ + ballRadius > fixedObstacle.z - 0.05f) &&
        (ballZ - ballRadius < fixedObstacle.z + 0.05f))
    {

        collisionPoint.x = ballX;
        collisionPoint.y = ballY;
    }

    return collisionPoint;
}

int checkRacketCollision()
{
    float minX = racketX - racketWidth / 2.0f;
    float maxX = racketX + racketWidth / 2.0f;
    float minY = racketY - racketHeight / 2.0f;
    float maxY = racketY + racketHeight / 2.0f;

    if (ballX + ballRadius > minX && ballX - ballRadius < maxX &&
        ballY + ballRadius > minY && ballY - ballRadius < maxY &&
        ballZ + ballRadius > racketZ - 0.1f && ballZ - ballRadius < racketZ + 0.1f)
    {
        return 1;
    }
    return 0;
}

void resetBall()
{
    ballX = racketX;
    ballY = racketY;
    ballZ = -1.5f;
    ballVX = 0.01f;
    ballVY = 0.01f;
    ballVZ = SavedBallVZ;
    ballAttached = 1;
}
