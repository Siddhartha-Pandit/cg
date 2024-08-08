# include <iostream>
#include <GL/glut.h>
#define BLAST_ON 1
#define ROCKET 0
int flag=ROCKET;
float ty=0;
float viewer[3]={0,0,5};

void rocket(){
glColor3f(1,0,0);
glPushMatrix();
glTranslatef(0,1,0);
glRotatef(-90,1,0,0);
glutSolidCone(1.1,1.5,5,5);
glPopMatrix();
glColor3f(1,1,0);
glutSolidCube(2);

}
void display(){
glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);


if(flag==BLAST_ON){
glPushMatrix();
glTranslatef(0,ty,0);
glPushMatrix();
glTranslatef(0,-3,0);
rocket();

glPopMatrix();
ty+=0.1;
glPopMatrix();


}else if(flag==ROCKET){
ty=0;
glPushMatrix();
glTranslatef(0,-3,0);
rocket();
glPopMatrix();
}
glutSwapBuffers();
glFlush();
}

void keys(unsigned char key, int x, int y){
if (key=='x') viewer[0]+=0.2;
else if(key=='X') viewer[0]-=0.2;
else if(key=='y') viewer[1]+=0.2;
else if(key=='Y') viewer[1]-=0.2;
else if(key=='z') viewer[2]-=0.2;
else if(key=='Z') viewer[2]+=0.2;
else if(key=='b') flag=BLAST_ON;
else if(key=='r') flag=ROCKET;
glutPostRedisplay();
}

void init(){
glMatrixMode(GL_PROJECTION);
glOrtho(-5,5,-5,5,2,20);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
glutInitWindowSize(500,500);
glutCreateWindow("Rocket");
init();
glutDisplayFunc(display);
glutKeyboardFunc(keys);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}