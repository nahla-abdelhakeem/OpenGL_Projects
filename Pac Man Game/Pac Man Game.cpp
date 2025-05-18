#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

float playerX = 0.0, playerY = 0.0;
float moveSpeed = 0.06;
char direction = 'r';
int score = 0;
bool gameOver = false;
bool win = false;

const int wallCount = 3;
float wallX[wallCount] = { -0.5, 0.0, 0.5 };
float wallY[wallCount] = { -0.5, 0.5, -0.5 };


const int dotCount = 5;
float dotX[dotCount] = { -0.8, -0.6, -0.4, 0.2, 0.6 };
float dotY[dotCount] = { -.2, 0.2, -0.2, 0.4, -0.8 };
bool dotEaten[dotCount] = { 0, 0, 0, 0, 0 };

bool isWall(float x, float y) {           //for collision
    for (int i = 0; i < wallCount; i++) {
        if (abs(x - wallX[i]) < .1 && abs(y - wallY[i]) < .1)
            return true;
    }
    return false;
}

void drawPacMan() {
    if (gameOver) return;
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(playerX, playerY);
    for (int i = 30; i < 330; i++) {
        float angle = i * 3.14 / 180;         //to radian
        glVertex2f(playerX + 0.07 * cos(angle), playerY + 0.07 * sin(angle));     //.07 is r
    }
    glEnd();
}

void drawDots() {
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < dotCount; i++) {
        if (dotEaten[i] == 0) {
            glBegin(GL_QUADS);
            glVertex2f(dotX[i] - 0.01, dotY[i] - 0.01);
            glVertex2f(dotX[i] + 0.01, dotY[i] - 0.01);
            glVertex2f(dotX[i] + 0.01, dotY[i] + 0.01);
            glVertex2f(dotX[i] - 0.01, dotY[i] + 0.01);
            glEnd();
        }
    }
}

void drawWalls() {
    glColor3f(1.0, 0.2, 0.0);
    for (int i = 0; i < wallCount; i++) {
        glBegin(GL_QUADS);
        glVertex2f(wallX[i] - 0.05, wallY[i] - 0.05);
        glVertex2f(wallX[i] + 0.05, wallY[i] - 0.05);
        glVertex2f(wallX[i] + 0.05, wallY[i] + 0.05);
        glVertex2f(wallX[i] - 0.05, wallY[i] + 0.05);
        glEnd();
    }
}

void drawForWin() {
    glColor3f(1.0, 0.84, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1, -0.2);
    glVertex2f(0.1, -0.2);
    glVertex2f(0.15, 0.0);
    glVertex2f(-0.15, 0.0);
    glEnd();


    glColor3f(1.0, 0.8, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.15, 0.0);
    glVertex2f(-0.2, 0.05);
    glVertex2f(-0.15, 0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.15, 0.0);
    glVertex2f(0.2, 0.05);
    glVertex2f(0.15, 0.1);
    glEnd();


    glColor3f(0.6, 0.3, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.08, -0.25);
    glVertex2f(0.08, -0.25);
    glVertex2f(0.05, -0.2);
    glVertex2f(-0.05, -0.2);
    glEnd();
}

void drawForLose() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14 / 180.0;
        glVertex2f(.2 * cos(angle), .2 * sin(angle));
    }
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3);

    glBegin(GL_LINES);
    glVertex2f(-0.07, 0.05);
    glVertex2f(-0.03, 0.09);
    glVertex2f(-0.03, 0.05);
    glVertex2f(-0.07, 0.09);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.03, 0.05);
    glVertex2f(0.07, 0.09);
    glVertex2f(0.07, 0.05);
    glVertex2f(0.03, 0.09);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.05, -0.05);
    glVertex2f(0.05, -0.05);

    glEnd();
}

void movePlayer(int) {
    if (gameOver) return;

    float newX = playerX, newY = playerY;
    if (direction == 'u') newY += moveSpeed;
    if (direction == 'd') newY -= moveSpeed;
    if (direction == 'l') newX -= moveSpeed;
    if (direction == 'r') newX += moveSpeed;

    if (isWall(newX, newY)) {
        gameOver = true;
        win = false;
        glutPostRedisplay();
        return;
    }

    if (newX > 1.0) newX = -1.0;
    if (newX < -1.0) newX = 1.0;
    if (newY > 1.0) newY = -1.0;
    if (newY < -1.0) newY = 1.0;

    playerX = newX;
    playerY = newY;

    for (int i = 0; i < dotCount; i++) {
        if (!dotEaten[i] && abs(playerX - dotX[i]) < 0.05 && abs(playerY - dotY[i]) < 0.05) {
            dotEaten[i] = true;
           

        }
    }

    bool allEaten = true;
    for (int i = 0; i < dotCount; i++) {
        if (!dotEaten[i]) {
            allEaten = false;
            break;
        }
    }
    if (allEaten) {
        gameOver = true;
        win = true;
    }

    glutPostRedisplay();
    glutTimerFunc(100, movePlayer, 0);
}

void specialKeys(int key, int x, int y) {
    if (gameOver) return;

    switch (key) {
    case GLUT_KEY_UP:
        direction = 'u';
        break;
    case GLUT_KEY_DOWN:
        direction = 'd';
        break;
    case GLUT_KEY_LEFT:
        direction = 'l';
        break;
    case GLUT_KEY_RIGHT:
        direction = 'r';
        break;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (gameOver) {
        if (win) {
            drawForWin();

        }
        else {
            drawForLose();
        }
    }
    else {
        drawPacMan();
        drawDots();
        drawWalls();
    }

    glClearColor(0.0, 0.0, 0.2, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glutSwapBuffers();
   
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(600, 200);
    glutCreateWindow("Pac-Man Game");


    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(100, movePlayer, 0);
    glutMainLoop();
    return 0;
}