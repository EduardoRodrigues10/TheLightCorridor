#include "../include/Ballon.h"
#include "../include/Couloir.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

float lineSpacing = 5.0f / 10.0f;
float lineOffset = 0.0f;

void drawCorridor()
{
    glColor3f(0.0f, 0.0f, 0.39f);

    // Mur de gauche
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, -1.0f, -5.0f);
    glVertex3f(-1.0f, 1.0f, -5.0f);
    glVertex3f(-1.0f, 1.0f, 2.5f);
    glVertex3f(-1.0f, -1.0f, 2.5f);
    glEnd();

    // Mur de droite
    glBegin(GL_QUADS);
    glVertex3f(1.0f, -1.0f, -5.0f);
    glVertex3f(1.0f, 1.0f, -5.0f);
    glVertex3f(1.0f, 1.0f, 2.5f);
    glVertex3f(1.0f, -1.0f, 2.5f);
    glEnd();

    // Plancher
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, -1.0f, -5.0f);
    glVertex3f(1.0f, -1.0f, -5.0f);
    glVertex3f(1.0f, -1.0f, 2.5f);
    glVertex3f(-1.0f, -1.0f, 2.5f);
    glEnd();

    // Plafond
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, 1.0f, -5.0f);
    glVertex3f(1.0f, 1.0f, -5.0f);
    glVertex3f(1.0f, 1.0f, 2.5f);
    glVertex3f(-1.0f, 1.0f, 2.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    int numLines = 10;

    for (int i = 0; i <= numLines; ++i)
    {
        float z = -5.0f + (i * lineSpacing) - lineOffset;

        glBegin(GL_LINE_STRIP);
        glVertex3f(-1.0f, -1.0f, z);
        glVertex3f(1.0f, -1.0f, z);
        glVertex3f(1.0f, 1.0f, z);
        glVertex3f(-1.0f, 1.0f, z);
        glVertex3f(-1.0f, -1.0f, z);
        glEnd();
    }
}

int checkCorridorCollision()
{
    if (ballX - ballRadius < -1.0f || ballX + ballRadius > 1.0f)
    {
        return 1;
    }
    if (ballY - ballRadius < -1.0f || ballY + ballRadius > 1.0f)
    {
        return 1;
    }
    return 0;
}