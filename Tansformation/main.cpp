#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
# define w 1000
#define h 1000
#include<iostream>
using namespace std;

float a,b;
int c[3][3];
int obj[3][3] ={{10,100,45},{10,10,50},{1,1,1}};

void MyInit()
{
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(2);
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void SetPixel(int a, int b)
{

    glBegin(GL_POINTS);
    glVertex2f(a,b);
    glEnd();
    glFlush();
}
void axes()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    for(int i=-w;i<w;i++)
    {
        SetPixel(i,0);
        SetPixel(0,i);
    }

}
void myObject()
{
    glClear(GL_COLOR_BUFFER_BIT);
    axes();
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(10,10);
    glVertex2f(100,10);
    glVertex2f(45,50);
    glEnd();
    glFlush();
}

void Multiply(int a[3][3],int b[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c[i][j]=0;
            for(int k=0;k<3;k++)
            {
                c[i][j]+= (a[i][k])*(b[k][j]);
            }
        }
    }
}
void Draw()
{
    glColor3f(1,0.4,0.6);
    glBegin(GL_POLYGON);
    glVertex2f(c[0][0],c[1][0]);
    glVertex2f(c[0][1],c[1][1]);
    glVertex2f(c[0][2],c[1][2]);
    glEnd();
    glFlush();

}

void Translation()
{
    int t[3][3]={{1,0,50},{0,1,50},{0,0,1}};
    Multiply(t,obj);
    Draw();
}
void Scaling()
{
    int t[3][3]={{2,0,0},{0,2,0},{0,0,1}};
    Multiply(t,obj);
    Draw();
   }
void ScalingFixed()
{
   int t[3][3]={{2,0,0},{0,2,0},{0,0,1}};
    Multiply(t,obj);
    glColor3f(1,0.4,0.6);
    glBegin(GL_POLYGON);
    glVertex2f(10,10);
    glVertex2f(c[0][1],c[1][1]);
    glVertex2f(c[0][2],c[1][2]);
    glEnd();
    glFlush();
}
void ShearingX()
{
    int t[3][3] ={{1,3,0},{0,1,0},{0,0,1}};
    Multiply(t,obj);
    glColor3f(1,0.4,0.6);
    glBegin(GL_POLYGON);
    glVertex2f(10,10);
    glVertex2f(c[0][1],c[1][1]);
    glVertex2f(c[0][2],c[1][2]);
    glEnd();
    glFlush();

}
void ShearingY()
{
    int t[3][3] ={{1,0,0},{3,1,0},{0,0,1}};
    Multiply(t,obj);
    glColor3f(1,0.4,0.6);
    glBegin(GL_POLYGON);
    glVertex2f(10,10);
    glVertex2f(c[0][1],c[1][1]);
    glVertex2f(c[0][2],c[1][2]);
    glEnd();
    glFlush();

}

void ReflectionX()
{
    int t[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
    Multiply(t,obj);
    Draw();
   }
void ReflectionY()
{
    int t[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
    Multiply(t,obj);
    Draw();
   }

void ReflectionO()
{
    int t[3][3]={{-1,0,0},{0,-1,0},{0,0,1}};
    Multiply(t,obj);
    Draw();
   }

   void Rotation90()
{
    int t[3][3]={{0,1,0},{-1,0,0},{0,0,1}};
    Multiply(t,obj);
   glBegin(GL_POLYGON);
    glVertex2f(10,10);
    glVertex2f(c[0][1],c[1][1]);
    glVertex2f(c[0][2],c[1][2]);
    glEnd();
    glFlush();
   }

   void Rotationanti90()
{
    int t[3][3]={{0,-1,0},{1,0,0},{0,0,1}};
    Multiply(t,obj);
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
        myObject();
        break;
    case 2:
        Translation();
        break;
    case 3:
        Scaling();
        break;
    case 4:
        ScalingFixed();
        break;
    case 5:
       ShearingX();
       break;
    case 6:
       ShearingY();
       break;
    case 7:
       ReflectionX();
       break;

    case 8:
       ReflectionY();
       break;
    case 9:
       ReflectionO();
       break;
    case 10:
       Rotation90();
       break;
    case 11:
       Rotationanti90();
       break;
    case 12:
        exit(0);
    }
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB |GLUT_SINGLE );
    glutInitWindowPosition(100,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("Transformation");
    MyInit();
    Translation();
    glutDisplayFunc(axes);
    glutCreateMenu(menu);
    glutAddMenuEntry("Myobject",1);
    glutAddMenuEntry("Tranlation",2);
    glutAddMenuEntry("Scaling",3);
    glutAddMenuEntry("scalingFixed",4);
    glutAddMenuEntry("ShearX",5);
    glutAddMenuEntry("Sheary",6);
    glutAddMenuEntry("ReflectionX",7);
    glutAddMenuEntry("ReflectionY",8);
    glutAddMenuEntry("ReflectionO",9);
    glutAddMenuEntry("Rotation90",10);
    glutAddMenuEntry("Rotationanti90",11);
    glutAddMenuEntry("Exit",12);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


    glutMainLoop();
    return 0;
}
