#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
#define w 600
#define h 600
int x,y,x1,y1,x2,y2,dx,dy,p,sx,sy;
float m;

void MyInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(3);
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void axes()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i= -w;i<w;i++)
    {
        glColor3f(0,1,0);
        glBegin(GL_POINTS);
        glVertex2f(i,0);
        glVertex2f(0,i);
        glEnd();
        glFlush();
    }
}
void SetPixel(int a,int b)
{

    glColor3f(0,1,0);
    glBegin(GL_POINTS);
    glVertex2f(a,b);
    glEnd();
    glFlush();
}
void Line()
{
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    m = dx/dy;
    x=x1;
    y=y1;

    if((x2-x1)>0)
    {
        sx=1;
    }
    else
    {
        sx = -1;
    }

    if((y2-y1)>0)
    {
        sy=1;

    }
    else
    {
        sy = -1;
    }

    p = 2*dy - dx;

    if(m < 0)
    {
        for(int i=0; i<dx ;i++)
        {
            if(p < 0)
            {
                x = x + sx;
                y = y;
                p = p + 2*dy;
            }
            else
            {
                x = x+sx;
                y = y + sy;
                p = p + 2*dy - 2*dx;
            }

            SetPixel(x,y);

        }
    }
    else
    {
        for(int i=0;i < dy;i++)
        {
            if(p < 0)
            {
                x = x;
                y = y + sy;

                p = p + 2*dx;
            }
            else
            {
                x = x + sx;
                y = y + sy;
                p = p+2*dx -dy;
            }
            SetPixel(x,y);
        }
    }

}
void DottedLine()
{
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    m = dx/dy;
    x=x1;
    y=y1;

    if((x2-x1)>0)
    {
        sx=1;
    }
    else
    {
        sx = -1;
    }

    if((y2-y1)>0)
    {
        sy=1;

    }
    else
    {
        sy = -1;
    }

    p = 2*dy - dx;

    if(m < 0)
    {
        for(int i=0; i<dx ;i++)
        {
            if(p < 0)
            {
                x = x + sx;
                y = y;
                p = p + 2*dy;
            }
            else
            {
                x = x+sx;
                y = y + sy;
                p = p + 2*dy - 2*dx;
            }
            if((i%2)==0){
            SetPixel(x,y);}

        }
    }
    else
    {
        for(int i=0;i < dy;i++)
        {
            if(p < 0)
            {
                x = x;
                y = y + sy;

                p = p + 2*dx;
            }
            else
            {
                x = x + sx;
                y = y + sy;
                p = p+2*dx -dy;
            }
            if((i%2)==0){
            SetPixel(x,y);}
        }
    }

}
void DashLine()
{
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    m = dx/dy;
    x=x1;
    y=y1;

    if((x2-x1)>0)
    {
        sx=1;
    }
    else
    {
        sx = -1;
    }

    if((y2-y1)>0)
    {
        sy=1;

    }
    else
    {
        sy = -1;
    }

    p = 2*dy - dx;

    if(m < 0)
    {
        for(int i=0; i<dx ;i++)
        {
            if(p < 0)
            {
                x = x + sx;
                y = y;
                p = p + 2*dy;
            }
            else
            {
                x = x+sx;
                y = y + sy;
                p = p + 2*dy - 2*dx;
            }
            if(i<=3){
            SetPixel(x,y);}

        }
    }
    else
    {
        for(int i=0;i < dy;i++)
        {
            if(p < 0)
            {
                x = x;
                y = y + sy;

                p = p + 2*dx;
            }
            else
            {
                x = x + sx;
                y = y + sy;
                p = p+2*dx -dy;
            }
            if(i%8>=4){
            SetPixel(x,y);}
        }
    }

}
void menu(int index)
{
    switch(index)
    {

    case 1:
        Line();
        break;
    case 2:
        DottedLine();
        break;
    case 3:
        DashLine();
        break;
    case 4:
        exit(0);
    }
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Line");

    MyInit();
    glutDisplayFunc(axes);
    cout<<"Emter the first coordantes:";
    cin>>x2>>y2;
    cout<<"Enter the second coordiantes:";
    cin>>x1>>y1;
    glutCreateMenu(menu);
    glutAddMenuEntry("Line",1);
    glutAddMenuEntry("DottedLine",2);
    glutAddMenuEntry("DashedLine",3);
    glutAddMenuEntry("Exit",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

        return 0;
}
