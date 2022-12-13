#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

#include<iostream>
using namespace std;
#define w 800
#define h 800
   int x1,x2,y1,y2;
void SimpleLine()
{



    float dx,dy;
    dx=abs(x2-x1);
    dy=y2-y1;

    int steps;
    if(dx>dy)
    {

        steps=dx;
    }
    else
    {

        steps=dy;
    }
    float xinc,yinc;
    xinc=(x2-x1)/steps;
    yinc=(y2-y1)/steps;

    float x,y;
    x=x1;
    y=y1;

    glColor3f(0,1,0);
    glBegin(GL_POINTS);

    for(int i=1;i<=steps;i++)
    {

        glVertex2f(x,y);


        x=x+xinc;
        y=y+yinc;

    }
    glEnd();
    glFlush();


}
void DashLine()
{



    float dx,dy;
    dx=x2-x1;
    dy=y2-y1;

    int steps;
    if(dx>dy)
    {

        steps=abs(dx);
    }
    else
    {

        steps=abs(dy);
    }
    float xinc,yinc;
    xinc=(float)(dx)/steps;
    yinc=(float)(dy)/steps;

    float x,y;
    x=x1;
    y=y1;

    glColor3f(0,0,1);
    glBegin(GL_POINTS);

    for(int i=1;i<=steps;i++)
    {
        if((i%10)<=3)
        {


        glVertex2f(x,y);
        }

        x=x+xinc;
        y=y+yinc;

    }
    glEnd();
    glFlush();


}
void DottedLine()
{



    float dx,dy;
    dx=x2-x1;
    dy=y2-y1;

    int steps;
    if(dx>dy)
    {

        steps=abs(dx);
    }
    else
    {

        steps=abs(dy);
    }
    float xinc,yinc;
    xinc=(float)(dx)/steps;
    yinc=(float)(dy)/steps;

    float x,y;
    x=x1;
    y=y1;

    glColor3f(1,0,0);
    glBegin(GL_POINTS);

    for(int i=1;i<=steps;i++)
    {
        if((i%2)==0)
        {


        glVertex2f(x,y);
        }

        x=x+xinc;
        y=y+yinc;

    }
    glEnd();
    glFlush();


}
void Draw_Boat(float x1,float y1,float x2,float y2)
{
    float dx,dy;
    dx=abs(x2-x1);
    dy=abs(y2-y1);

    int steps;
    if(dx>dy)
    {

        steps=dx;
    }
    else
    {

        steps=dy;
    }
    float xinc,yinc;
    xinc=(x2-x1)/steps;
    yinc=(y2-y1)/steps;

    float x,y;
    x=x1;
    y=y1;

    glColor3f(0,0,1);
    glBegin(GL_POINTS);

    for(int i=1;i<=steps;i++)
    {

        glVertex2f(x,y);


        x=x+xinc;
        y=y+yinc;

    }
    glEnd();
    glFlush();


}
void Boat()
{
   Draw_Boat(0,50,50,0);
   Draw_Boat(50,0,100,0);
   Draw_Boat(100,0,150,50);
   Draw_Boat(150,50,0,50);
   Draw_Boat(50,50,75,75);
   Draw_Boat(75,75,100,50);

}
void menu(int choise)
{

    if(choise==1)
    {
        SimpleLine();
    }
    else if(choise==2)
    {
        DottedLine();
    }
    else if(choise==3)
    {
        DashLine();
    }
    else if(choise==4)
    {
        Boat();
    }

}
void SetPixel(int p1,int p2)
{
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    glVertex2d(p1,p2);
    glEnd();

}

    void Display()
    {

        for(int j=-400;j<400;j++)
        {
            SetPixel(j,0);
            SetPixel(0,j);

        }
        glFlush();
    }
void MyInit()
{

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100,150);
    glutInitWindowSize(600,600);
    glutCreateWindow("Practice");
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
    MyInit();
    glutDisplayFunc(Display);

   cout<<"(Enter the first cooradiants:)";
    cin>>x1>>y1;
    cout<<"(Enter the second co ordiantes:)";
    cin>>x2>>y2;
    glutCreateMenu(menu);
    glutAddMenuEntry("SimpleLine",1);
    glutAddMenuEntry("DottedLine",2);
    glutAddMenuEntry("DashedLine",3);
    glutAddMenuEntry("Boat",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}

