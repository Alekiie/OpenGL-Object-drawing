#include <GL/glut.h>
#include <math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set color using glColor3f with RGB values ranging from 0.0 to 1.0
    glColor3f(0.0, 1.0, 1.0);

    // Draw the triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);

    // Create a window with the title "Triangle"
    glutCreateWindow("Triangle");

    // Set the display function
    glutDisplayFunc(display);

    // Set up the orthographic projection matrix
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    // Set the clear color
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Enter the GLUT event processing loop
    glutMainLoop();

    // Return 0 to indicate successful execution
    return 0;
}
