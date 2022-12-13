
#include<GL/glu.h>
#include<GL/glut.h>


void MyInit()
{
    glClearColor(0,0,0,1);
    glColor3f(1,0,0);

}
void Draw()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);

    glBegin(GL_POLYGON);
        glVertex2f(-0.5,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,-0.5);
        glVertex2f(-0.5,-0.5);
    glEnd();

    glFlush();

}
int main(int c,char **v)
{
    glutInit(&c,v);
    glutInitWindowPosition(250,50);
    glutInitWindowSize(600,600);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Basic program");

    void MyInit();

    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;
}
