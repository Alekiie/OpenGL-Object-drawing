#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

void drawCircleOutline(float centerX, float centerY, float radius, float colorR, float colorG, float colorB)
{
    glColor3f(colorR, colorG, colorB);

    glBegin(GL_LINE_LOOP);

    int numSegments = 100;
    for (int i = 0; i < numSegments; ++i)
    {
        float angle = i * (2.0 * M_PI / numSegments);
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the first circle outline (magenta) without stencil testing
    drawCircleOutline(0.0, 0.0, 0.5, 1.0, 0.0, 1.0);

    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);

    // Create a window with the title "Circle"
    glutCreateWindow("Circle");

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
