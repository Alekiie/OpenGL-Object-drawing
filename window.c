#include <GL/glut.h>
#include <GL/glu.h>

void myInit()
{
}
void Draw()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0, 0);

    // glPointSize(5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glEnd();

    // clear everyting on the buffer and reflect new drawing
    glFlush();
}
int main(int argC, char **argV)
{

    glutInit(&argC, argV);

    // initial window position

    // size of the window

    // create the window
    glutCreateWindow("Basic OpenGL Window.");
    myInit();

    // set up callback functions for drawing and handling events
    glutDisplayFunc(Draw);

    glutMainLoop();
    return 0;
}