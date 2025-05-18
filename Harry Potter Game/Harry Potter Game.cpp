#include <GL/glut.h>
#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

float X_for_Harry = -90; 
float Y_for_Harry = 0;   

vector<pair<float, float>> snitches = {
    {80,0},{30,0},{80,-30},{ 30,-80 },{80,30},{-100,100},{70,-10},{100,-100}
};

bool gameOver = false;
bool win = false;  
const float WIN_POSITION = 60; 

void CompleteTheShape(float originX, float originY, const vector<vector<float>>& pixels, const vector<vector<float>>& palette) {
    int rows = pixels.size();
    int cols;
    if (rows > 0) {
        cols = pixels[0].size();
    }
    else {
        cols = 0;
    }


    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {

            float currentX = originX + col;
            float currentY = originY - row;
            int colorIndex = static_cast<int>(pixels[row][col]);

            if (colorIndex != -1) {
                float r = palette[colorIndex][0] / 255.0f;
                float g = palette[colorIndex][1] / 255.0f;
                float b = palette[colorIndex][2] / 255.0f;


                glColor3f(r, g, b);
                glBegin(GL_QUADS);
                glVertex2f(currentX, currentY);
                glVertex2f(currentX + 1, currentY);
                glVertex2f(currentX + 1, currentY + 1);
                glVertex2f(currentX, currentY + 1);
                glEnd();
            }
        }
    }
}




void drawHarry(float x, float y) {
        vector<vector<float>> HARRY = {
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,2,2,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,2,0,2,2,2,2,0,2,0,0,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,2,2,2,2,2,2,2,2,2,0,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,2,2,0,1,2,0,1,2,2,0,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,2,2,2,0,0,2,0,0,2,2,0,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,2,2,2,2,2,2,2,2,2,2,0,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,2,2,0,2,2,2,2,2,0,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,0,2,2,0,0,2,2,2,0,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,4,4,0,0,2,2,2,2,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,3,3,4,4,1,0,0,0,0,1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,3,3,3,4,1,1,3,3,1,1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,3,3,3,0,4,1,3,3,1,4,0,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,3,3,3,3,0,4,5,3,3,5,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,0,3,3,0,3,3,3,0,4,5,5,4,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,0,0,0,0,1,1,0,3,3,3,0,3,3,3,3,0,4,4,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,6,6},
            {-1,-1,0,0,3,3,0,0,0,3,3,3,3,0,3,3,3,3,0,3,0,-1,-1,-1,-1,-1,-1,-1,6,6,6,6},
            {-1,-1,-1,0,3,3,3,3,3,3,3,3,0,0,3,3,3,0,4,0,0,-1,-1,-1,-1,-1,6,6,6,6,-1,-1},
            {5,5,5,0,3,3,3,3,3,3,3,0,0,0,3,3,0,4,2,2,0,0,6,6,6,6,6,6,-1,-1,-1,-1},
            {5,5,5,5,0,3,3,3,3,3,0,0,0,0,3,0,4,2,2,2,2,0,6,6,-1,-1,-1,-1,-1,-1,-1,-1},
            {5,5,5,5,5,0,3,3,3,0,5,0,0,0,0,4,0,2,2,2,2,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,5,5,5,5,5,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,5,5,5,5,5,0,0,0,5,5,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,5,5,5,5,5,5,5,5,0,0,0,0,1,1,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,5,5,5,5,5,0,0,0,0,1,1,1,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,5,5,1,1,0,0,0,1,1,1,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,-1,-1,-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        };

        vector<vector<float>> HarryColor = {
                                         {1,0,5},         //black              0
                                          {255,255,255},    //white            1
                                           {237,217,164},     //face           2
                                           {77,77,77} ,        //gray          3
                                              {146,21,19},      //red          4
                                               { 228,200,91 },    //yellow     5
                                               {105,47,27}        //broom      6
        };

        CompleteTheShape(X_for_Harry, Y_for_Harry, HARRY, HarryColor);
    }


void drawSnitch(float x, float y) {
        vector<vector<float>> snitch = {
            {1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,1},
            {-1,1,1,1,1,-1,-1,-1,-1,1,1,1,1,-1},
            {-1,-1,1,1,1,-1,-1,-1,-1,1,1,1,-1,-1},
            {-1,-1,-1,1,1,1,0,0,1,1,1,-1,-1,-1},
            {-1,-1,-1,-1,-1,0,0,0,0,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,0,0,0,0,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,0,0,0,0,-1,-1,-1,-1,-1},
        };

        vector<vector<float>> snitchColor = {
            {206,176,78}, {254,254,254} 
        };

        CompleteTheShape(x, y, snitch, snitchColor);
    }

void checkGameStatus() {
   
    if (X_for_Harry >= WIN_POSITION) {
        gameOver = true;
        win = true;
        return;
    }

    
    float harryLeft = X_for_Harry;
    float harryRight = X_for_Harry + 32;
    float harryTop = Y_for_Harry;
    float harryBottom = Y_for_Harry - 32;

    for (auto& snitch : snitches) {
        float snitchLeft = snitch.first;
        float snitchRight = snitch.first + 14;
        float snitchTop = snitch.second;
        float snitchBottom = snitch.second - 7;

        if (harryRight > snitchLeft && harryLeft < snitchRight &&
            harryTop > snitchBottom && harryBottom < snitchTop) {
            gameOver = true;
            win = false;
            return;
        }
    }
}


void update() {
    if (!gameOver) {
        X_for_Harry += 0.2f; 

        
        for (int i = 0; i < snitches.size(); ++i) {
            snitches[i].first -= 0.5f;
            if (snitches[i].first < -100) {
                snitches[i].first = 100;
            }
        }

        checkGameStatus();
    }
}


void timer(int value) {
    if (!gameOver) {
        update();
        glutPostRedisplay();
    }
    glutTimerFunc(16, timer, 0);
}

void specialKeys(int key, int x, int y) {
    if (!gameOver) {
        if (key == GLUT_KEY_UP) {
            Y_for_Harry += 5;
        }
        else if (key == GLUT_KEY_DOWN) {
            Y_for_Harry -= 5;
        }
        checkGameStatus();
        glutPostRedisplay();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

   glBegin(GL_QUADS);

glColor3f(0.5f, 0.8f, 1.0f);
glVertex2f(-100.0f, 100.0f);

glColor3f(0.5f, 0.8f, 1.0f);
glVertex2f(100.0f, 100.0f);

glColor3f(0.0f, 0.3f, 0.6f);
glVertex2f(100.0f, -100.0f);

glColor3f(0.0f, 0.3f, 0.6f);
glVertex2f(-100.0f, -100.0f);

glEnd(); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

    if (!gameOver) {
        drawHarry(X_for_Harry, Y_for_Harry);
        for (auto snitch : snitches) {
            drawSnitch(snitch.first, snitch.second);
        }
    }
    else {
        glColor3f(1, 1, 1); 
        glBegin(GL_QUADS);
        glVertex2f(-100, -50);
        glVertex2f(100, -50);
        glVertex2f(100, 50);
        glVertex2f(-100, 50);
        glEnd();

        if (win) {
            glColor3f(0, 1, 0); 
            glRasterPos2f(-30, 0);
            string message = "Well Done !!!";
            for (char c : message) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
            }
        }
        else {
            glColor3f(1, 0, 0); 
            glRasterPos2f(-40, 0);
            string message = "GAME OVER!!!";
            for (char c : message) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
            }
        }
    }

    glutSwapBuffers();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 1000);
    glutCreateWindow("Harry Potter Game");

   
    glutDisplayFunc(display);

    glutSpecialFunc(specialKeys);

    glutTimerFunc(25, timer, 0);

    glutMainLoop();
    return 0;
}
