#include<GL/glut.h>
#include<iostream>

using namespace std;

void box1();
void box2();
void display();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("simple");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  box1();
  box2();
  glFlush();
}

void box1(){
  glBegin(GL_POLYGON);
     //add code here
 
  glVertex2f(-0.80, 0.20);
  glVertex2f(-0.20, 0.20);
  glVertex2f(-0.20, 0.80);
  glVertex2f(-0.80, 0.80);
  glEnd();

}

void box2(){
  glBegin(GL_POLYGON);
     //add code here
  glVertex2f(0.80, -0.20);
  glVertex2f(0.20, -0.20);
  glVertex2f(0.20, -0.80);
  glVertex2f(0.80, -0.80);
  glEnd();
}

