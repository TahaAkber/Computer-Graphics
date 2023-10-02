// built-in Matrics OGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <gl/glut.h>
#include <math.h>
#include <Windows.h>
#include <iostream>
using namespace std;

int screenWidth = 640;
int screenHeight = 480;

void initGL() {
    glClearColor(255,255,255,255);
}

void displayMatrix(GLdouble* m) {
    int incr = 4;
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 4; row++) {
            cout << m[col + row * incr] << "";
        }
        cout << endl;
    }
    cout << endl;
}
void peekAtMatrixCT(void) {
    GLdouble CT[16];
    glGetDoublev(GL_MODELVIEW_MATRIX, CT);
    displayMatrix(CT);
    return;
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    GLdouble matrix[16] = {
        1.0, 2.0, 3.0, 4.0,
        5.0, 6.0, 7.0, 8.0,
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    displayMatrix(matrix);
    peekAtMatrixCT();
    glFlush();
    glutSwapBuffers();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Taha lab 9");


    glMatrixMode(GL_PROJECTION); // used this
    glLoadIdentity(); // used this
    glOrtho(0, screenWidth, 0, screenHeight, -1, 1); // used this
    glMatrixMode(GL_MODELVIEW); // used this

    glutDisplayFunc(myDisplay);
    initGL();
    glutMainLoop();
    return 0;
}













