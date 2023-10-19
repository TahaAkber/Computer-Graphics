#include <gl/Canvas2.h.h>

#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>


#define M_PI  3.14157

// display

//using namespace std;

Canvas cvs(640, 480, "Test Canvas");


void ngon(int n, double cx, double cy, double radius, double Angle) {
    if (n < 3) {
        return;
    }
    double angle = Angle * 3.142 / 180;
    double anglearc = 2 * 3.142 / n;
    cvs.moveTo(radius * cos(angle) + cx, radius * sin(angle) + cy);
    for (int i = 0; i < n; i++) {
        angle += anglearc;
        cvs.lineTo(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }


}
void display(void)
{
    cvs.clearScreen(); //clear screen
    ngon(6, 300, 250, 100, 0);
    cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
    cvs.setViewport(0, 640, 480, 0);

   
    glFlush();
}// end display





int main(int argc, char** argv)
{
    // the window is opened in the Canvas constructor
    cvs.setBackgroundColor(0.0, 0.0, 0.0); 
    cvs.setColor(1.0, 1.0, 1.0); 
    glutDisplayFunc(display);
    glutMainLoop();
}//end main

