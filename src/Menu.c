#include "../include/Menu.h"

int showMenu = 1;
int isGameOver = 0;
int isGameComplete = 0;
double levelUpDisplayTime = 0;
int currentLevel = 1;
int score = 0;

void drawText(char msg[], float red, float green, float blue, int x, int y, void *font)
{

    glColor3f(red, green, blue);
    glWindowPos2i(x, y);
    for (int i = 0; i < strlen(msg); i++)
    {
        glutBitmapCharacter(font, msg[i]);
    }
}

void drawMenu()
{
    glPushMatrix();

    drawText("The Light Corridor", 1.0f, 0.0f, 0.0f, 280, 450, GLUT_BITMAP_TIMES_ROMAN_24);
    drawText("By Christian and Edouardo", 0.39f, 0.84f, 0.34f, 270, 425, GLUT_BITMAP_9_BY_15);
    drawText("Jouer (Espace pour jouer)", 0.2f, 1.0f, 1.0f, 280, 300, GLUT_BITMAP_HELVETICA_18);
    drawText("Quitter (Echap pour quitter)", 0.2f, 1.0f, 1.0f, 280, 200, GLUT_BITMAP_HELVETICA_18);

    glPopMatrix();
}

void drawScore(int x, int y)
{
    char scoreText[32];
    sprintf(scoreText, "Score: %d", score);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 800, 0.0, 600);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2i(x, y);
    int len = strlen(scoreText);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreText[i]);
    }

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void drawGameOver()
{
    glPushMatrix();

    drawText("Game Over", 1.0f, 0.0f, 0.0f, 340, 400, GLUT_BITMAP_TIMES_ROMAN_24);
    drawScore(360, 350);
    drawText("Touche Echap pour quitter", 0.39f, 0.84f, 0.34f, 265, 300, GLUT_BITMAP_TIMES_ROMAN_24);

    glPopMatrix();
}

void drawBoss()
{
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);

    drawText("Toi VS le Boss, 100 pv t'a balle fait -10 pv", 1.0f, 1.0f, 1.0f, 210, 450, GLUT_BITMAP_HELVETICA_18);

    glPopMatrix();
}

void drawLevelUp()
{
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);

    char levelUpText[50];
    sprintf(levelUpText, "Niveau %d", currentLevel);
    glWindowPos2i(360, 500);
    for (int i = 0; i < strlen(levelUpText); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, levelUpText[i]);
    }

    glPopMatrix();
}

void drawCongratulations()
{
    glPushMatrix();

    drawText("Felicitations, tu a trouve la sortie du", 0.39f, 0.84f, 0.34f, 225, 400, GLUT_BITMAP_TIMES_ROMAN_24);
    drawText("couloir et ainsi libérer la balle", 0.39f, 0.84f, 0.34f, 265, 350, GLUT_BITMAP_TIMES_ROMAN_24);
    drawScore(360, 300);
    drawText("Touche Echap pour quitter", 0.2f, 1.0f, 1.0f, 265, 250, GLUT_BITMAP_TIMES_ROMAN_24);

    glPopMatrix();
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (showMenu)
    {
        if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        {
            showMenu = 0; // Commencer le jeu
        }
        else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, 1); // Fermer la fenêtre et quitter le programme
        }
    }
    else if (isGameOver || isGameComplete)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, 1); // Fermer la fenêtre et quitter le programme
        }
    }
}
