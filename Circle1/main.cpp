
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<windows.h>
#include<iostream>
using namespace std;
#define w 800
#define h 800

int x,y,r,p,xc,yc;
void MyInit()
{
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(3);
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void SetPixel(int a,int b)
{
    glBegin(GL_POINTS);
    glVertex2f(a,b);
    glEnd();
    glFlush();
}
void axes()
{
    for(int i=-400;i<400;i++)
    {
        glBegin(GL_POINTS);
        glVertex2f(0,i);
        glVertex2f(i,0);
        glEnd();
        glFlush();
    }
}

void plot(int x,int y)
{
   // glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1,0,0);
    glBegin(GL_POINTS);
    glVertex2f(xc+x,yc+y);
    glVertex2f(xc-x,yc+y);
    glVertex2f(xc+x,yc-y);
    glVertex2f(xc-x,yc-y);

    glVertex2f(xc+y,yc+x);
    glVertex2f(xc-y,yc+x);
    glVertex2f(xc+y,yc-x);
    glVertex2f(xc-y,yc-x);
    glEnd();
    glFlush();


}

void Circle()
{
    x=0;
    y=r;
     p = 3 - 2*r;
    while(y>=x)
    {

        if(p<=0)
        {
            p = p+ 4*x +6;
        }
        else
        {
            p= p+ 4*(x - y)+10;
            y--;
        }
        x++;
        plot(x,y);
    }
    glFlush();

}
void Concentric()
{
    x=0;
    r=r/0.5;
    Circle();

}
void Ring()
{
    glColor3f(1,0,0);
    Circle();

    glColor3f(0,1,0);
    xc=xc+2*r-10;
    Circle();

    glColor3f(0,0,1);
    xc = xc+2*r-10;
    Circle();

    glColor3f(0.8,0.9,1);
    xc = xc-r+10;
    yc = yc - 1.5*r;
    Circle();

    glColor3f(0.8,0.9,0.4);
    xc = xc-2*r+10;
    Circle();


}
void Spiral_1(int r,int xc,int yc)
{
    x=0;
    y=r;
     p = 3 - 2*r;
    while(y>=x)
    {

        if(p<=0)
        {
            p = p+ 4*x +6;
        }
        else
        {
            p= p+ 4*(x - y)+10;
            y--;
        }
        x++;

        SetPixel(x+xc,y+yc);
        SetPixel(y+xc,x+yc);
        SetPixel(-x+xc,y+yc);
        SetPixel(-y+xc,x+yc);
    }
}

void Spiral_2(int r,int xc,int yc)
{
    x=0;
    y=r;
     p = 3 - 2*r;
    while(y>=x)
    {

        if(p<=0)
        {
            p = p+ 4*x +6;
        }
        else
        {
            p= p+ 4*(x - y)+10;
            y--;
        }
        x++;
        SetPixel(-x+xc,-y+yc);
        SetPixel(-y+xc,-x+yc);
        SetPixel(x+xc,-y+yc);
        SetPixel(y+xc,-x+yc);
    }
}

void Spiral()
{
    for(int i=0;i<10;i++)
    {
        if(i%2==0)
        {
            Spiral_1(i*10,10,0);
        }
        else
        {
            Spiral_2(i*10,20,0);
        }
    }

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
        Ring();
        break;
    case 4:
        Spiral();
        break;
    }
}
int main(int argv,char **argc)
{
    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_RGB |GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("Circle");
    glutDisplayFunc(axes);
    MyInit();
    cout<<"Enter the CO-ordinates of circle:";
    cin>>xc>>yc;
    cout<<"Enter the radius:";
    cin>>r;

    glutCreateMenu(menu);
    glutAddMenuEntry("circle",1);
    glutAddMenuEntry("Concentric",2);
    glutAddMenuEntry("Ring",3);
    glutAddMenuEntry("Spiral",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


    glutMainLoop();
    return 0;
}
