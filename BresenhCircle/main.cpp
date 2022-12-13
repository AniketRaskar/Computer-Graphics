#include<windows.h>
#include<iostream>
using namespace std;
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#define w 600
#define h 600

float x,y,xc,yc,p,r,X,Y;
int index;

void SetPixel(int X,int Y)
{
   glColor3f(1,0,0);
   glPointSize(3);
  // glClear(GL_CLEAR_BUFFER_BIT);
   glBegin(GL_POINTS);
   glVertex2f(X,Y);
   glEnd();
   glFlush();
}
void DrawCircle(int xc,int yc,int x,int y)
{
    glBegin(GL_POINTS);
    SetPixel(xc+x,yc+y);
    SetPixel(xc-x,yc+y);
    SetPixel(xc+x,yc-y);
    SetPixel(xc-x,yc-y);
    SetPixel(xc+y,yc+x);
    SetPixel(xc-y,yc+x);
    SetPixel(xc+y,yc-x);
    SetPixel(xc-y,yc-x);

}

void Circle()
{
    x=0;
    y=r;

    p = 3 - 2*r;
    while(y >= x)
    {
        if(p <= 0)
        {
            p = p + 4*x +6;
        }
        else
        {
            p = p + 4*(x-y)+10;
            y--;
        }
        x++;
    DrawCircle(xc,yc,x,y);
    }



}

void Concentric()
{
    glColor3f(1,1,0);
    r=1.4*r;
    Circle();
}
void olympicRing()
{
    glColor3f(1,0,0);
    xc = xc+2*r -10;
    Circle();

    glColor3f(0.5,0.4,0.7);
    xc = xc+2*r -10;
    Circle();

    glColor3f(1,0.4,0.7);
    xc = xc+2*r -10;
    Circle();

    glColor3f(1,0.7,0.9);
    xc = xc -35;
    yc = yc - 1.4*r;
    Circle();

    glColor3f(1,0.3,0.9);
    xc = xc -2*r +25;
    Circle();

}

void menu(int index)
{
    switch(index)
    {
    case 1:
        Circle();
        break;
    case 2:
        Concentric();
        break;
    case 3:
        olympicRing();
    }

}

void MyInit()
{
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(3);
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void Display()
{
    glColor3f(0,1,0);
    for(int j= -300;j<=300;j++)
    {
        glBegin(GL_POINTS);
        glVertex2i(j,0);
        glVertex2i(0,j);
        glEnd();
        glFlush();
    }
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Bresenhm Circle");
    glutDisplayFunc(Display);
    MyInit();
    cout<<"Enter the origion of circle:";
    cin>>xc>>yc;
    cout<<"Enter the radius of circle:";
    cin>>r;
    glutCreateMenu(menu);
    glutAddMenuEntry("Circle",1);
    glutAddMenuEntry("Concentric",2);
    glutAddMenuEntry("olympic",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
