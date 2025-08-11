//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glut.h>

#include <GL/glut.h> 

void initFlor(void){

	glClearColor(0.0, 0.0, 0.0, 0.0);

	gluOrtho2D(0.0, 500.0, 0, 500.0);

}

void florFunc(void){

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, .0, .0);
	glBegin(GL_POLYGON);
		glVertex2i(248, 250);
		glVertex2i(251, 250);
		glVertex2i(248, 100);
		glVertex2i(251,100);
	glEnd();

	glColor3f(.0, 1.0, .0);
	glBegin(GL_TRIANGLES);
		glVertex2i(250, 250);
		glVertex2i(230, 200);
		glVertex2i(270, 200);
	glEnd();

	glColor3f(.5, .5, .0);
	glBegin(GL_TRIANGLES);
		glVertex2i(250, 250);
		glVertex2i(200, 230);
		glVertex2i(200, 270);
	glEnd();

	glColor3f(1.0, 1.0, .0);
	glBegin(GL_TRIANGLES);
		glVertex2i(250, 250);
		glVertex2i(230, 300);
		glVertex2i(270, 300);
	glEnd();

	glColor3f(.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
		glVertex2i(250, 250);
		glVertex2i(300, 270);
		glVertex2i(300, 230);
	glEnd();

	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Flor de Abril");

	initFlor();

	glutDisplayFunc(florFunc);

	glutMainLoop();	

}