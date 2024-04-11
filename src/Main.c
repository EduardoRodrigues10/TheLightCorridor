#include "../include/Menu.h"

extern int showMenu;

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

/* Emplacement de la caméra */
void setupCamera(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, (float)width / (float)height, 0.1f, 10.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    if (!glfwInit())
    {
        fprintf(stderr, "Erreur lors de l'initialisation de GLFW\n");
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "The Light Corridor", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Erreur lors de la création de la fenêtre GLFW\n");
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    glfwMakeContextCurrent(window);
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de GLEW: %s\n", glewGetErrorString(err));
        glfwTerminate();
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    initRandom();
    initObstacles();

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        setupCamera(width, height);

        if (showMenu)
        {
            drawMenu();
        } else if (isGameOver){
            drawGameOver();
        } else if (isGameComplete){
            drawCongratulations();
        }
        else
        {
            // Mettre à jour la logique du jeu
            updateGameLogic();

            // Dessine les objets du jeu
            drawCorridor();
            drawBall();
            drawObstacles();
            drawBonuses();
            drawRaquette();
            drawLives();
            drawScore(10,10);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}