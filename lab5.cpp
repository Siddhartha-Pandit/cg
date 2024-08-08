#include <iostream>
#include <GL/glut.h>
float  ax=0, ay=0,az=0;
using namespace std;

float red_mat[4]={1,0,0,1};
float gray_mat[4]={0.7,0.7,0.7,1};
float yellow_mat[4]={1,1,0,1};
void car(){
glMaterialfv(GL_FRONT,GL_DIFFUSE,red_mat);
glutSolidCube(1);
glPushMatrix();
glMaterialfv(GL_FRONT,GL_DIFFUSE, yellow_mat);
glTranslatef(0.75,-0.25,0);
glScalef(0.5,0.5,0.5);
glutSolidCube(1);
glPopMatrix();

glMaterialfv(GL_FRONT,GL_DIFFUSE,gray_mat);
glPushMatrix();
glTranslatef(-0.35,-0.5,0.5);
glutSolidTorus(0.05,0.08,32,32);
glTranslatef(0,0,-1);
glutSolidTorus(0.05,0.08,32,32);
glPopMatrix();

glMaterialfv(GL_FRONT,GL_DIFFUSE,gray_mat);
glPushMatrix();
glTranslatef(0.35,-0.5,0.5);
glutSolidTorus(0.05,0.08,32,32);
glTranslatef(0,0,0-1);
glutSolidTorus(0.05,0.08,32,32);

glPopMatrix();

}


void mouse(int b,int s ,int x, int y){
if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN){
ax+=10;
}
else if(b==GLUT_MIDDLE_BUTTON && s==GLUT_DOWN){
ay+=10;
}
else if(b==GLUT_RIGHT_BUTTON && s==GLUT_DOWN){
az+=10;
}
if(ax>=360) ax-=360;
if(ay>=360) ay-=360;
if(az>=360) az-=360;

glutPostRedisplay();
}

 void display(){
glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);

glPushMatrix();
glRotatef(ax,1,0,0);
glRotatef(ay,0,1,0);
glRotatef(az,0,0,1);
car();
glPopMatrix();
glFlush();
}

void init(){
glMatrixMode(GL_PROJECTION);
glOrtho(-2,2,-2,2,-2,2);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char ** argv){

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB |GLUT_DEPTH | GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("3 rotation");
init();
glutDisplayFunc(display);
glutMouseFunc(mouse);
glEnable(GL_DEPTH_TEST);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_SMOOTH);
glEnable(GL_NORMALIZE);
glutMainLoop();
return 0;
}

