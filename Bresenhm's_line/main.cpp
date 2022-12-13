#include<windows.h>
#include<iostream>
using namespace std;
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#define w 800
#define h 600

float x1,y1,x2,y2,dx,dy,po,m,sx,sy;
int index;

void SetPixel(int i,int j)
{
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2i(i,j);
    glEnd();
    glFlush();


}
void SimpleLine()
{
    dx = abs(x2-x1);
    dy = abs(y2-y2);

    m = dy/dx;

    float x=x1;
    float y=y1;

    if((x2-x1)>0)
       {

            sx = 1;
       }
       else
        {
            sx = -1;
        }
    if((y2-y1)>0)
    {
        sy = 1;
    }
    else
    {
        sy = -1;
    }
    po = 2*dy - dx;
    if(m<1)
    {
        for(int i =0;i< dx;i++)
        {

        if(po < 0)
        {
            x = x +sx;
            y = y;
            po = po + 2*dy;

        }
        else
        {
            x = x + sx;
            y = y + sy;

            po = po + 2*dy - 2*dx;
        }
        glColor3f(1,0,0);
        SetPixel(x,y);
        }

    }
    else
    {
        for(int i=0;i<=dy;i++)
        {
            if(po < 0)
            {

                x = x;
                y = y + sy;
                po = po + 2*dx;
            }
            else
            {
                x = x +sx ;
                y = y + sy;
                po = po + 2*dx - 2*dy;
            }
             glColor3f(1,0,0);
        SetPixel(x,y);
        }
    }


}
void DottedLine()
{
    dx = abs(x2-x1);
    dy = abs(y2-y2);

    m = dy/dx;

    float x=x1;
    float y=y1;

    if((x2-x1)>0)
       {

            sx = 1;
       }
       else
        {
            sx = -1;
        }
    if((y2-y1)>0)
    {
        sy = 1;
    }
    else
    {
        sy = -1;
    }
    po = 2*dy - dx;
    if(m<1)
    {
        for(int i =0;i< dx;i++)
        {

        if(po < 0)
        {
            x = x +sx;
            y = y;
            po = po + 2*dy;

        }
        else
        {
            x = x + sx;
            y = y + sy;

            po = po + 2*dy - 2*dx;
        }
        if((i%10)==0)
        {


        glColor3f(0,1,0);
        SetPixel(x,y);
        }
        }

    }
    else
    {
        for(int i=0;i<=dy;i++)
        {
            if(po < 0)
            {

                x = x;
                y = y + sy;
                po = po + 2*dx;
            }
            else
            {
                x = x +sx ;
                y = y + sy;
                po = po + 2*dx - 2*dy;
            }
            if((i%10)==0){
             glColor3f(0,1,0);
        SetPixel(x,y);}
        }
    }


}
void Dashline()
{
    dx = abs(x2-x1);
    dy = abs(y2-y2);

    m = dy/dx;

    float x=x1;
    float y=y1;

    if((x2-x1)>0)
       {

            sx = 1;
       }
       else
        {
            sx = -1;
        }
    if((y2-y1)>0)
    {
        sy = 1;
    }
    else
    {
        sy = -1;
    }
    po = 2*dy - dx;
    if(m<1)
    {
        for(int i =0;i< dx;i++)
        {

        if(po < 0)
        {
            x = x +sx;
            y = y;
            po = po + 2*dy;

        }
        else
        {
            x = x + sx;
            y = y + sy;

            po = po + 2*dy - 2*dx;
        }
        if((i%10)<4){
        glColor3f(0,0,1);
        SetPixel(x,y);
        }
        }

    }
    else
    {
        for(int i=0;i<=dy;i++)
        {
            if(po < 0)
            {

                x = x;
                y = y + sy;
                po = po + 2*dx;
            }
            else
            {
                x = x +sx ;
                y = y + sy;
                po = po + 2*dx - 2*dy;
            }
            if((i%10)<4){
             glColor3f(0,0,1);
        SetPixel(x,y);
            }
        }
    }


}

void Display()
{
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    for(int j= -400; j<400;j++)
    {
        glVertex2i(j,0);
        glVertex2i(0,j);
    }
    glEnd();
   glFlush();
}
void menu(int index)
{
    switch(index)
    {
    case 1:
        SimpleLine();
        break;
    case 2:
        DottedLine();
        break;
    case 3:
        Dashline();
        break;
    }
}
void Init()
{
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(3);
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

int main(int arg,char **argv)
{
    glutInit(&arg,argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);;
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Bresenham's_line");
    Init();

    cout<<"Enter the first Co-ordinates:";
    cin>>x1>>y1;
    cout<<"Enter the second co-ordiantes:";
    cin>>x2>>y2;
    glutDisplayFunc(Display);
    glutCreateMenu(menu);
    glutAddMenuEntry("SimleLine",1);
    glutAddMenuEntry("DottedLine",2);
    glutAddMenuEntry("DashedLine",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
