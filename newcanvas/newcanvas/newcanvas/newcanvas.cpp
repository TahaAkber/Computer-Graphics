#include <gl/Canvas2.h.h>

#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>


#define M_PI  3.14157

// display

//using namespace std;

Canvas cvs(640, 480, "Test Canvas");

//draw arrow using relative drawing
void arrow(float f, float h, float t, float w) {
    cvs.lineRel(-w - t / 2, -f);
    cvs.lineRel(w, 0);
    cvs.lineRel(0, -h);
    cvs.lineRel(t, 0);
    cvs.lineRel(0, h);
    cvs.lineRel(w, 0);
    cvs.lineRel(-w -t/2, f);

};

void display(void)
{
    cvs.clearScreen(); //clear screen

    cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
    cvs.setViewport(10, 460, 10, 460);

    //Drawing box using given Class functions
    
    RealRect box(-2.0, 2.0, -1.0, 1.0);
    box.draw();
    // ***************PRACTICING Simple Line DRAWING************//
    // call moveTo() and lineTo();
    
    cvs.moveTo(0, -5.0);
    cvs.lineTo(0, 5.0);
     
    //Relative drawing start function declaration here
    arrow(5, 5, 5, 5);
    // ***************END RELATIVE DRAWING*********************//
    glFlush();
}// end display





int main(int argc, char** argv)
{
    // the window is opened in the Canvas constructor
    cvs.setBackgroundColor(0.0, 0.0, 0.0); //background color is white 
    cvs.setColor(1.0, 1.0, 0.0); //drawing color is red 
    glutDisplayFunc(display);
    glutMainLoop();
}//end main