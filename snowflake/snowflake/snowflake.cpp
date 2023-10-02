#include <iostream>
#include <GL/glut.h>

void snowflake() {
    glPushMatrix();
   
    glBegin(GL_LINE_STRIP);
    glVertex2f(0, 5);
    glVertex2f(20, 5);
    glVertex2f(30, 25);
    glVertex2f(35, 18);
    glVertex2f(25, 5);
    glVertex2f(30, 5);
    glEnd();
    glPopMatrix();
}

void drawflake() {
    glPushMatrix();
    glTranslatef(0, 5, 0);
    snowflake();
    glTranslatef(0, 0, 0);
    glScalef(1, -1, 1);
    glTranslatef(0, -5, 0);
    snowflake();
    glTranslatef(0, 0, 0);

    glTranslatef(-10, 0, 0);
    snowflake();
    glTranslatef(0, 0, 0);

    glTranslatef(0, 5, 0);
    glScalef(1, -1, 1);
    snowflake();
    glTranslatef(0, 0, 0);

    glTranslatef(-10, 5, 0);
    glScalef(1, -1, 1);
    snowflake();
    glTranslatef(0, 0, 0);

    glTranslatef(0, 5, 0);
    glScalef(1, -1, 1);
    snowflake();
    glTranslatef(0, 0, 0);

    glPopMatrix();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
   
    glTranslatef(0, 5, 0);
    snowflake();
    glTranslatef(0, 0, 0);
    glScalef(1, -1, 1);
    glTranslatef(0, -5, 0);
    glRotatef(0, 1, 0, 0);
    snowflake();
    glTranslatef(0, 0, 0);

    glTranslatef(-10, 0, 0);
    glRotatef(0, 1, 0, 0);
    snowflake();
    glTranslatef(0, 0, 0);

    glTranslatef(0, 5, 0);
    glScalef(1, -1, 1);
    snowflake();
    glTranslatef(0, 0, 0);

    glTranslatef(-10, 5, 0);
    glScalef(1, -1, 1);
    snowflake();
    glTranslatef(0, 0, 0);

    glTranslatef(0, 5, 0);
    glScalef(1, -1, 1);
    snowflake();
    glTranslatef(0, 0, 0);

    glTranslatef(0, -5, 0);
    glRotatef(180, 0, 1, 0);
    drawflake();
    glTranslatef(0, 0, 0);

    glTranslatef(0, 30, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(1, 1, -1);
    drawflake();
    glTranslatef(0, 0, 0);


    glTranslatef(-40, 15, 0);
    glRotatef(180, 0, 0, 1);
    glScalef(1, 1, -1);
    drawflake();
    glTranslatef(0, 0, 0);


    glFlush();
}

void init() {
    glClearColor(0.8f, 0.8f, 0.8f, 0);
    glEnable(GL_COLOR_MATERIAL);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-70, 70, -70, 70);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(200, 100);

    glutCreateWindow("Window Shapes");
    glutDisplayFunc(display);
    init();
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
