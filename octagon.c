#include <GL/glut.h>
#include <math.h>


#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set color using glColor3f with RGB values ranging from 0.0 to 1.0
    glColor3f(0.0, 1.0, 1.0);

     glBegin(GL_POLYGON);

    // Calculate the vertices of the octagon
    float radius = 0.5;
    for (int i = 0; i < 8; ++i)
    {
        float angle = i * (2.0 * M_PI / 8);
        float x = 0.5 * cos(angle);
        float y = 0.5 * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);

    // Create a window with the title "Triangle"
    glutCreateWindow("OCTAGON");

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
