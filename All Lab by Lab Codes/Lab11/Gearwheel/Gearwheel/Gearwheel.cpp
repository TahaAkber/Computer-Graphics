// Gearwheel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>;
#include <string>
#include <string.h>
#include <GL/glut.h>

void tooth0() {
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.6, 0.8);
    glVertex2f(0.0, 1.0);
    glEnd();
}
void tooth1(double r) {
    double rad = 6.0 * 3.142 / 180;
    double sin6 = r * sin(rad), cos6 = r * cos(rad);
    glPushMatrix();
    glTranslatef(cos6, -sin6, 0.0);
    glScalef(2.0 * sin6, 2.0 * sin6, 1.0);
    tooth0();
    glPopMatrix();
}
void gear(double r) {
    glPushMatrix();
    for (int i = 0; i <= 30; i++) {
        tooth1(r);
        glRotatef(12.0, 0.0, 0.0, 1.0);
    }
    glPopMatrix();
}
//void move() {
//    float speed = 0.0001;
//    static int oldTime = clock(), newTime;
//    newTime = clock();
//
//   /* double deg;
//    deg += (newTime - oldTime) * speed;*/
//
//    oldTime = newTime;
//    glutPostRedisplay();
//}
float angle = 0.0;
int oldTime = 0;
void move() {
    // Increase the speed for faster rotation
    float speed = 2.0;

    // Get the current time
    int newTime = glutGet(GLUT_ELAPSED_TIME);

    // Calculate the time difference
    int timeDiff = newTime - oldTime;

    // Update the angle based on time and speed
    angle += speed * timeDiff / 1000.0; // Divide by 1000 to convert milliseconds to seconds

    // Update the oldTime for the next frame
    oldTime = newTime;

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glColor3f(1.0, 0.0, 0.0);
        glRasterPos2f(-8, 8);
        std::string name = "A Wheel Gear";
        for (int i = 0; i < name.length(); i++) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, name[i]);
        }

    glPushMatrix();  // Push the current transformation matrix onto the stack
    glRotatef(angle, 0.0, 0.0, 1.0);  // Apply the rotation
    gear(5);
    glPopMatrix();  // Pop the transformation matrix

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Gear Wheels");
    glutDisplayFunc(display);
    glutIdleFunc(move);

    oldTime = glutGet(GLUT_ELAPSED_TIME);

    glutMainLoop();

    
}