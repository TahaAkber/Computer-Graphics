#include <gl/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

int screenWidth = 640;
int screenHeight = 480;

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
		glColor3f(1.0, 1.0, 0.0);
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


float increment = 3;
Canvas cvs;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	// 3.5.1 Drawing Turtles Figure
	
	/*float l = 200.0;
	for (int j = 0; j < 4; j++) {

		for (int i = 0; i < 4; i++) {
			cvs.forward(l, 1);
			cvs.turn(90);
			cvs.forward(l, 1);
			cvs.turn(90);
			cvs.forward(l, 1);
			cvs.turn(90);
		}
		l -= 40;
	}*/


	// 3.5.1 
	//float l = 200.0;
	//cvs.forward(l, 1);
	//cvs.turn(120);
	//cvs.forward(l / 2, 1);
	//cvs.turn(120);
	//cvs.forward(l / 2, 1);
	//cvs.turn(240);
	//cvs.forward(l / 2, 1);
	//cvs.turn(240);
	//cvs.forward(l / 2, 1);
	//cvs.turn(120);
	//cvs.forward(l / 2, 1);
	//cvs.turn(120);
	//cvs.forward(l, 1);


	// 3.5.2 Drawing a well-known logo
	/*float l = 100.0;
	cvs.forward(l, 1);
	cvs.turn(320);
	cvs.forward(l, 1);
	cvs.turn(220);
	cvs.forward(l, 1);
	cvs.turn(320);
	cvs.forward(l, 1);

	cvs.turn(40);

	cvs.forward(l, 1);
	cvs.turn(40);
	cvs.forward(l, 1);
	cvs.turn(140);
	cvs.forward(l, 1);
	cvs.turn(40);
	cvs.forward(l * 2, 1);

	cvs.turn(90);
	cvs.forward(l, 1);
	cvs.turn(100);
	cvs.forward(l, 1);
	cvs.turn(80);
	cvs.forward(l, 1);

	cvs.forward(100, 0);*/

	glFlush();
}

// 3.5.3 Driving the turtle with strings
void myKeys(unsigned char key, int x, int y) {
	int L = 30;
	switch (key) {
	case 'f':
		cvs.forward(L, 1);
		break;
	case 'l':
		cvs.turn(60);
		break;
	case 'r':
		cvs.turn(-60);
		break;
	}

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Exercise 3.5.1-3.5.3");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display);
	glutKeyboardFunc(myKeys);

	glutMainLoop();
	return 0;
}