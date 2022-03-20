#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void box1();
void tri1();
void tri2();
void line1();
void display();
void SpecialInput(int key, int x, int y);
void movePosition();
void mouseMonitor(int button, int state, int x, int y);
void keyboardMonitor(unsigned char key, int x, int y);

int r = 244, g = 238, b = 169;	 // for the left eye
int r1 = 240, g1 = 187, b1 = 98; // for the right eye

float xpos = 0.0f float ypos = 0.0f;

int i = 1;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("face");
	glutDisplayFunc(display);
	glutSpecialFunc(SpecialInput);
	glutMouseFunc(mouseMonitor);
	glutKeyboardFunc(keyboardMonitor);
	glutMainLoop();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	box1();
	tri1();
	tri2();
	line1();
	glFlush();
}

void box1()
{
	glColor3ub(187, 100, 100);

	glBegin(GL_POLYGON);
	glVertex2f(-0.97f, -0.97f);
	glVertex2f(-0.97f, 0.97f);
	glVertex2f(0.97f, 0.97f);
	glVertex2f(0.97f, -0.97f);
	glEnd();
}

void tri1()
{ // left eye
	glColor3ub(r, g, b);

	glBegin(GL_TRIANGLES);
	glVertex2f(-.6f + xpos, .4f + ypos);  // left
	glVertex2f(-.15f + xpos, .4f + ypos); // right
	glVertex2f(-.38f + xpos, .8f + ypos); // middle
	glEnd();
}

void tri2()
{ // right eye
	glColor3ub(r1, g1, b1);

	glBegin(GL_TRIANGLES);
	glVertex2f(.6f + xpos, .4f + ypos);	 // left
	glVertex2f(.15f + xpos, .4f + ypos); // right
	glVertex2f(.38f + xpos, .8f + ypos); // middle
	glEnd();
}

void line1()
{
	glColor3ub(200, 242, 239);
	glLineWidth(5.0f);

	glBegin(GL_LINES);
	glVertex2f(-0.15 + xpos, 0 + ypos); // right
	glVertex2f(0.15 + xpos, 0 + ypos);	// left
	glEnd();
}

void SpecialInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		r += 5;
		g += 5;
		b += 10;
		break;
	case GLUT_KEY_RIGHT:
		r1 += 10;
		g1 += 5;
		b1 += 2;
		break;
	}
	glutPostRedisplay();
}

void mouseMonitor(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		r += 3;
		g += 5;
		b += 7;
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		r1 += 4;
		g1 += 2;
		b1 += 4;
	}
}

void keyboardMonitor(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
	case 'A':
		xpos -= .05f;
		break;

	case 's':
	case 'S':
		ypos -= .05f;
		break;

	case 'w':
	case 'W':
		ypos += .05f;
		break;

	case 'd':
	case 'D':
		xpos += .05f;
		break;

	// for esc key
	case 27:
		glutIdleFunc(movePosition);
		break;
	}
	glutPostRedisplay();
}

void movePosition()
{
	if (i <= 5)
	{
		// equivalent 1000 milliseconds or 1 second
		usleep(1000000);
		xpos += .05f;
		i++;
	}

	if (i == 6)
		exit(0);

	glutPostRedisplay();
}
