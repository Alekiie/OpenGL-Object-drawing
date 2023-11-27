#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0, 0); // Set color to red

    // glPointSize(10);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5); // Bottom-left vertex
    glVertex2f(0.5, -0.5);  // Bottom-right vertex
    glVertex2f(0.5, 0.5);   // Top-right vertex
    glVertex2f(-0.5, 0.5);  // Top-left vertex
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Rectangle");
    glutDisplayFunc(display);

    // Set up the coordinate system
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glutMainLoop();
    return 0;
}

