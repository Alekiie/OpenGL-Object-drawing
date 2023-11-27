#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

void drawMoon() {
    glColor3f(1.0, 1.0, 1.0); // White color for the moon

    // Draw a circle representing the full moon
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0); // Center of the circle
    for (int i = 0; i <= 360; i += 10) {
        float theta = i * (M_PI / 180.0);
        float x = 0.2 * cos(theta);
        float y = 0.2 * sin(theta);
        glVertex2f(x, y); // Points on the circle
    }
    glEnd();
}

void drawStars() {
    glColor3f(1.0, 1.0, 1.0); // White color for the stars

    // Draw random points to represent stars
    glPointSize(2.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 100; ++i) {
        float x = (float)rand() / RAND_MAX * 2.0 - 1.0;
        float y = (float)rand() / RAND_MAX * 2.0 - 1.0;
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawStars(); // Draw stars
    drawMoon();  // Draw the moon

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set up a 2D orthographic view
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Night Sky with Stars and Moon");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background

    glutMainLoop();
    return 0;
}
