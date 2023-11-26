#include <GL/glut.h>

GLfloat T = 0;

void spin()
{
    T += 1;
    if (T > 360)
        T = 0;
    glutPostRedisplay();
}
void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{

    glBegin(GL_POLYGON);
    glVertex3f(A[0], A[1], A[2]);
    // similar with above
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);

    glEnd();
};
void Cube(
    GLfloat V0[],
    GLfloat V1[],
    GLfloat V2[],
    GLfloat V3[],
    GLfloat V4[],
    GLfloat V5[],
    GLfloat V6[],
    GLfloat V7[])
{
    glColor3f(1.0, 0, 0); // front
    Face(V0, V1, V2, V3);

    glColor3f(0, 0, 1.0); // back
    Face(V4, V5, V6, V7);

    glColor3f(1.0, 0, 1.0); // left
    Face(V0, V3, V7, V4);

    glColor3f(0.5, 0.5, 0.5); //right
    Face(V1, V2, V6, V5);

    glColor3f(0, 1.0, 1.0); //top
    Face(V0, V1, V5, V4);

    glColor3f(0.5, 1.0, 0.5); //bottom
    Face(V3, V2, V6, V7);


}
void display()
{
    GLfloat V[8][3] = {
        // front
        {-0.5, 0.5, 0.5},
        {0.5, 0.5, 0.5},
        {0.5, -0.5, 0.5},
        {-0.5, -0.5, 0.5},
        // back
        {-0.5, 0.5, -0.5},
        {0.5, 0.5, -0.5},
        {0.5, -0.5, -0.5},
        {-0.5, -0.5, -0.5},
    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(T, 1, 1, 1);
    Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
    glColor3f(0, 1.0, 0.5);
    glEnable(GL_DEPTH_TEST);

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Rotating Cube");
    glutDisplayFunc(display);
    glutIdleFunc(spin);

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glutMainLoop();
    return 0;
}