#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
#define w 600
#define h 600

int obj[3][3]={{10,100,45},{10,10,50},{1,1,1}};
int c[3][3];
void MyInit()
{

    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(3);
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void axes()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,0);
    glBegin(GL_POINTS);
    for(int i=-300;i<300;i++)
    {
        glVertex2f(i,0);
        glVertex2f(0,i);
    }
    glEnd();
    glFlush();

}
void MyObject()
{
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f(10,10);
    glVertex2f(100,10);
    glVertex2f(40,50);
    glEnd();
    glFlush();

}
void Draw()
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(c[0][0],c[1][0]);
    glVertex2f(c[0][1],c[1][1]);
    glVertex2f(c[0][2],c[1][2]);
    glEnd();
    glFlush();
}

void Multiply(int a[][3],int b[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c[i][j]=0;
            for(int k=0;k<3;k++)
            {
                c[i][j]+=(a[i][k])*(b[k][j]);
            }
        }
    }
}
void Translation()
{
    int t[3][3]={{1,0,50},{0,1,50},{0,0,1}};
    Multiply(t,obj);
    Draw();
}
void Scaling()
{
    int s[3][3]={{4,0,0},{0,4,0},{0,0,1}};
    Multiply(s,obj);
    glColor3f(1,0.8,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(10,10);
    glVertex2f(c[0][1],c[1][1]);
    glVertex2f(c[0][2],c[1][2]);
    glEnd();
    glFlush();

}
void Rotation90()
{
    int r[3][3]={{0,1,0},{-1,0,0},{0,0,1}};
    Multiply(r,obj);
    Draw();
}
void Rotationanti90()
{
    int r[3][3]={{0,-1,0},{1,0,0},{0,0,1}};
    Multiply(r,obj);
    Draw();
}
void ReflectionX()
{
    int x[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
        Multiply(x,obj);
        Draw();
}
void ReflectionY()
{
    int x[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
        Multiply(x,obj);
        Draw();
}
void ReflectionO()
{
    int x[3][3]={{-1,0,0},{0,-1,0},{0,0,1}};
        Multiply(x,obj);
        Draw();
}
void ShearX()
{
    int s[3][3]={{1,3,0},{0,1,0},{0,0,1}};
    Multiply(s,obj);
    glColor3f(0.2,0.4,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(10,10);
    glVertex2f(c[0][1],c[1][1]);
    glVertex2f(c[0][2],c[1][2]);
    glEnd();
    glFlush();

}
void ShearY()
{
    int s[3][3]={{1,0,0},{3,1,0},{0,0,1}};
    Multiply(s,obj);
    glColor3f(0.7,0.8,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(10,10);
    glVertex2f(c[0][1],c[1][1]);
    glVertex2f(c[0][2],c[1][2]);
    glEnd();
    glFlush();

}
void menu(int index)
{
    switch(index)
    {
    case 1:
        MyObject();
        break;
    case 2:
        Translation();
        break;
    case 3:
        Scaling();
        break;
    case 4:
        Rotation90();
        break;
    case 5:
        Rotationanti90();
        break;
    case 6:
        ReflectionX();
        break;
     case 7:
        ReflectionY();
        break;
    case 8:
        ReflectionO();
        break;
    case 9:
        ShearX();
        break;
    case 10:
        ShearY();
        break;
    }
}
int main(int argv,char **argc)
{
    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_RGB |GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("Transformation");
    glutDisplayFunc(axes);
    MyInit();
    glutCreateMenu(menu);
    glutAddMenuEntry("MyObject",1);
    glutAddMenuEntry("Translation",2);
    glutAddMenuEntry("Scaling",3);
    glutAddMenuEntry("Rotation90",4);
    glutAddMenuEntry("Rotationanti90",5);
    glutAddMenuEntry("ReflectionX",6);
    glutAddMenuEntry("ReflecionY",7);
    glutAddMenuEntry("ReflectionO",8);
    glutAddMenuEntry("ShearX",9);
    glutAddMenuEntry("ShearY",10);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();


    return 0;
}
