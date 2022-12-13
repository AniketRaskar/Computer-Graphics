#include<bits/stdc++.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>

using namespace std;
#define w 800
#define h 800

float x2,y2,X1,Y1,dx,dy,m,x,y,X,Y;
int steps;

void axes()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    for(int i=-400;i<400;i++)
    {
        glBegin(GL_POINTS);
        glVertex2f(i,0);
        glVertex2f(0,i);
        glEnd();
        glFlush();
    }
}
void MyInit()
{
    glClearColor(1,1,1,1);
    glColor3f(0,1,0);
    glPointSize(5);
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void SetPixel(int a,int b)
{
    glColor3f(0,0,1);
    glBegin(GL_POINTS);
    glVertex2f(a,b);
    glEnd();
    glFlush();
}

void Line()
{
    dx = abs(x2-X1);
    dy = abs(y2-Y1);

    m=dy/dx;
    x=X1;
    y=Y1;
    if(dx>dy)
    {
        steps=dx;
    }
    else
    {
        steps =dy;
    }
    X = (x2-X1)/steps;
    Y = (y2-Y1)/steps;
   for(int i=0;i<=steps;i++)
   {
       x = x+X;
       y = y+Y;
       SetPixel(x,y);

   }

}

void DottedLine()
{
    dx=abs(x2-X1);
    dy = abs(y2-Y1);
    m = dy/dx;
    x=X1;
    y=Y1;
    if(dx>dy)
    {
        steps=dx;
    }
    else
    {
        steps = dy;
    }
    X = (x2-X1)/steps;
    X = (y2-Y1)/steps;
    for(int i=0;i<=steps;i++)
    {
        x = x+X;
        y = y+X;
        if((i%5)==0){
        SetPixel(x,y);
        }
    }
}
void DashedLine()
{
    dx=abs(x2-X1);
    dy = abs(y2-Y1);
    m = dy/dx;
    x=X1;
    y=Y1;
    if(dx>dy)
    {
        steps=dx;
    }
    else
    {
        steps = dy;
    }
    X = (x2-X1)/steps;
    X = (y2-Y1)/steps;
    for(int i=0;i<=steps;i++)
    {
        x = x+X;
        y = y+X;
        if((i%10)>=3){
        SetPixel(x,y);
        }
    }
}
void Boat_draw(int X1,int Y1,int x2,int y2)
{
    dx = abs(x2-X1);
    dy = abs(y2-Y1);

    m=dy/dx;
    x=X1;
    y=Y1;
    if(dx>dy)
    {
        steps=dx;
    }
    else
    {
        steps =dy;
    }
    X = (x2-X1)/steps;
    Y = (y2-Y1)/steps;
   for(int i=0;i<=steps;i++)
   {
       x = x+X;
       y = y+Y;
       SetPixel(x,y);

   }


}
void Boat()
{

    Boat_draw(-100,50,-75,0);
    Boat_draw(-75,0,75,0);
    Boat_draw(75,0,100,50);
    Boat_draw(-100,50,100,50);

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
            DashedLine();
            break;
        case 4:
            Boat();
            break;
        case 5:
            exit(0);
            break;



        }

}
int main(int argv,char **argc)
{
    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );
    glutInitWindowPosition(100,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("DDA1");
    glutDisplayFunc(axes);
    MyInit();
    cout<<"Enter the first co-ordianetes:";
    cin>>X1>>Y1;
    cout<<"Enter the second co-ordiantes:";
    cin>>x2>>y2;
    glutCreateMenu(menu);
    glutAddMenuEntry("Line",1);
    glutAddMenuEntry("DottedLine",2);
    glutAddMenuEntry("DashedLine",3);
    glutAddMenuEntry("Boat",4);
    glutAddMenuEntry("exit",5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

    return 0;
}
