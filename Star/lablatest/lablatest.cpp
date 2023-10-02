#include <iostream>
#include <gl/glut.h>


void starmotif() {
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	glVertex2f(3, 3);
	glVertex2f(0, 8);
	glVertex2f(-3, 0);
	glVertex2f(-2, -1);
	glVertex2f(0, 5);
	glVertex2f(2, 3);
	glVertex2f(3, 3);
	glEnd();
	glPopMatrix();

}

float angle = 0;
void drawstar() {
	for (int i = 0; i < 4; i++) {
		glRotatef(angle + 90, 0, 0, 1);
		starmotif();
	}
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	starmotif();	
	drawstar();
	glFlush();
};

void init() {
	glClearColor(0.8f, 0.8f, 0.8f, 0);
	glEnable(GL_COLOR_MATERIAL);
}
void reshape(int w, int v) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)v);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20, 20, -20, 20);
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

}





