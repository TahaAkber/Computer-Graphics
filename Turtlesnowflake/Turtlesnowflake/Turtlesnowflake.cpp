#include <gl/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

int screenWidth = 640;
int screenHeight = 440;

class Canvas {
public:
	float x, y;
	float angle;
	Canvas() {
		this->x = 225;
		this->y = 200;
	}
	void turnTo(float angle) {
		this->angle = angle;
	}
	void turn(float angle) {
		this->angle += angle;
	}
	void lineTo(float x, float y) {
		float t_x = x; float t_y = y;
		glColor3f(1.0, 0.0, 0.0);
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex2f(this->x, this->y);
		glVertex2f(x, y);
		glEnd();
		glFlush();
		moveTo(t_x, t_y);
	}
	void moveTo(float x, float y) {
		this->x = x;
		this->y = y;

	}


	void forward(float dist, int isVisible) {
		const float RadPerDeg = 0.017453393;
		float x = this->x + dist * cos(RadPerDeg * this->angle);
		float y = this->y + dist * sin(RadPerDeg * this->angle);
		if (isVisible >= 1) {
			lineTo(x, y);

		}
		else {
			moveTo(x, y);
		}
	}

};

float L = 1.0;
Canvas cvs;

void flakeMotif(float L) {
	cvs.moveTo(0.0, 0.1 * L);
	cvs.turnTo(0);
	cvs.forward(2 * L, 1);
	cvs.turn(60);
	cvs.forward(1 * L, 1);
	cvs.turn(270);
	cvs.forward(0.2 * L, 1);
	cvs.turn(270);
	cvs.forward(0.9 * L, 1);
	cvs.turn(120);
	cvs.forward(1 * L, 1);
	cvs.turn(60);
	cvs.forward(0.9 * L, 1);
	cvs.turn(270);
	cvs.forward(0.2 * L, 1);
	cvs.turn(270);
	cvs.forward(0.8 * L, 1);
	cvs.turn(120);
	cvs.forward(1 * L, 1);
	cvs.turn(330);
	cvs.forward(0.2 * L, 1);
	cvs.turn(30);
}
void drawFlake() {
	float angle = 0;
	for (int i = 0; i < 4; i++) {
		flakeMotif(1);
		glScalef(1.0, -1.0, 0);
		flakeMotif(1);
		glScalef(1.0, -1.0, 0);
		glRotatef(angle + 90, 0, 0, 1);
	};
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawFlake();
	float angle = 0;
	for (int i = 0; i < 8; i++) {
		flakeMotif(1);
		glScalef(1.0, -1.0, 0);
		flakeMotif(1);
		glScalef(1.0, -1.0, 0);
		glRotatef(angle + 45, 0, 0, 1);
	}

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("SnowFlake");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}