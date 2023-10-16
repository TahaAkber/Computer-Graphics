#include <GL/glut.h>
#include <cmath>
#include <math.h>
#include <cstdlib>

// Add global variables for the menu
int menu_id;
int value = 0;
const double PI = 3.142;
const int numVertices = 40;
float carX = -10.0; // Initial car position
bool pause = false;  
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

void drawArc(float centerX, float centerY, float radius, float startAngle, float endAngle) {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= numVertices; ++i) {
        float angle = startAngle + (endAngle - startAngle) * static_cast<float>(i) / numVertices;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void menu(int num) {
    if (num == 0) {
        // Handle "Start" menu item
        value = 1;
        carX = -10.0;
        pause = false;

    }
    else if (num == 1) {
        // Handle "Restart" menu item
        carX = 5.0; // Reset the car position
        value = 0;
        pause = false;
    }
    else if (num == 2) {
        // Handle "Pause" menu item
        pause = !pause;
    }
    else if (num == 3) {
        // Handle "Exit" menu item
        exit(0);
    }
    glutPostRedisplay();
}
void drawCircle(float centerX, float centerY, float radius, int numVertices, bool semi) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; ++i) {
        float angle;
        if (semi) angle = PI * static_cast<float>(i) / numVertices;
        else angle = 2.0 * PI * static_cast<float>(i) / numVertices;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawWheel(float x, float y, float radius) {
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    drawCircle(0, 0, radius, 1000, false);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPointSize(10.0);

    glPushMatrix();
    glTranslatef(carX, 0.0, 0.0);

    drawArc(4.0, 0.0, 4.0, 0.0, 90.0 * PI / 180.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.0, 4);
    glVertex2f(2.0, 0);
    glEnd();

    drawArc(-4.0, 0.0, 4.0, 180.0 * PI / 180.0, 90.0 * PI / 180.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-2.0, 4);
    glVertex2f(-2.0, 0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-8.0, 0);
    glVertex2f(8.0, 0);
    glEnd();

    drawCircle(0.0, 4, 4, 1000, true);

    drawWheel(-4, 0, 1.3);
    drawWheel(4, 0, 1.3);

    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    if (!pause && carX <= 10) {
        carX += 0.1; // Move the car to the right
    }// Move the car to the right
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Animated Car");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutTimerFunc(100, update, 0); // Start the animation

    // Create the context menu
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Start", 0);
    glutAddMenuEntry("Restart", 1);
    glutAddMenuEntry("Pause", 2); // Add "Pause" menu item
    glutAddMenuEntry("Exit", 3);

    // Attach the menu to the right mouse button
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}


