#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

void drawStar()
{
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 8; ++i)
    {
       float angle1 = i * (2.0 * M_PI / 8);
        float x1 = 0.5 * cos(angle1);
        float y1 = 0.5 * sin(angle1);

        float angle2 = (i + 4) * (2.0 * M_PI / 8); // Connect points with the opposite ones
        float x2 = 0.5 * cos(angle2);
        float y2 = 0.5 * sin(angle2);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}
void reshape(int height, int width)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set up a 2D orthographic view
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawStar();
    glutSwapBuffers();
}
int main(int argC, char **argsV)
{
    glutInit(&argC, argsV);
    glutCreateWindow("An 8 corner start sample");
    glutDisplayFunc(display);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glutMainLoop();
    return 0;
}