#include <gl/glut.h>
#include <math.h>
#include <Windows.h>
#include <iostream>

using namespace std;

int screenWidth = 1000;
int screenHeight = 600;

void initGL() {
    glClearColor(0,0,0,0);
}

void hexagon() {
    glBegin(GL_LINES);
    // Define the vertices of the hexagon
    glVertex2f(1.0f, 0.0f); // Center
    glVertex2f(0.5f, 0.866f); // Top-right
    glVertex2f(0.5f, 0.866f); // Top-right
    glVertex2f(-0.5f, 0.866f); // Top-left
    glVertex2f(-0.5f, 0.866f); // Top-left
    glVertex2f(-1.0f, 0.0f); // Bottom-left
    glVertex2f(-1.0f, 0.0f); // Bottom-left
    glVertex2f(-0.5f, -0.866f); // Bottom-right
    glVertex2f(-0.5f, -0.866f); // Bottom-right
    glVertex2f(0.5f, -0.866f); // Bottom-center
    glVertex2f(0.5f, -0.866f); // Bottom-center
    glVertex2f(1.0f, 0.0f); // Center
    glEnd();
}
void grid(double R) {
   
    for (int j = 0; j < 5; j++) {        
        for (int i = 0; i < 5; i++) {
            hexagon();
            glTranslatef(3 * R / 2, 0, 0);
        }
        glTranslatef(-(3 * R / 2)*5, 1.732 * R, 0);
       
   }
    glTranslatef(0, -1.732 * 6, 0);   
}



void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    grid(1);
    
    glLoadIdentity();
    glFlush();
    glutSwapBuffers();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Grid Tiling");


    glMatrixMode(GL_PROJECTION); // used this
    glLoadIdentity(); // used this
    gluOrtho2D(10, -10, -10, 10); // used this
    glMatrixMode(GL_MODELVIEW); // used this

    glutDisplayFunc(myDisplay);
    initGL();
    glutMainLoop();
    return 0;
}



