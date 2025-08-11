#include <GL/glut.h>

float rotationAngle = 0.0;

float rotationSpeed = 0.5; 

bool isRotatingLeft = false;
bool isRotatingRight = false;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 500.0, 0, 500.0);
}

void renderText(float x, float y, const char *text) {
    glRasterPos2f(x, y);

    for (const char *c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2i(248, 250);
        glVertex2i(251, 250);
        glVertex2i(251, 100);
        glVertex2i(248, 100);
    glEnd();

    glPushMatrix();
    
    glTranslatef(250.0, 250.0, 0.0);
    glRotatef(rotationAngle, 0.0, 0.0, 1.0); 
    glTranslatef(-250.0, -250.0, 0.0);

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(230, 200);
        glVertex2i(270, 200);
    glEnd();

    glColor3f(0.5, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(200, 230);
        glVertex2i(200, 270);
    glEnd();
 
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(230, 300);
        glVertex2i(270, 300);
    glEnd();
 
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(300, 270);
        glVertex2i(300, 230);
    glEnd();

    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);
    renderText(20.0, 460.0, "RMB to rotate right");
    renderText(20.0, 440.0, "LMB to rotate left");

    glFlush();
}

void update(void) {
    bool needsRedraw = false;

    if (isRotatingLeft) {
        rotationAngle += rotationSpeed;
        needsRedraw = true;
    }
    if (isRotatingRight) {
        rotationAngle -= rotationSpeed;
        needsRedraw = true;
    }

    if (needsRedraw) {
        glutPostRedisplay();
    }
}

void handleMouseClick(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        switch (button) {
            case GLUT_LEFT_BUTTON:
                isRotatingLeft = true;
                isRotatingRight = false;
                break;
            case GLUT_RIGHT_BUTTON:
                isRotatingRight = true;
                isRotatingLeft = false;
                break;
        }
    }
    else if (state == GLUT_UP) {
        isRotatingLeft = false;
        isRotatingRight = false;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Catavento");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(handleMouseClick);
    glutIdleFunc(update);

    glutMainLoop();
    
    return 0;
}