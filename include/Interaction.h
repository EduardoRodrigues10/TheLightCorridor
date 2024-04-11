#ifndef __INTERACTION__
#define __INTERACTION__

#include "../include/Jeu.h"

extern int obstaclesMoving;
extern int ballAttached;
extern int lives;

/* Arrete le joueur d'avancer, une collision qui ne permet pas d'avancer est détécté  */
void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos);

/* Detecte qu'une interaction avec la souris à été faîte */
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);

#endif