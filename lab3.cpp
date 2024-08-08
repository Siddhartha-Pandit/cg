#include <iostream>
#include <GL/glut.h>
int TRANSFORM =-1;
#define TRANSLATE 1
# define ROTATE 2
#define ROTATE_PVT 3
#define SCALE 4
#define 	SCALE_PVT 5
using namespace std;
float tri[3][3]={{-100,100,0},{-100,-100,100},{1,1,1}};
void menu(int id){
switch (id){
case 0:
exit(0);
break;
case  TRANSLATE:
TRANSFORM=TRANSLATE;
break;
}
glutPostRedisplay();
}

void rot(int id){
switch (id){
case ROTATE:
TRANSFORM=ROTATE;
break;
case  ROTATE_PVT:
TRANSFORM=ROTATE_PVT;
break;
}
glutPostRedisplay();
}

void scale(int id){
switch (id){
case SCALE:
TRANSFORM=SCALE;
break;
case  SCALE_PVT:
TRANSFORM=SCALE_PVT;
break;
}
glutPostRedisplay();
}

void draw_tri(){
glBegin(GL_LINE_LOOP);
for(int i=0;i<3;i++){
glVertex2f(tri[0][i],tri[1][i]);
}
glEnd();
}

void display(){
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1,0,0);
glBegin(GL_LINE_LOOP);
draw_tri();
glEnd();
switch(TRANSFORM){
case TRANSLATE:
glColor3f(0,1,0);
glPushMatrix();
glTranslatef(50,50,0);
draw_tri();
glPopMatrix();
break;

case ROTATE:
glColor3f(0,0,1);
glPushMatrix();
glRotatef(180,0,0,1);
draw_tri();
glPopMatrix();
break;
case ROTATE_PVT:
glColor3f(0,0,0);
glPushMatrix();
glTranslatef(50,50,0);
glRotatef(180,0,0,1);
glTranslatef(-50,50,0);
draw_tri();
glPopMatrix();
break;

case SCALE:
glColor3f(1,0,1);
glPushMatrix();

glScalef(2,2,0);

draw_tri();
glPopMatrix();
break;

case SCALE_PVT:
glColor3f(0,1,1);
glPushMatrix();
glTranslatef(100,100,0);
glScalef(0.5,0.5,0);
glTranslatef(-100,100,0);
draw_tri();
glPopMatrix();
break;
}


glFlush();
}

void init(){
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-250,250,-250,250);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("Basic 2d opetation using opengl functions");
init();
int rot_menu=glutCreateMenu(rot);
glutAddMenuEntry("Rotate",2);
glutAddMenuEntry("Rotate_pvt",3);
int sc_menu=glutCreateMenu(scale);
glutAddMenuEntry("Scale",4);
glutAddMenuEntry("Scale Pvt",5);
glutDisplayFunc(display);
glutCreateMenu(menu);
glutAddMenuEntry("Exit",0);
glutAddMenuEntry("Transform",1);
glutAddSubMenu("Rotation",rot_menu);
glutAddSubMenu("Scale",sc_menu);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
return 0;
}