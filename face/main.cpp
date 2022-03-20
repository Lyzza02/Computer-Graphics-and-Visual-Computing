#include<GL/glut.h>
#include<iostream>

using namespace std;

void box1();
void tri1();
void tri2();
void line1();
void display();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("face");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  box1();
  tri1();
  tri2();
  line1();
  glFlush();
}

void box1(){
	glColor3ub(187, 100, 100);
	
	glBegin(GL_POLYGON);
	glVertex2f(-0.97f, -0.97f);
	glVertex2f(-0.97f, 0.97f);
	glVertex2f(0.97f, 0.97f);
	glVertex2f(0.97f, -0.97f);
  glEnd();
}

void tri1(){
	glColor3ub(244, 238, 169);
	
	glBegin(GL_TRIANGLES);
	glVertex2f(-.6f, .4f); //left
	glVertex2f(-.15f, .4f); // right
	glVertex2f(-.38f,.8f); //middle
  glEnd();
}

void tri2(){
	glColor3ub(240, 187, 98);
	
	glBegin(GL_TRIANGLES);
	glVertex2f(.6f, .4f); //left
	glVertex2f(.15f, .4f); // right
	glVertex2f(.38f, .8f); //middle
  glEnd();
}

void line1(){
	glColor3ub(200, 242, 239);
	glLineWidth(5.0f);
	
	glBegin(GL_LINES);
	glVertex2f(-0.15, 0); //right
	glVertex2f(0.15, 0); //left
  glEnd();
}
