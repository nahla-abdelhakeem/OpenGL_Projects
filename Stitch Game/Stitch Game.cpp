#include<GL/glut.h>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

float X_for_Stitch = 0;
float Y_for_Stitch = -60;

float stitchX = 0; 
bool moveRight = false;
bool moveLeft = false;
int score = 0;
const int WIN_SCORE = 3; 
bool gameOver = false;
bool win = false;


float knifeX[3] = { -10, -80, 50 };
float knifeY[3] = { 90, 90, 100 }; 

float heartX[3] = { -40, 20, 90 }; 
float heartY[3] = { 80, 100, 100 };

bool checkCollision(float x1, float y1, float x2, float y2, float threshold = 15) {
    return (abs(x1 - x2) < threshold && abs(y1 - y2) < threshold);
}

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

void drawStitchShape() {
    vector<vector<float>> stitch = {
        {-1,-1,-1,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,0,1,1,1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,0,1,1,1,2,2,0,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,0,1,1,0,2,4,2,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,0,0,0,4,4,4,4,0,3,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {0,2,2,4,4,0,0,4,4,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {0,2,4,4,0,0,0,0,4,4,0,-1,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {0,2,4,0,7,7,0,0,0,4,4,0,-1,-1,-1,-1,-1,-1,-1,-1,0,3,-1},
        {0,2,4,0,7,7,0,0,0,4,4,2,0,3,-1,-1,-1,-1,5,5,0,1,0},
        {0,2,4,0,0,0,0,0,0,4,4,2,2,0,-1,-1,5,5,5,3,0,4,0},
        {0,2,4,0,0,0,0,0,0,4,4,2,2,2,0,3,5,3,5,0,4,4,0},
        {0,2,4,4,0,0,0,0,4,4,4,2,2,2,2,0,0,0,0,4,4,0,-1},
        {0,2,4,4,4,0,0,4,4,4,4,2,2,2,2,2,2,4,4,4,0,-1,-1},
        {0,2,2,4,4,4,4,4,4,4,2,2,2,2,2,2,4,4,4,0,-1,-1,-1},
        {-1,0,2,4,4,4,4,4,4,2,2,2,2,2,2,2,4,4,4,0,-1,-1,-1},
        {-1,0,2,2,2,2,2,2,2,2,2,0,2,2,2,4,4,4,0,-1,-1,-1,-1},
        {-1,-1,0,0,2,2,2,2,2,2,0,2,2,2,2,4,4,0,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,0,0,2,2,2,0,2,2,2,0,2,4,4,4,0,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,0,0,2,0,2,2,2,0,2,2,4,4,4,0,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,0,2,2,2,0,5,0,2,0,4,4,0,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,0,2,2,2,0,5,0,2,2,0,0,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,0,2,2,2,0,5,5,5,0,2,2,0,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,0,2,2,2,0,5,5,5,0,2,2,0,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,0,0,2,2,2,0,5,5,5,0,2,2,2,0,-1,-1,-1},
        {-1,-1,-1,-1,-1,0,2,0,2,2,0,5,5,5,5,0,2,2,2,0,-1,-1,-1},
        {-1,-1,-1,-1,0,2,2,0,2,0,5,5,5,0,0,2,0,2,2,2,0,-1,-1},
        {-1,-1,0,0,2,2,0,5,5,5,5,5,5,5,0,2,2,0,2,2,0,-1,-1},
        {-1,0,2,2,0,0,5,5,5,5,5,5,5,5,0,2,2,2,0,0,0,-1,-1},
        {-1,0,2,2,0,0,5,5,5,5,5,5,5,5,0,2,2,2,2,2,2,0,-1},
        {-1,0,2,0,5,5,5,5,5,5,5,5,5,0,2,2,2,2,2,2,2,0,-1},
        {-1,-1,0,5,5,5,5,5,5,5,5,5,0,2,2,2,2,2,2,2,0,-1,-1},
        {-1,-1,0,5,5,5,5,5,5,5,0,0,0,2,2,2,2,2,2,2,2,2,0},
        {-1,-1,0,5,5,5,5,5,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0},
        {-1,-1,-1,0,0,0,0,0,-1,-1,0,0,0,0,0,0,-1,-1,-1,0,2,0,0},
    };

    vector<vector<float>> stitchColor = {
                                      {57,51,48},    //black              0
                                      {1,56,139},    //blue               1
                                      {42,104,160},  //blue body         2
                                      {203,189,147},  //teeth           3
                                      {26,164,189},    //blue around eye  4
                                      {252,101,143},   //tongue           5
                                      {214,136,192},   //ear              6
                                       {205,192,191,255}
    };

    CompleteTheShape(X_for_Stitch, Y_for_Stitch, stitch, stitchColor);
}


void drawKnifeShape(int idx) {
    vector<vector<float>> flow = {
        {-1,0,0,-1,-1},
        {0,0,0,-1,-1},
        {0,-1,0,-1,-1},
        {0,0,0,-1,-1},
        {0,-1,0,-1,-1},
        {0,0,0,-1,-1},
        {0,0,0,-1,-1},
        {0,0,1,1,1},
        {1,1,1,1,2},
        {1,1,1,1,2},
        {1,1,2,1,2},
        {1,1,1,2,2},
        {1,1,1,1,2},
        {1,1,1,1,2},
        {1,1,2,2,2},
        {1,2,1,2,-1},
        {1,1,2,2,-1},
        {1,2,2,-1,-1},
        {1,2,2,-1,-1},
        {2,2,-1,-1,-1},
        {2,-1,-1,-1,-1},
    };

    vector<vector<float>> KnifeColor = {
                                      {32,32,32},    // black   0
                                      {145,145,145}, //  gray    1
                                      {161,3,0},      //red       2

    };

    CompleteTheShape(knifeX[idx], knifeY[idx], flow, KnifeColor);
}




void drawHeartShape(int idx) {
    vector<vector<float>> flow = {
        {-1,0,0,-1,-1,0,0,-1},
        {0,1,1,0,0,1,1,0},
        {0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,0},
        {-1,0,1,1,1,1,0,-1},
        {-1,-1,0,1,1,0,-1,-1},
        {-1,-1,-1,0,0,-1,-1,-1},

    };

    vector<vector<float>> heartColor = {
                                          {1,1,3},    // black   0
                                        {239,6,11},  // red      1


    };

    CompleteTheShape(heartX[idx], heartY[idx], flow, heartColor);
}

void keyboard(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        X_for_Stitch -= 6;
    }
    else if (key == GLUT_KEY_RIGHT) {
        X_for_Stitch += 6;
    }
}

void updatePositions(int value) {
    if (gameOver) return;

   
    if (moveRight) {
        X_for_Stitch += 8;
    }
    else if (moveLeft) {
        X_for_Stitch -= 28;
    }

    
    if (X_for_Stitch > 100) X_for_Stitch = 100;
    if (X_for_Stitch < -100) X_for_Stitch = -100;

   
    for (int i = 0; i < 3; i++) {
        knifeY[i] -= 1;
        if (knifeY[i] < -100) {
            knifeY[i] = 100;
        }

        heartY[i] -= 1;
        if (heartY[i] < -100) {
            heartY[i] = 100;
        }
    }

   
    for (int i = 0; i < 3; i++) {
        if (checkCollision(X_for_Stitch, Y_for_Stitch, heartX[i], heartY[i])) {
            score++;
            heartX[i] = -100;
            heartY[i] = 100;

           
            if (score >= WIN_SCORE) {
                gameOver = true;
                win = true;
            }
        }
    }

    
    for (int i = 0; i < 3; i++) {
        if (checkCollision(X_for_Stitch, Y_for_Stitch, knifeX[i], knifeY[i])) {
            gameOver = true;
            win = false;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, updatePositions, 0);
}
void drawBackground() {
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.4f, 0.7f);  
    glVertex2f(-100, 100); 
    glVertex2f(100, 100); 
    glColor3f(0.3f, 0.6f, 1.0f); 
    glVertex2f(100, -50);    
    glVertex2f(-100, -50);   
                                        
    glColor3f(0.3f, 0.6f, 1.0f);
    glVertex2f(-100, 50);
    glVertex2f(100, 50);
    glColor3f(0.4f, 0.7f, 1.0f);   
    glVertex2f(100, 0);
    glVertex2f(-100, 0);




    glColor3f(0.0f, 0.6f, 0.0f);  
    glVertex2f(-100, -50);   
    glVertex2f(100, -50);    
    glVertex2f(100, -45);    
    glVertex2f(-100, -45);   


    
    glColor3f(0.545f, 0.271f, 0.075f);
    glVertex2f(-100, -50);   
    glVertex2f(100, -50);    
    glVertex2f(100, -100);   
    glVertex2f(-100, -100);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawBackground();

    if (!gameOver) {
       
        drawStitchShape();
        for (int i = 0; i < 3; i++) {
            drawHeartShape(i);
            drawKnifeShape(i);
        }
    }
    else {
        
        glColor3f(1, 1, 1); 
        glBegin(GL_QUADS);
        glVertex2f(-50, -20);
        glVertex2f(50, -20);
        glVertex2f(50, 20);
        glVertex2f(-50, 20);
        glEnd();

        if (win) {
            glColor3f(0, 1, 0);
            glRasterPos2f(-30, 0);
            string message = "Well Done!!!";
            for (char c : message) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
            }
        }
        else {
            glColor3f(1, 0, 0); 
            glRasterPos2f(-30, 0);
            string message = "GAME OVER!!!";
            for (char c : message) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
            }
        }
    }

    
    glColor3f(1, 1, 1);
    glRasterPos2f(-90, 90);
    

    glutSwapBuffers();
}


int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("Stitch Game");

    glClearColor(0.0, 0.0, 1.0, 1.0); 
    glOrtho(-100, 100, -100, 100, -1, 1); 
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutTimerFunc(25, updatePositions, 0); 
   
    glutMainLoop();

    return 0;
}