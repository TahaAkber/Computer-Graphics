#include<Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <iostream>
#include <math.h>

class GlintPoint {
public:
	GLint x, y;

};

class Point2 {
public:
	float x, y;
	void set(float dx, float dy) { x = dx; y = dy; }
	void set(Point2& p) { x = p.x; y = p.y; }
	Point2(float xx, float yy) { x = xx; y = yy; }
	Point2() { x = y = 0; }
};

Point2 currPos;
Point2 CP;

void moveTo(Point2 p) {
	CP.set(p);
}
void lineTo(Point2 p) {
	glBegin(GL_LINES);
	glVertex2f(CP.x, CP.y);
	glVertex2f(p.x, p.y);
	glEnd();
	glFlush();
	CP.set(p);
}
void myInit(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);

}
void rosette(int N, float radius) {
	Point2* pointlist = new Point2[N];
	GLfloat theta = (2.0f * 3.1415926536) / N;
	//calculating points
	for (int c = 0; c < N; c++) {
		// calculating coordinates of the points
		pointlist[c].set(radius * sin(theta * c),
			radius * cos(theta * c));
		for (int i = 0; i < N ; i++) {
			for (int j = 0; j < N; j++)
			{
				moveTo(pointlist[i]);
				lineTo(pointlist[j]);
			}
		}
	}
};
	void render() {
		glClear(GL_COLOR_BUFFER_BIT);
		glViewport(10, 10, 640, 480);
		rosette(8, .66f);
	}
	void main(int argc, char** argv) {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glutInitWindowSize(640, 480);
		glutCreateWindow("Rosette");
		glutDisplayFunc(render);

		myInit();
		glutMainLoop();
	}