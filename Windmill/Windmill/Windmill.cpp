///*
//This is a program which displays several primitives as well as animates objects.
//Your task is to make the plane that makes a crash landing, but unlike the movies,
//it doesn't burst into flames.The background contains a triangle for windmill.
//You need to complete it using transformation then make it animate*/
//
//#include "gl/glut.h"
//#define PI 3.141592
//
//void display(void); // draw everything
//void drawWind(void);  // draw single blade 
//void drawwindmill(void); //complete this to complete windmill i.e. call drawWind() in it
//void drawplane();  // work in this function
////  for crash landing of plane i.e. animate and collision with land 
//
//void drawlandscape();// do nothing with it 
//void Timer(int value); // update varible for animation here
//
//void keyboard(unsigned char key, int x, int y);
//void init(void);
//void reshape(GLsizei w, GLsizei h);
//
//
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glLoadIdentity();
//
//	drawlandscape();
//	drawplane();
//	drawwindmill();
//
//
//	glutSwapBuffers();
//
//
//}
//
//
//void drawWind() // single Triangle
//{
//
//	glBegin(GL_TRIANGLES);
//
//	glColor3f(0.8, 0.8, 0.8);
//	glVertex2f(125, 90);
//	glVertex2f(140, 120);
//	glVertex2f(160, 120);
//
//	glEnd();
//};
//	
//
//void drawwindmill()
//{
//
//	drawWind();
//	//	glPushMatrix();  // Save the current transformation matrix
//	//	glScalef(1.0f, -1.0f, 1.0f);
//	//
//	//	 Draw the reflected objects
//	//	glBegin(GL_TRIANGLES);
//	//	glColor3f(0.0f, 0.0f, 1.0f);  // Blue color
//	//	glVertex2f(125, -90);
//	//	glVertex2f(140, -120);
//	//	glVertex2f(160, -120);
//	//	glEnd();
//	//
//	//	glPopMatrix();  // Restore the original transformation matrix
//	//};
//	
//}
//
//void Timer(int value) // work in this function after completing windmill to animate it
//{
//	//update variables here
//
//	glutPostRedisplay();
//	display();
//	glutTimerFunc(30, Timer, 1);
//	
//}
//
//
//void drawplane()// work in this function to animate and crash plane
//{
//	/* Draw a plane */
//
//	glBegin(GL_TRIANGLES);
//
//	glColor3f(1.0, 1.0, 1.0);
//	glVertex2f(245.0, 230.0);
//	glVertex2f(245.0, 240.0);
//	glVertex2f(215.0, 230.0);
//
//
//
//	glColor3f(0.2, 0.2, 0.2);
//	glVertex2f(244.0, 228.0);
//	glVertex2f(244.0, 235.0);
//	glVertex2f(228.0, 235.0);
//
//	glEnd();
//
//
//}
//
//
//void main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(50, 50);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("BSCS 514 Lab #8");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutTimerFunc(30, Timer, 1);
//	glutMainLoop();
//}
//
//
//
//void drawlandscape()
//{
//	/* Draw a box of grass */
//	glBegin(GL_QUADS);
//	glColor3f(0.0, 1.0, 0.0);
//	glVertex2f(250.0, 0.0);
//	glColor3f(0.0, 0.9, 0.0);
//	glVertex2f(250.0, 50.0);
//	glColor3f(0.0, 0.8, 0.0);
//	glVertex2f(0.0, 50.0);
//	glColor3f(0.0, 0.7, 0.0);
//	glVertex2f(0.0, 0.0);
//	glEnd();
//
//	/* An attempt at a few snow covered mountains */
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(0.0, 0.0, 0.6);
//	glVertex2f(250.0, 50.0);
//	glColor3f(1.0, 1.0, 1.0);
//	glVertex2f(200.0, 150.0);
//	glColor3f(0.0, 0.0, 0.5);
//	glVertex2f(150.0, 50.0);
//
//	//glBegin(GL_TRIANGLES);
//	glColor3f(0.0, 0.0, 0.5);
//	glVertex2f(200.0, 50.0);
//	glColor3f(1.0, 1.0, 1.0);
//	glVertex2f(150.0, 150.0);
//	glColor3f(0.0, 0.0, 0.5);
//	glVertex2f(100.0, 50.0);
//
//	glColor3f(0.0, 0.0, 0.7);
//	glVertex2f(150.0, 50.0);
//	glColor3f(1.0, 1.0, 1.0);
//	glVertex2f(100.0, 150.0);
//	glColor3f(0.0, 0.0, 0.5);
//	glVertex2f(50.0, 50.0);
//
//	glColor3f(0.0, 0.0, 0.5);
//	glVertex2f(100.0, 50.0);
//	glColor3f(1.0, 1.0, 1.0);
//	glVertex2f(50.0, 150.0);
//	glColor3f(0.0, 0.0, 0.5);
//	glVertex2f(0.0, 50.0);
//
//	glEnd();
//
//	/* Draw the body of a windmill */
//	glBegin(GL_QUADS);
//	glColor3f(0.6, 0.6, 0.0);
//	glVertex2f(145.0, 50.0);
//	glVertex2f(135.0, 100.0);
//	glVertex2f(115.0, 100.0);
//	glVertex2f(105.0, 50.0);
//	glEnd();
//
//}
//
//void init()
//{
//	glClearColor(0.8f, 0.8f, 1.0f, 1.0f);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, 250.0, 0.0, 250.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void reshape(GLsizei w, GLsizei h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, 250.0, 0.0, 250.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//
//
//
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 27:
//		exit(0);
//		break;
//	}
//}



#include <windows.h>
#include <gl/Gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#define PI 3.141592

void display(void); // draw everything
void drawWind(void);  // draw single blade 
void drawwindmill(void); //complete this to complete windmill i.e. call drawWind() in it
void drawplane();  // work in this function
//  for crash landing of plane i.e. animate and collision with land 

void drawlandscape();// do nothing with it 
void Timer(int value); // update variable for animation here

void keyboard(unsigned char key, int x, int y);
void init(void);
void reshape(GLsizei w, GLsizei h);




void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawlandscape();
    drawplane();
    drawwindmill();


    glutSwapBuffers();


}
static float windmillAngles[4] = { 0.0f, 90.0f, 180.0f, 270.0f };

void drawWind() // single Triangle
{

    glBegin(GL_TRIANGLES);

    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(125.0, 90.0);
    glVertex2f(140.0, 120.0);
    glVertex2f(160.0, 120.0);
    glEnd();

}

void drawwindmill()
{
    glPushMatrix();

    // Rotate the entire windmill about an arbitrary point (126.0, 93.0)
    static float angle = 1.0f; // Define a static variable to store the rotation angle
    angle += PI; // Increment the angle for rotation

    // Draw the windmill blades using a loop
    for (int i = 0; i < 4; ++i) {
        glTranslatef(125.0, 90.0, 0.0); // Translate to the center of the windmill
        glRotatef(windmillAngles[i], 0.0f, 0.0f, 1.0f);
        glTranslatef(-125.0, -90.0, 0.0); // Translate back to the original position
        windmillAngles[i] += (i + 1) * 0.5f;
        if (windmillAngles[i] >= 360.0f) {
            windmillAngles[i] -= 360.0f;
        }

        // Draw a single windmill blade
        drawWind();

    }

    glPopMatrix();
}


void Timer(int value)
{
    // Request redisplay to continuously update the windmill's rotation
    glutPostRedisplay();

    // Set a timer to call itself again after a certain interval
    glutTimerFunc(30, Timer, 0);
}


static GLfloat w = 0.0;
static GLfloat x = 0.0;
static GLfloat y = 0.0;
static GLfloat z = 0.0;
static GLfloat planeSpeed = 1.5;


void drawplane() {
    /* Draw a plane */

    glPushMatrix();
    glTranslatef(x, y, 0.0);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(245.0, 230.0);
    glVertex2f(245.0, 240.0);
    glVertex2f(215.0, 230.0);

    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(244.0, 228.0);
    glVertex2f(244.0, 235.0);
    glVertex2f(228.0, 235.0);

    glEnd();

    // Update the plane's position based on speed


    // Check if the plane has reached the X-coordinate limits and reset if necessary to keep it within the screen
    if (x > -200) {
        x -= planeSpeed;
    }
    else if (x == -200) {
        x = -200;
    }

    // Check if the plane has reached the Y-coordinate limits and reset if necessary to keep it within the screen
    if (y > -180) {
        y -= 2;
    }
    else if (y == -180) {
        y = -180;
    }

    glPopMatrix();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("BSCS 514 Lab #8");
    /* The `init()` function is initializing the OpenGL environment. It sets the clear color to light
    blue, sets the projection matrix to an orthographic view with the coordinate range of (0, 0) to
    (250, 250), and sets the modelview matrix to the identity matrix. */
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(30, Timer, 1);
    glutMainLoop();

}



void drawlandscape()
{
    /* Draw a box of grass */
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(250.0, 0.0);
    glColor3f(0.0, 0.9, 0.0);
    glVertex2f(250.0, 50.0);
    glColor3f(0.0, 0.8, 0.0);
    glVertex2f(0.0, 50.0);
    glColor3f(0.0, 0.7, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();

    /* An attempt at a few snow covered mountains */

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.6);
    glVertex2f(250.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(200.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(150.0, 50.0);

    //glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(200.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(150.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(100.0, 50.0);

    glColor3f(0.0, 0.0, 0.7);
    glVertex2f(150.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(100.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(50.0, 50.0);

    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(100.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(50.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(0.0, 50.0);

    glEnd();

    /* Draw the body of a windmill */
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.0);
    glVertex2f(145.0, 50.0);
    glVertex2f(135.0, 100.0);
    glVertex2f(115.0, 100.0);
    glVertex2f(105.0, 50.0);
    glEnd();

}

void init()
{
    glClearColor(0.8f, 0.8f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 250.0, 0.0, 250.0);

    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 250.0, 0.0, 250.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}





void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
}