#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1.0, 0);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glEnd();

    glFlush();
}
int main(int argC, char **argV)
{
    glutInit(&argC, argV);
    glutCreateWindow("Another Trial ");
    glutDisplayFunc(display);

    // coordinate system
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);


    glutMainLoop();

    return 0;
}