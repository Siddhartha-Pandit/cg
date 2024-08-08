#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;

float tri[3][3]={{-100,100,0},{-100,-100,100},{1,1,1}};
float tx=50,ty=50;
float thetar=(M_PI/180)*30;
float px=0,py=0;
void draw_tri(){
glBegin(GL_LINE_LOOP);
for (int i =0;i<3;i++){
glVertex2f(tri[0][i],tri[1][i]);
}
glEnd();
}

void translate(){
glBegin(GL_LINE_LOOP);

for (int i =0;i<3;i++){
float x=tri[0][i]+tx;
float y=tri[1][i]+ty;
glVertex2f(x,y);
}
glEnd();
}
void scale(){
glBegin(GL_LINE_LOOP);

for (int i =0;i<3;i++){
float x=tri[0][i]*2;
float y=tri[1][i]*2;
glVertex2f(x,y);
}
glEnd();
}

void rotate(){
glBegin(GL_LINE_LOOP);

for (int i =0;i<3;i++){
float x=tri[0][i],y=tri[1][i];
float rx=px+(x-px)*cos(thetar)-(y-py)*sin(thetar);
float ry=py+(x-px)*sin(thetar)+(y-py)*cos(thetar);

glVertex2f(rx,ry);
}
glEnd();
}


void display(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
draw_tri();
glColor3f(1,0,1);
translate();
glColor3f(0,1,1);
rotate();
glColor3f(0,1,0);
scale();
glFlush();
}

void init(){

glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-250,250,-250,250);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char  **argv){

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("2d transformation");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}