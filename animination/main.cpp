#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
#define w 100
#define h 50

float x_pos = -10;

void MyInit()
{
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(3);
    gluOrtho2D(0,100,0,50);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex2f(0,25);

    glColor3f(1,1,0);
    glVertex2f(100,25);

    glColor3f(0,0,1);
    glVertex2f(100,50);

    glColor3f(0.5,1,0.9);    glVertex2f(0,50);

    glEnd();
    glFlush();
    glColor3f(0,0.3,1);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,0);
    glVertex2f(100,25);
    glVertex2f(0,25);
    glEnd();
    glFlush();

    glColor3f(1,0.5,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(x_pos+20,5);
    glVertex2f(x_pos+30,5);
    glVertex2f(x_pos+35,10);
    glVertex2f(x_pos+15,10);

    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glVertex2f(x_pos+23,10);
    glVertex2f(x_pos+25,15);
    glVertex2f(x_pos+27,10);
    glEnd();
    glFlush();

    glPointSize(5);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex2i(x_pos+5,3);
    glVertex2i(x_pos+25,4);
    glVertex2i(x_pos+23,13);
    glEnd();
    glFlush();
    glutSwapBuffers();

}
    //float x_pos = -40;
void Timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,Timer,0);
    x_pos = x_pos + 0.30;
    if(x_pos >= 90)
    {


    x_pos = -10;
    }
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB |GLUT_DOUBLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,480);
    glutCreateWindow("Animination");
    MyInit();
    glutDisplayFunc(Draw);
    glutTimerFunc(0,Timer,0);


    glutMainLoop();
    return 0;
}
