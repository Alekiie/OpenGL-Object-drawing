#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

void drawCircleOutline(float centerX, float centerY, float radius, float colorR, float colorG, float colorB) {
    glColor3f(colorR, colorG, colorB);

    glBegin(GL_LINE_LOOP);

    int numSegments = 100;
    for (int i = 0; i < numSegments; ++i) {
        float angle = i * (2.0 * M_PI / numSegments);
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

void setStencil(float centerX, float centerY, float radius) {
    glClear(GL_STENCIL_BUFFER_BIT);

    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_ALWAYS, 1, 1);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    drawCircleOlClear(GL_STENCIL_BUFFER_BIT);

    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_ALWAYS, 1, 1);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    drawCircle();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set stencil buffer for the first circle (magenta)
    setStencil(0.0, 0.5, 1.0);

    // Draw the second circle outline (cyan) only where stencil buffer is 1 (inside the first circle)
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_EQUAL, 1, 1);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    drawCircleOutline(0.5, 0.0, 1.0, 0.0, 1.0, 1.0);
    drawCircleOutline(-0.5, 0.0, 1.0, 0.0, 1.0, 0.0);
    drawCircleOutline(-0.5, 0.5, 1.0, 0.0, 0.0, 1.0);

    glDisable(GL_STENCIL_TEST);

    // Draw the first circle outline (magenta) without stencil testing
    drawCircleOutline(0.0, 0.5, 1.0, 1.0, 0.0, 1.0);

    glutSwapBuffers();
}



void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5); // Adjusted orthographic view
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_STENCIL);
    glutCreateWindow("Intersecting Circles at Center");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background

    glutMainLoop();
    return 0;
}
