//Lab1 breshenmhams
#include <iostream>
#include <GL/glut.h>
#include<cmath>
using namespace std;
float ax,ay,bx,by;

void draw_pixel(float x, float y){
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}

void bres(){
    float dx=bx-ax;
    float dy=by-ay;
    float m=dy/dx;
    float inc =1;
    if(abs(m)<0){
        inc-=1;
    }
    dx=abs(dx);
    dy=abs(dy);
    if(m<1){
    if(bx<ax){
        swap(ax,ay);
        swap(bx,by);
    }
    float x=ax;
    float y=ay;
    float p=2*dy-dx;
    while(x<=bx){
        if(p<0){
            p+=2*dy;
        }
        else{
            y+=inc;
            p+=2*dy-2*dx;
            }
        draw_pixel(x,y);
        x++;
    }
    }
    else{
if (by<bx){
swap(ax,ay);
swap(bx,by);
}
float x=ax;
float y=ay;
float p=2*dx-dy;
while(y<=by){
if(p<0){
p+=2*dx;
}
else{
x+=inc;
p+=2*dx-dy;
}
draw_pixel(x,y);
y++;
}
}

}


void display(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
bres();
glColor3f(1,0,0);
draw_pixel(ax,ay);
draw_pixel(bx,by);
glFlush();
}
void init(){
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,499,0,499);
glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char ** argv){
cout<<"Enter ax,ay, bx,by"<<endl;
cin >>ax>>ay>>bx>>by;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("Bresenhams");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}