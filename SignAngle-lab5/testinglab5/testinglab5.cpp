#include <iostream>
#include <cmath>    // Include cmath for sin function
#include <GL/glut.h>

//--------------- setWindow ---------------------
void setWindow(float left, float right, float bottom, float top)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);
}

//---------------- setViewport ------------------
void setViewport(float left, float right, float bottom, float top)
{
    glViewport(left, bottom, right - left, top - bottom);
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // set white background color
    glColor3f(0.0f, 0.0f, 0.0f);     // set the drawing color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void) // plot the sinc function, using world coordinates
{
    setWindow(-5.0, 5.0, -0.3, 1.0); // set the window
    setViewport(0, 640, 0, 480);    // set the viewport
    glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer
    glBegin(GL_LINE_STRIP);
    for (GLfloat x = -4.0; x < 4.0; x += 0.1) // draw the plot
        glVertex2f(x, sin(3.14159 * x) / (3.14159 * x));
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
    glutInitWindowSize(640, 480); // set window size
    glutCreateWindow("my first attempt"); // open the screen window
    glutDisplayFunc(myDisplay); // register redraw function
    myInit();
    glutMainLoop(); // go into a perpetual loop
    return 0; // Return a value from main
}
