#include <iostream>
#include <GL/glut.h>
using namespace std;
float v[4][3]={{0,0,1},{-1,-1,-1},{1,-1,-1},{0,1,-1}};
int k=0;

void draw_tri( float a[3],float b[3],float c[3]){
glBegin(GL_TRIANGLES);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glEnd();
}
void div_tri(float a[3],float b[3],float c[3],int k){
if(k>0){
float m1[3],m2[3],m3[3];
for(int i=0;i<3;i++){
m1[i]=(a[i]+b[i])/2;
m2[i]=(a[i]+c[i])/2;
m3[i]=(b[i]+c[i])/2;
}
div_tri(a,m1,m2,k-1);
div_tri(b,m1,m3,k-1);
div_tri(c,m2,m3,k-1);
}
else{
draw_tri(a,b,c);
}
}

void tetrahedron(){
glColor3f(0,0,0);
div_tri(v[1],v[2],v[3],k);

glColor3f(1,0,0);
div_tri(v[0],v[1],v[2],k);

glColor3f(0,1,0);
div_tri(v[0],v[1],v[3],k);

glColor3f(0,0,1);
div_tri(v[0],v[2],v[3],k);
}

void display(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
tetrahedron();
glFlush();
}
void init(){
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
glOrtho(-2,2,-2,2,-2,2);
glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char **argv){
cout<<"how many fractal you want";
cin>>k;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH |GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("Fractal");
init();
glutDisplayFunc(display);
glutMainLoop();
return(0);
}
