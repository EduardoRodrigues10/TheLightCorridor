#include "../include/Interaction.h"
#include <string.h>

void drawText(char message[], float red, float green, float blue, int x , int y, void *font);

/* Dessine le menu de début de jeu */
void drawMenu();

/* Dessine le score du joueur */
void drawScore();

/* Dessine la fin de jeu */
void drawGameOver();

/* Affichage avant la fin contre le boss */
void drawBoss();

/* Dessine le niveau du joueur */
void drawLevelUp();

/* Dessine l'interface de fin lorsque le joueur à terminé le jeu */
void drawCongratulations();

/* Detecte une interaction avec le clavier et son type, et plus particulierement pour le menu de debut de jeu */
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);