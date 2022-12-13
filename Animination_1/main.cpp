#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
#define w 400
#define h 400
float x_pos = -40;
void MyInit()
{
    glClearColor(1,1,1,1);
    glColor3f(0,1,0);
    glPointSize(3);
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

void Draw_boat()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);

        glVertex2f(x_pos+20,10);
        glVertex2f(x_pos+30,-15);
        glVertex2f(x_pos+70,-15);
        glVertex2f(x_pos+80,10);

    glEnd();
    glFlush();

    glutSwapBuffers();
}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    x_pos += 0.40;
    if(x_pos>=100)
    {
        x_pos= -40;
    }
}
int main(int arv,char **argc)
{
    glutInit(&arv,argc);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(100,50);
    glutCreateWindow("Animination");
    glutDisplayFunc(Draw_boat);
    MyInit();
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}
