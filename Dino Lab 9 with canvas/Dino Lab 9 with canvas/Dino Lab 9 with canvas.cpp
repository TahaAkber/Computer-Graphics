#include <gl/Canvas2.h.h>

#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>


#define M_PI  3.14157

// display

using namespace std;

Canvas cvs(640, 480, "Test Dino");


void translate2D(GLfloat x, GLfloat y) {
	glTranslatef(x, y, 0.0f);
}

void drawmotif(const char* fileName)
{
	fstream inStream;

	inStream.open(fileName, ios::in);	// open the file

	if (inStream.fail())
	{
		cout << "can't open it!"; return;
	}

	// clear the screen

//GLint numpolys, numPoints, x ,y;

	GLfloat numpolys, numPoints, x, y;
	inStream >> numpolys;		           // read the number of polylines


	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numPoints;       //number of points in first PolyLine  
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2f(x, y);
		}
		glEnd();
	}
	inStream.close();
};

void Tilemotif() {
    glPushMatrix();
	translate2D(10,-10);
    for (int i = 0; i < 10; i++) {
        glPushMatrix();
        for (int j = 0; j < 10; j++) {
			glViewport(i * 64, j * 44, 64, 44);
			drawmotif("Dino.txt");
        }
		glPopMatrix();
    }
}

void display(void)
{
    cvs.clearScreen(); //clear screen

	Tilemotif();
	
    cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
    cvs.setViewport(10, 460, 10, 460);

    glFlush();
}// end display





int main(int argc, char** argv)
{
    // the window is opened in the Canvas constructor
    cvs.setBackgroundColor(1.0, 1.0, 1.0); //background color is white 
    cvs.setColor(1.0, 0.0, 1.0); //drawing color is red 
    glutDisplayFunc(display);
	glutSwapBuffers();
    glutMainLoop();
}//end main