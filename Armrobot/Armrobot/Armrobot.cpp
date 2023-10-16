#include <gl/glut.h>
#include <cmath>
#include <math.h>
#include <cstdlib>


void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init() {
    glClearColor(0, 0, 0, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void drawarm() {
    glBegin(GL_POLYGON);
    glVertex2f(2, 2);
    glVertex2f(2, 0);
    glVertex2f(3, 0);
    glVertex2f(3, 2);
    glEnd();
}
void drawhead() {
    glBegin(GL_LINES);
    glVertex2f(2, 2);
    glVertex2f(2, 0);
    glVertex2f(15, 0);
    glVertex2f(15, 2);
    glVertex2f(2, 2);
    glVertex2f(15, 2);
    glVertex2f(2, 0);
    glVertex2f(15, 0);
    glEnd();
}
void drawbody() {
    glBegin(GL_LINES);
    glVertex2f(2, 6);
    glVertex2f(4, 0);
    glVertex2f(4, 0);
    glVertex2f(2, -6);
    glVertex2f(2, -6);
    glVertex2f(8, -6);
    glVertex2f(8, -6);
    glVertex2f(6, 0);
    glVertex2f(6, 0);
    glVertex2f(8, 6);
    glVertex2f(8, 6);
    glVertex2f(2, 6);

    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(4, 4, 0);
    drawbody();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 10, 0);
    drawhead();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 8, 0);
    drawarm();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12.5, 8, 0);
    drawarm();
    glPopMatrix();

    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Robot");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);

   

    glutMainLoop();
    return 0;
}