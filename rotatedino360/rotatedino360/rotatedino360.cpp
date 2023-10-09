#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>

using std::cout;
using std::fstream;
using std::ios;

const int screenWidth = 650;	   // width of screen window in pixels 
const int screenHeight = 450;	   // height of screen window in pixels
double rotate_x = 0.5;

void setWindow(int xs, int xe, int ys, int ye) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D((GLint)xs, (GLint)xe, (GLint)ys, (GLint)ye);
}

void drawPolyLineFile(const char* fileName) {
    fstream inStream;
    inStream.open(fileName, ios::in);	// open the file

    if (inStream.fail()) {
        cout << "can't open it!";
        return;
    }

    GLfloat numpolys, numPoints, x, y;
    inStream >> numpolys;		           // read the number of polylines

    for (int j = 0; j < numpolys; j++)  // read each polyline
    {
        inStream >> numPoints;       //number of points in the first PolyLine  
        glBegin(GL_LINE_STRIP);	     // draw the next polyline
        for (int i = 0; i < numPoints; i++) {
            inStream >> x >> y;        // read the next x, y pair
            glVertex2f(x, y);
        }
        glEnd();
    }
    inStream.close();
}

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);       // background color is white
    glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black
    glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
    glViewport(0, 0, screenWidth, screenHeight);
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    setWindow(0, 640, 0, 480);

    int numDinos = 10;  // Number of dinos in the circular pattern
    double radius = 120.0; // Radius of the circular pattern

    double rotationAngle = 360.0 / numDinos; // Angle to rotate each dino by

    for (int i = 0; i < numDinos; i++) {
        double angle = 2.0 * 3.14159265358979323846 * i / numDinos; // Calculate angle for each dino
        double x = screenWidth / 2 + radius * cos(angle)+32;
        double y = screenHeight / 2 + radius * sin(angle)+22;

         glViewport(x , y , 64, 44); // Adjust the viewport for each dino
        glPushMatrix(); // Save the current matrix
        glTranslatef(x, y, 0); // Translate to the dino's position
        glRotatef(i * rotationAngle, 0, 0, 1); // Rotate the dino
        glTranslatef(-x, -y, 0); // Translate back to the original position
        drawPolyLineFile("dino.txt");
        glPopMatrix(); // Restore the previous matrix
    }

    glFlush();
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
    glutInitWindowSize(screenWidth, screenHeight); // set window size
    glutInitWindowPosition(10, 10); // set window position on screen
    glutCreateWindow("Dino Circular Drawing"); // open the screen window
    glutDisplayFunc(myDisplay);     // register redraw function
    myInit();
    glutMainLoop(); 		     // go into a perpetual loop
    return 1;
}
