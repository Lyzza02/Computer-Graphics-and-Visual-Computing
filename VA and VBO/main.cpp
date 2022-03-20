#define GLEW_STATIC

#include<iostream>
#include<GL/glew.h>
#include<GL/glut.h>

using namespace std;

void rectangle();
void triangle();
void display();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("face");
   glutDisplayFunc(display);
   
   GLenum err = glewInit();
   if (err == GLEW_OK){
   	glutMainLoop();
   }
}


void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  triangle();
  rectangle();
  glFlush();
}

void triangle(){
	glColor3ub(244, 238, 169);
	
	GLfloat tri_vertex[] = {
		-.4f, .4f, 0.0f, // left
		.4f, .4f, 0.0f, //right
		0.0f, .8f, 0.0f //middle
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, tri_vertex);
	glDrawArrays(GL_TRIANGLES,0,3);
	glDisableClientState(GL_VERTEX_ARRAY);
	
}

void rectangle(){
	glColor3ub(154, 220, 255);
	
	GLfloat rec_vertex[] = {
		-0.6f, -0.2f, 0.0f, //left bottom
		-0.6f, .4f, 0.0f, //left top
		0.6f, .4f, 0.0f, //right top
		0.6f, -0.2f, 0.0f //right bottom
	};
	
	GLuint VBOid;
	glGenBuffers(1, &VBOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*12, rec_vertex, GL_STATIC_DRAW);
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glDrawArrays(GL_POLYGON,0,8);
	
	//back to normal
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBOid);
}
