#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

void draw8CornerStar() {
    glColor3f(1.0, 1.0, 0.0); // Yellow color for the star

    // Draw 8 ovals to create the star
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0); // Center of the star

    for (int i = 0; i <= 8; ++i) {
        float angle = i * (M_PI / 4.0); // Angle for each oval
        float x = 0.5 * cos(angle);
        float y = 0.5 * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    draw8CornerStar(); // Draw the 8-corner star using ovals

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
    glutCreateWindow("8-Corner Star with Ovals");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background

    glutMainLoop();
    return 0;
}
