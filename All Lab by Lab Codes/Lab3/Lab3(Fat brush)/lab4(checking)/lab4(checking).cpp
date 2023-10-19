#include <gl/glut.h>
#include<gl/glu.h>
#include<gl/gl.h>

#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4

int windowWidth = 800;
int windowHeight = 600;

float red = 1.0, green = 1.0, blue = 1.0;
bool isDrawing = false;
void processMenuEvents(int option);


void drawColorMenu() {
    glutCreateMenu(processMenuEvents);
    glutAddMenuEntry("Red", RED);
    glutAddMenuEntry("Green", GREEN);
    glutAddMenuEntry("Blue", BLUE);
    glutAddMenuEntry("White", WHITE);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void processMenuEvents(int option) {
    switch (option) {
    case RED:
        red = 1.0; green = 0.0; blue = 0.0;
        break;
    case GREEN:
        red = 0.0; green = 1.0; blue = 0.0;
        break;
    case BLUE:
        red = 0.0; green = 0.0; blue = 1.0;
        break;
    case WHITE:
        red = 1.0; green = 1.0; blue = 1.0;
        break;
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isDrawing = true;
        glColor3f(red, green, blue);
        glPointSize(5.0);
        glBegin(GL_POINTS);
        glVertex2f((x - windowWidth / 2) / (float)windowWidth,
            -(y - windowHeight / 2) / (float)windowHeight);
        glEnd();
        glFlush();
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        isDrawing = false;
    }
}

void mouseMotion(int x, int y) {
    if (isDrawing) {
        glColor3f(red, green, blue);
        glPointSize(5.0);
        glBegin(GL_POINTS);
        glVertex2f((x - windowWidth / 2) / (float)windowWidth,
            -(y - windowHeight / 2) / (float)windowHeight);
        glEnd();
        glFlush();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Freehand Drawing");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(renderScene);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    drawColorMenu();
    glutMainLoop();
    return 0;
}
