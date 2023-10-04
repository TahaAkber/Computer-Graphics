// Including the necessary libraries for OpenGL and mathematical operations.
#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Using a namespace to prevent potential naming conflicts and to logically group
// associated functionalities.
namespace GoldenRectangleUtils {

    /**
    * @class GoldenRectangle
    * Represents and manipulates a golden rectangle using the golden ratio.
    */
    class GoldenRectangle {
    private:
        // Constants for the golden ratio and initial rectangle dimensions.
        const double GOLDEN_RATIO = 1.61803398875;
        const double INITIAL_WIDTH = 1.0;
        const double INITIAL_HEIGHT = 1.0 / GOLDEN_RATIO;

        // Variables for the current rectangle dimensions.
        double width;
        double height;

    public:
        /**
        * Constructs a golden rectangle with the initial dimensions.
        */
        GoldenRectangle() {
            width = INITIAL_WIDTH;
            height = INITIAL_HEIGHT;
        }

        /**
        * Returns the current width of the golden rectangle.
        *
        * @return double The width of the rectangle.
        */
        double getWidth() const { return width; }

        /**
        * Returns the current height of the golden rectangle.
        *
        * @return double The height of the rectangle.
        */
        double getHeight() const { return height; }

        /**
        * Updates the dimensions of the golden rectangle based on the golden ratio.
        */
        void updateDimensions() {
            double newWidth = height * GOLDEN_RATIO;
            double newHeight = width / GOLDEN_RATIO;

            width = newWidth;
            height = newHeight;
        }
    };

    /**
    * Renders a golden rectangle using OpenGL.
    */
    void renderGoldenRectangle() {
        // Create a golden rectangle object.
        GoldenRectangle rectangle;

        // Set up the OpenGL window.
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

        // Set up the rectangle color and position.
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, 0.0);

        // Render the golden rectangle.
        glBegin(GL_POLYGON);
        glVertex2f(-rectangle.getWidth() / 2, -rectangle.getHeight() / 2);
        glVertex2f(rectangle.getWidth() / 2, -rectangle.getHeight() / 2);
        glVertex2f(rectangle.getWidth() / 2, rectangle.getHeight() / 2);
        glVertex2f(-rectangle.getWidth() / 2, rectangle.getHeight() / 2);
        glEnd();

        // Update the rectangle dimensions based on the golden ratio.
        rectangle.updateDimensions();

        // Render the updated golden rectangle.
        glBegin(GL_POLYGON);
        glVertex2f(-rectangle.getWidth() / 2, -rectangle.getHeight() / 2);
        glVertex2f(rectangle.getWidth() / 2, -rectangle.getHeight() / 2);
        glVertex2f(rectangle.getWidth() / 2, rectangle.getHeight() / 2);
        glVertex2f(-rectangle.getWidth() / 2, rectangle.getHeight() / 2);
        glEnd();

        // Flush the OpenGL buffer and display the golden rectangle.
        glFlush();
    }

    /**
    * Initializes the OpenGL window and starts the rendering loop.
    */
    void startRendering() {
        // Initialize the GLUT library and create the window.
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(800, 800);
        glutCreateWindow("Golden Rectangle");

        // Set the display function to render the golden rectangle.
        glutDisplayFunc(renderGoldenRectangle);

        // Start the GLUT main loop.
        glutMainLoop();
    }

    void renderGoldenRectangles() {
        // Set up the OpenGL window.
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

        // Initialize the position for the first rectangle.
        float x = 0.0;
        float y = 0.0;

        for (int i = 0; i < 10; ++i) {  // Change 10 to the number of rectangles you want
            // Create a golden rectangle object.
            GoldenRectangle rectangle;

            // Set up the rectangle color and position.
            glColor3f(0.0, 0.0, 0.0);
            glTranslatef(x, y, 0.0);

            // Render the golden rectangle.
            glBegin(GL_POLYGON);
            glVertex2f(-rectangle.getWidth() / 2, -rectangle.getHeight() / 2);
            glVertex2f(rectangle.getWidth() / 2, -rectangle.getHeight() / 2);
            glVertex2f(rectangle.getWidth() / 2, rectangle.getHeight() / 2);
            glVertex2f(-rectangle.getWidth() / 2, rectangle.getHeight() / 2);
            glEnd();

            // Update the position for the next rectangle.
            x += rectangle.getWidth() + 0.5;  // Adjust the spacing between rectangles

            // Update the rectangle dimensions based on the golden ratio.
            rectangle.updateDimensions();
        }

        // Flush the OpenGL buffer and display the golden rectangles.
        glFlush();
    }

    // ...
    }

    int main(int argc, char** argv) {
        // Initialize the GLUT library and start rendering the sequence of golden rectangles.
        glutInit(&argc, argv);
        GoldenRectangleUtils::startRendering();

    }