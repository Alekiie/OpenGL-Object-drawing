#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

void drawCup() {
    glColor3f(0.0, 0.0, 0.5); // Navy Blue

    // Draw the body of the cup (cylinder)
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 360; i += 10) {
        float theta = i * (M_PI / 180.0);
        float x = 0.5 * cos(theta);
        float y = 0.5 * sin(theta);
        glVertex3f(x, y, 0.0);        // Bottom point
        glVertex3f(x, y, 1.0);        // Top point
    }
    glEnd();

    // Draw the base of the cup (circle)
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, 0.0, 0.0); // Center of the circle
    for (int i = 0; i <= 360; i += 10) {
        float theta = i * (M_PI / 180.0);
        float x = 0.5 * cos(theta);
        float y = 0.5 * sin(theta);
        glVertex3f(x, y, 0.0); // Points on the circle
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);

    drawCup();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Floating Navy Blue Cup");
    glEnable(GL_DEPTH_TEST);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
