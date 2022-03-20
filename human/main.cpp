#define GLEW_STATIC

#include<iostream>
#include<GL/glew.h>
#include<GL/glut.h>

using namespace std;

void display();
void body();
void face();
void base_face();
void base_body();
void headband();
void eyes();
void nose();
void mouth();
void buttons();
void collar1();
void collar2();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutCreateWindow("Human");
   glutDisplayFunc(display);
   
   GLenum err = glewInit();
   if (err == GLEW_OK){
   	glutMainLoop();
   }
}


void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  body();
  face();
  glFlush();
}

void face(){
	base_face();
	headband();
	eyes();
	nose();
	mouth();
}

void body(){
	base_body();
	buttons();
	collar1();
	collar2();
}

void base_face(){
	glColor3ub(233, 218, 193);
	
	GLfloat rec_vertex[] = {
		-0.4f, 0.05f, 0.0f, //left bottom
		-0.4f, 0.85f, 0.0f, //left top
		0.4f, 0.85f, 0.0f, //right top
		0.4f, 0.05f, 0.0f //right bottom
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, rec_vertex);
	glDrawArrays(GL_QUADS,-0.4,4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void headband(){
	glColor3ub(148, 180, 159);
	
	GLfloat h_vertex[] = {
		-0.4f, 0.65f, 0.0f, //left bottom
		-0.4f, 0.75f, 0.0f, //left top
		0.4f, 0.75f, 0.0f, //right top
		0.4f, 0.65f, 0.0f //right bottom
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, h_vertex);
	glDrawArrays(GL_QUADS,-0.4,4);
	glDisableClientState(GL_VERTEX_ARRAY);
	
}

void eyes(){
	glColor3ub(105, 152, 171);
	
	GLfloat eyes_vertex[] = {
		//left-side (EYE)
		-0.3f, 0.43f, 0.0f, //left bottom
		-0.3f, 0.58f, 0.0f, //left top
		-0.15f, 0.58f, 0.0f, //right top
		-0.15f, 0.43f, 0.0f, //right bottom
		
		//right-side (EYE)
		0.3f, 0.43f, 0.0f, //left bottom
		0.3f, 0.58f, 0.0f, //left top
		0.15f, 0.58f, 0.0f, //right top
		0.15f, 0.43f, 0.0f, //right bottom
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, eyes_vertex);
	glDrawArrays(GL_QUADS,-0.3,8);
	glDisableClientState(GL_VERTEX_ARRAY);
	
}

void nose(){
	glColor3ub(206, 171, 147);
	
	GLfloat tri_vertex[] = {
		-.15f, .25f, 0.0f, // left
		.15f, .25f, 0.0f, //right
		0.0f, .55f, 0.0f //middle
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, tri_vertex);
	glDrawArrays(GL_TRIANGLES,-.15,3);
	glDisableClientState(GL_VERTEX_ARRAY);
	
}

void mouth(){
	glColor3ub(216, 133, 163);
	glLineWidth(2.0f);
	
	GLfloat line_vertex[] = {
		-.2f, .17f, 0.0f, // left
		.2f, .17f, 0.0f, //right
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, line_vertex);
	glDrawArrays(GL_LINES,-0.2,2);
	glDisableClientState(GL_VERTEX_ARRAY);
	
}

void base_body(){
	glColor3ub(216, 33, 72);
	
	GLfloat body_vertex[] = {
	    -0.2f, -0.75f, 0.0f,
	    0.2f, -0.75f, 0.0f,
	    
	    0.4f, -0.48f, 0.0f,
	    0.4f, -0.21f, 0.0f,
	    
	    0.2f,  0.05f, 0.0f,
	    -0.2f, 0.05f, 0.0f,
	    
	    -0.4f, -0.21f, 0.0f,
	    -0.4f, -0.48f, 0.0f
	};

  GLuint VBOid;
  glGenBuffers(1, &VBOid);
  glBindBuffer(GL_ARRAY_BUFFER, VBOid);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*24, body_vertex, GL_STATIC_DRAW);

  glEnableClientState(GL_VERTEX_ARRAY);

  glVertexPointer(3,GL_FLOAT,0,0);
  glDrawArrays(GL_POLYGON,-0.2,8);

  glDisableClientState(GL_VERTEX_ARRAY);
  glBindBuffer(GL_ARRAY_BUFFER,0);
  glDeleteBuffers(1, &VBOid);
}

void buttons(){
	glColor3ub(238, 195, 115);
	
	GLfloat b_vertex[] = {
	    -0.05f, -0.3f, 0.0f,
		-0.05f, -0.4f, 0.0f,
		0.05f, -0.4f, 0.0f,
		0.05f, -0.3f, 0.0f,
		
		-0.05f, -0.5f, 0.0f,
		-0.05f, -0.6f, 0.0f,
		0.05f, -0.6f, 0.0f,
		0.05f, -0.5f, 0.0f
	};

  GLuint VBOid;
  glGenBuffers(1, &VBOid);
  glBindBuffer(GL_ARRAY_BUFFER, VBOid);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*24, b_vertex, GL_STATIC_DRAW);

  glEnableClientState(GL_VERTEX_ARRAY);

  glVertexPointer(3,GL_FLOAT,0,0);
  glDrawArrays(GL_QUADS,-0.05,8);

  glDisableClientState(GL_VERTEX_ARRAY);
  glBindBuffer(GL_ARRAY_BUFFER,0);
  glDeleteBuffers(1, &VBOid);
}

void collar1(){
	glColor3ub(255, 195, 0);
	
	GLfloat b_vertex[] = {
		//back
		-.2f, .05f, 0.0f, // left
		.2f, .05f, 0.0f, //right
		0.0f, -.2f, 0.0f //middle
	};

  GLuint VBOid;
  glGenBuffers(1, &VBOid);
  glBindBuffer(GL_ARRAY_BUFFER, VBOid);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*9, b_vertex, GL_STATIC_DRAW);

  glEnableClientState(GL_VERTEX_ARRAY);
  
  glVertexPointer(3,GL_FLOAT,0,0);
  glDrawArrays(GL_TRIANGLES,-0.2,3);

  glDisableClientState(GL_VERTEX_ARRAY);
  glBindBuffer(GL_ARRAY_BUFFER,0);
  glDeleteBuffers(1, &VBOid);
}

void collar2(){
	glColor3ub(233, 218, 193);
	
	GLfloat b_vertex[] = {
		//front
		-.15f, .05f, 0.0f, // left
		.15, .05f, 0.0f, //right
		0.0f, -.13f, 0.0f //middle
	};

  GLuint VBOid;
  glGenBuffers(1, &VBOid);
  glBindBuffer(GL_ARRAY_BUFFER, VBOid);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*9, b_vertex, GL_STATIC_DRAW);

  glEnableClientState(GL_VERTEX_ARRAY);
  
  glVertexPointer(3,GL_FLOAT,0,0);
  glDrawArrays(GL_TRIANGLES,-.15,3);

  glDisableClientState(GL_VERTEX_ARRAY);
  glBindBuffer(GL_ARRAY_BUFFER,0);
  glDeleteBuffers(1, &VBOid);
}
