#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include<GL/freeglut.h>
#include<time.h>
#include<cstring>
#include<iostream>
using namespace std;
#define window_width  1000
#define window_height 800
int wid, n;
int keypa=0;
char a1[50];
float r=1.0,g=1.0,b=1.0,r1=1.0;
//int stack[50];
int no, top=-1;
int index_i = 1, index_j;
char temp = '\0';

int n1;
//char a1[50]={'5','4','1','6'};
int yellow_color[100];
int red_color[100];
GLfloat space;

int sb;


void colormenu(int id)
{
switch(id)
{
case 2:
r=0.3;
g=0;
b=0;
r1=0;
break;
case 3:
r=0;
g=0.3;
b=0;
r1=0;
break;
case 4:
r=0;
g=0.2;
b=0.5;
r1=0;
break;
case 5:
r=1;
g=1;
b=1;
r1=0;
break;
}
glutPostRedisplay();
}
void tm(int id)
{
switch(id)
{
case 1: exit(1);
break;
default:colormenu(id);
break;
}
}

void delay(){
for(int c=1;c<=10000; c++)
{
for(int d=1;d<=10000; d++)
{
}
}
}


void RenderString(float x, float y, void *font, char string)
{
        glColor3f(0.0, 0.0, 1.0);
        glRasterPos2f(x, y);
        glutBitmapCharacter(font, string);
}

void strir(char p,int n,GLint x,GLint y)
{
    glColor3f(1,0.9,0);
    glRasterPos2f(x,y);
    //for(int i=0;i<n;i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24 , p );
}

void stri(char *p,int n,GLint x,GLint y)
{
    glColor3f(1,0.9,0);
    glRasterPos2f(x,y);
    for(int i=0;i<n;i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24 , p[i] );
}

//int index_i = 1, index_j;
//char temp = '\0';

void drawer() {
        delay();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 1.0);
        for (int i = 1; i <= n1; i++) {
                glColor3f(1.0, 1.0, 1.0);
                if (yellow_color[i - 1])
                        glColor3f(0.0, 1.0, 0.0);
                else if (red_color[i - 1])
                        glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POLYGON);

    //glColor3f(0.5,0,0);
    glVertex2f(space*i+5-730 , 315);
    glVertex2f(space*i - 25-730, 320);
glVertex2f(space*i - 50-730, 350);
    glVertex2f(space*i - 33-730, 385);
glVertex2f(space*i+4 -730, 398);
glVertex2f(space*i + 55-730, 385);
glVertex2f(space*i + 70-730, 350);
    glVertex2f(space*i + 42-730, 323);
glEnd();

                //glRectf(space*i - 25, 300, space*i + 25, 400);
                RenderString(space*i - 730, 345, GLUT_BITMAP_TIMES_ROMAN_24, a1[i - 1]);
                glColor3f(1.0, 0.5, 0.5);
                //glRectf(475, 450, 525, 550);
/*glBegin(GL_POLYGON);
    //glVertex2f(500, 550);
   glVertex2f(465, 501);
    glVertex2f(480, 473);
    glVertex2f(510, 463);
    glVertex2f(540, 473);
    glVertex2f(555, 501);
    glVertex2f(540, 535);
    glVertex2f(505, 545);
    glVertex2f(480, 535);



glEnd(); */
/*
glBegin(GL_POLYGON);
    //glVertex2f(500, 550);
   glVertex2f(175, 501);
    glVertex2f(190, 473);
    glVertex2f(220, 463);
    glVertex2f(250, 473);
    glVertex2f(265, 501);
    glVertex2f(250, 535);
    glVertex2f(215, 545);
    glVertex2f(190, 535);



glEnd();



                glColor3f(0.5, 0, 0.5);
                RenderString(210, 495, GLUT_BITMAP_TIMES_ROMAN_24, temp);*/
        }
        glFlush();
}


void selectionSort() {
        int i,j,min_idx;

        for(i=0;i<n1;i++)
        /*To sort elements in descending order, change temp<data[j] to
temp>data[j] in above line.*/
        {
                red_color[i] = 1;

                min_idx=i;
                drawer();
                memset(red_color, 0, sizeof(red_color));
                for(j=i+1;j<n1;j++)
                {
                    red_color[j] = 1;

                    drawer();
                    memset(red_color, 0, sizeof(red_color));
                    if(a1[j]<a1[min_idx])
                        {
                            red_color[j] = 1;
                            min_idx=j;
                            drawer();
                            memset(red_color, 0, sizeof(red_color));
                        }
                }
        yellow_color[min_idx] = 1;
        yellow_color[i] = 1;
        drawer();
        delay();
        temp=a1[min_idx];
        a1[min_idx]=a1[i];
        a1[i]=temp;
        }


}
void delay1()
{
    for(int i=0;i<35000;i++)
        for(int j=0;j<5000;j++);
}

char line1[] = {"JSS Academy of Technical Education, Bangalore"};
char line2[] = {"Computer Science Department"};
char line3[] = {"   Computer Graphics project"};
char line8[]={"Topic: Selection Sort Algorithm"};
char line4[] = {"Submitted By : "};
char line5[] = {"AMULYA HN : 1JS16CS012"};
char line6[] = {"APOORVA N : 1JS16CS016"};
char line7[] = {"(Press 1 to enter the main page)"};
char line9[] = {"Under The Guidance Of : "};
char line10[] = {"Ms RASHMI BN"};
char op[] = {"Options:"};
char op1[] = {"1. First Come First Serve (FCFS)"};
char op2[] = {"2. Round Robin (RR)"};
char op3[] = {"3. Shortest Remaining Time First (SRTF)"};
char op4[] = {"4. Re-enter the data"};
char op5[] = {"5. Exit"};
int np=1;
//End of global declarations

void striz(char *p,int n,GLint x,GLint y)
{
    glColor3f(1,0.9,0);
    glRasterPos2f(x,y);
    for(int i=0;i<n;i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24 , p[i] );
}
void strii(char *p,int n,GLint x,GLint y)
{
    glColor3f(1,0.9,0);
    glRasterPos2f(x,y);
    for(int i=0;i<n;i++)
        glutBitmapCharacter( GLUT_BITMAP_8_BY_13 , p[i] );
}
void backgrnp()
{
    stri("Enter the number of elements",30,15,375);
     //printf("hai");
    //constr();
glutSwapBuffers();
    glFlush();
//drawer();
  //selectionSort();
    //  glutPostRedisplay();
}
void push(char e)
{
int i;

a1[++top]=e;

}

void backgrnp1()
{
    striz("Enter the elements",30,15,375);
    //strii("Press zero after entering all elements",50,35,505);
    //constr();
    glutSwapBuffers();
    glFlush();
//drawer();
  //  selectionSort();
    //   glutPostRedisplay();
}

void init()
{
        //glLoadIdentity();
        //glMatrixMode(GL_PROJECTION);

    glClearColor(1,1,1,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0,1000,0,700);

}


void myinit() {
        glLoadIdentity();
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);

        gluOrtho2D(0, 1000, 0, 700);
}


/*void init()
{
        //glLoadIdentity();
        //glMatrixMode(GL_PROJECTION);

    glClearColor(1,1,1,0.0);
    glMatrixMode(GL_PROJECTION);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0, 1000, 0, 700);

}
*/



void key1(unsigned char k,int x,int y)
{
    char a=k;
    int numb;
    if(keypa==0)
    {
        if(a == '1') {
            keypa=1;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);

            backgrnp();
        }
    }
    else if(keypa==1)
    {
        if(a < '3'&& a > '1') {
            keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            n1=2;
            stri(&a,1,360,175);
            backgrnp();
            delay1();
            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();

        }
        else if(a <'4' && a > '2')
        {
             keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            n1=3;
            stri(&a,1,360,175);
            backgrnp();
            delay1();
            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
        }
        else if(a <'5' && a > '3') {
             keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            n1=4;
            stri(&a,1,360,175);
            backgrnp();
            delay1();
            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
        else if(a <'6' && a > '4') {
             keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            n1=5;
            stri(&a,1,360,175);
            backgrnp();
            delay1();
            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
        else if(a <'7' && a > '5') {
             keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            n1=6;
            stri(&a,1,360,175);
            backgrnp();
            delay1();
            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
        else if(a <'8' && a > '6') {
             keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            n1=7;
            stri(&a,1,360,175);
            backgrnp();
            delay1();
            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
        else if(a <'9' && a > '7') {
             keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            n1=8;
            stri(&a,1,360,175);
            backgrnp();
            delay1();
            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
            else if(a <'10' && a > '9') {
             keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            n1=9;
            stri(&a,1,360,175);
            backgrnp();
            delay1();
            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
    }
    else if(keypa==2)
    {
        if(a <'2') {
            keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            push(a);
            stri(&a,1,360,175);
            backgrnp1();
            delay1();

            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();


        }
        else if(a <'3' && a > '1') {
            keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            push(a);

            stri(&a,1,360,175);
            backgrnp1();
            delay1();
            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();

            }
        else if(a <'4' && a > '2') {

            keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            push(a);

            stri(&a,1,360,175);
            backgrnp1();
            delay1();

            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
         else if(a <'5' && a > '3') {
            keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            push(a);
            stri(&a,1,360,175);
            backgrnp1();
            delay1();

            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
        else if(a <'6' && a > '4') {
            keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            push(a);
            stri(&a,1,360,175);
            backgrnp1();
            delay1();

            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
        else if(a <'7' && a > '5') {
            keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            push(a);
            stri(&a,1,360,175);
            backgrnp1();
            delay1();

            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
        else if(a <'8' && a > '6') {
            keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            push(a);
            stri(&a,1,360,175);
            backgrnp1();
            delay1();

            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
        else if(a <'9' && a > '7') {
            keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            push(a);
            stri(&a,1,360,175);
            backgrnp1();
            delay1();

            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();
            }
        else if(a <'10' && a > '8') {
            keypa=2;
            glClearColor(0.0,0.255,.255,.803);
            glClear (GL_COLOR_BUFFER_BIT);
            /*push(a);
            stri(&a,1,360,375);
            backgrnp1();
            delay1();

            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp1();*/

            glClear(GL_COLOR_BUFFER_BIT);
            space = 1000 / (2 + 1.0);


            myinit();
            drawer();

        selectionSort();

            }




    }



}
void displayText( float x, float y, int r, int g, int b, const char *string ) {
    int j = strlen (string);
    glColor3f( r, g, b );
    glRasterPos2f( x, y );
    for( int i = 0; i < j; i++ )
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
    glFlush();
}

void displayName(char *lines)
{
  displayText(500, 450, 1, 1, 1,lines);

}

void displayfirst(void){

    displayText(50, 500, 0, 0, 1,line3);
    displayText(10, 600, 0, 0, 0,line2);
    displayText(-140, 650, 0, 0, 0,line1);
    displayText(50, 450, 1, 0, 0,line8);
    displayText(-550, 230, 1, 0, 0,line4);
    displayText(-550, 150,0, 0, 0,line5);
    displayText(-550, 70, 0, 0, 0,line6);
    displayText(220,-40,0,1,0,line7);
    displayText(770,220,1,0,0,line9);
    displayText(790,150,0,0,0,line10);

}


void displayOptions()
{
    glClear(GL_COLOR_BUFFER_BIT);
    displayText(300, 200, 1, 1, 1,op5);
    displayText(600, 230, 1, 1, 1,op4);
    displayText(600, 260, 1, 1, 1,op3);
    displayText(600, 290, 1, 1, 1,op2);
    displayText(100, 320, 1, 1, 1,op1);
    displayText(600, 350, 1, 0, 0,op);

}
void disp()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(r,g,b,r1);
    /*
     sb=glutCreateMenu(colormenu);
glutAddMenuEntry("RED",2);
glutAddMenuEntry("GREEN",3);
glutAddMenuEntry("BLUE",4);
glutAddMenuEntry("WHITE",5);
glutCreateMenu(tm);
glutAddMenuEntry("QUIT",1);
glutAddSubMenu("COLOR",sb);
glutAttachMenu(GLUT_RIGHT_BUTTON);
*/
    displayfirst();
}

void myReshape(int w, int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(w<=h)
                glOrtho(-1.75,1.75,-1.75*h/w,1.75*h/w,-5,10);
        else
                glOrtho(-1.75*w/h, 1.75*w/h,-1.75,1.75,-5,10);
        glMatrixMode(GL_MODELVIEW);
}


//Initialiasation

int main(int argc, char** argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1500, 1500);
    //glutInitWindowPosition(100,100);
    wid =  glutCreateWindow("");
//glutReshapeFunc(winReshapeFcn);
    //init();

    glutDisplayFunc(disp);
sb=glutCreateMenu(colormenu);
glutAddMenuEntry("RED",2);
glutAddMenuEntry("GREEN",3);
glutAddMenuEntry("BLUE",4);
glutAddMenuEntry("WHITE",5);
glutCreateMenu(tm);
glutAddMenuEntry("QUIT",1);
glutAddSubMenu("COLOR",sb);
glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutKeyboardFunc(key1);
    glutReshapeFunc(myReshape);
init();

   // GL_Setup( window_width, window_height);
    //a();

    glutMainLoop();
}
