#include<GL/glut.h>
#include<iostream>

using namespace std;

void base();
void chimney();
void line1();
void line2();
void line3();
void door();
void doorknob1();
void doorknob1_border();
void doorknob2();
void doorknob2_border();
void window();
void windowBorder();
void display();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("house");
   glutDisplayFunc(display);
   glutMainLoop();
}


void display(){
  glClear(GL_COLOR_BUFFER_BIT);

  base();
  chimney();
  door();
  doorknob1();
  doorknob1_border();
  doorknob2();
  doorknob2_border();
  line1();
  line2();
  line3();
  window();
  windowBorder();

  glFlush();
}

void base(){
	glColor3ub(187, 100, 100);

	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(0.0f, 0.7f); // top of the roof
	glVertex2f(-0.55f, 0.1f); // left corner
	glVertex2f(0.55f, 0.1f); // right corner 
	glVertex2f(-0.55f, -0.7f); // bottom left 
	glVertex2f(0.55f, -0.7f); //bottom right

	glEnd();
}

void chimney(){
	glColor3ub(178, 171, 140);
	
	glBegin(GL_POLYGON);
	glVertex2f(-0.45f, 0.7f); // left corner
	glVertex2f(-0.3f, 0.7f); // right corner
	glVertex2f(-0.3f, 0.42f); //bottom right 
	glVertex2f(-0.45f, 0.25f); // bottom left
	glEnd();
}

void door(){
	glColor3ub(227, 183, 160);
	
	glBegin(GL_QUADS);
	glVertex2f(-0.3f, -0.1f); // left corner
	glVertex2f(0.3f, -0.1f); // right corner
	glVertex2f(0.3f, -0.7f); // bottom right corner
	glVertex2f(-0.3f, -0.7f); // bottom left corner

	glEnd();
}

void doorknob1(){
	glColor3ub(172, 185, 146);
	
	glBegin(GL_QUADS);
	glVertex2f(-0.12f, -0.37f); // left corner
	glVertex2f(-0.045f, -0.37f); // right corner
	glVertex2f(-0.045f, -0.45f); // bottom right corner
	glVertex2f(-0.12f, -0.45f); // bottom left corner

	glEnd();
}

void doorknob1_border(){
	glColor3ub(255, 237, 219);
	glLineWidth(2.0f);
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.12f, -0.37f); // left corner
	glVertex2f(-0.045f, -0.37f); // right corner
	glVertex2f(-0.045f, -0.45f); // bottom right corner
	glVertex2f(-0.12f, -0.45f); // bottom left corner

	glEnd();
}

void doorknob2(){
	glColor3ub(172, 185, 146);
	
	glBegin(GL_QUADS);
	glVertex2f(0.12f, -0.37f); // left corner
	glVertex2f(0.045f, -0.37f); // right corner
	glVertex2f(0.045f, -0.45f); // bottom right corner
	glVertex2f(0.12f, -0.45f); // bottom left corner

	glEnd();
}

void doorknob2_border(){
	glColor3ub(255, 237, 219);
	glLineWidth(2.0f);
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.12f, -0.37f); // left corner
	glVertex2f(0.045f, -0.37f); // right corner
	glVertex2f(0.045f, -0.45f); //bottom right corner
	glVertex2f(0.12f, -0.45f); // bottom left corner

	glEnd();
}

void line1(){
	glColor3ub(255, 237, 219);
	glLineWidth(3.0f);

	glBegin(GL_LINES);
	//division of the door
	glVertex2f(-0.0f, -.1f);
	glVertex2f(-0.0f, -.7f);
	
	glEnd();
}

void line2(){
	glColor3ub(255, 237, 219);
	glLineWidth(3.0f);

	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.3f, -.7f);
	glVertex2f(-0.3f, -.1f);
	glVertex2f(0.3f, -.1f); 
	glVertex2f(0.3f, -.7f); 
	
	glEnd();
}

void line3(){
	glColor3ub(200, 242, 239);
	glLineWidth(5.0f);
	
	glBegin(GL_LINES);
	glVertex2f(-0.15f, 0.0f);
	glVertex2f(0.15f, 0.0f);
	
	glEnd();
}

void window(){
	glColor3ub(154, 208, 236);

	glBegin(GL_TRIANGLES);
	glVertex2f(-.15f, .3f); //left
	glVertex2f(.15f, .3f); // right
	glVertex2f(.0f, .5f); //middle
	
	
	glVertex2f(-.15f, .3f); //left
	glVertex2f(.15f, .3f); // right
	glVertex2f(.0f, .1f); //middle
	
	glEnd();
}

void windowBorder(){
	glEnable(GL_LINE_STIPPLE);
	glColor3ub(209, 209, 209);
	glLineWidth(2.0f);
	glLineStipple(4, 0xAAAA );
	
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.5f, -0.7f); // bottom left
	glVertex2f(-0.5f, 0.1f); //upper left
	
	glVertex2f(0.0f, 0.65f);
	glVertex2f(0.5f, 0.1f);
	
	glVertex2f(0.5f, 0.1f); //upper right
	glVertex2f(0.5f, -0.7f); //bottom right
	
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}
