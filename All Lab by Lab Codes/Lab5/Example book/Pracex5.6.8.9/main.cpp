#include <gl/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

int screenWidth = 800;
int screenHeight = 400;

class Canvas {
public:
	float x, y;
	float angle;
	Canvas() {
		this->x = 80;
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
		glColor3f(0.5, 0.5, 0.5);
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
Canvas cvs;
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1,1);
	
	float l = 70.0;
	for (int i = 0; i < 3; i++) {
		cvs.forward(l, 1);
		cvs.turn(90);
		cvs.forward(l - 20, 1);
		cvs.turn(90);
		cvs.forward(l / 2, 1);
		cvs.turn(270);
		cvs.forward(l / 2, 1);
		cvs.turn(270);
		cvs.forward(l - 20, 1);
		cvs.turn(270);
		cvs.forward(15, 1);
		cvs.turn(90);
		cvs.forward(25, 1);
		cvs.turn(90);
		cvs.forward(15, 1);
		cvs.turn(270);
		cvs.forward(l - 20, 1);
		cvs.turn(270);
		cvs.forward(l / 2, 1);
		cvs.turn(270);
		cvs.forward(l / 2, 1);
		cvs.turn(90);
		cvs.forward(l - 20, 1);
		cvs.turn(90);
		cvs.forward(l, 1);
	}

	glFlush();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Week 5");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}