/**
 * @file main.cpp
 * This is the driver file for the scene creation. It initializes glut and calls its methods
*/

/*
Group Members

Sukrit - 2018A7PS0205H
Jay Karhade - 2018A3PS0852H
Siddharth Jagota - 2018A7PS0166H
*/

//Necessary imports
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "primitives.h"

using namespace std;

double zoom = 0.5; //!< Stores the current zoom of the window

//Rotation Variables
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

//Translation Variables
float translateX = 1.5f;
float translateY = 0.0f;
float translateZ = -100.0f;

GLuint bush_main;

void loadObj(char const *fname) {
	FILE *fp;
	int read;
	GLfloat x, y, z;
	char ch;
	bush_main=glGenLists(1);
	fp=fopen(fname,"r");
	if (!fp) 
    {
        printf("can't open file %s\n", fname);
		exit(1);
    }
	glPointSize(2.0);
	glNewList(bush_main, GL_COMPILE);
	{
		glPushMatrix();
		glBegin(GL_TRIANGLE_STRIP);
		while(!(feof(fp)))
 		{
  			read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
  			if(read==4&&ch=='v')
  			{
   				glVertex3f(x,z,y);
  			}
 		}
		glEnd();
	}
	glPopMatrix();
	glEndList();
	fclose(fp);
}

void drawBush()
{
    //glTranslatef(x,y,-1);
    glPushMatrix();
    glColor3ub(34,139,34);
    glScalef(3,3,3);
    glCallList(bush_main);
    glPopMatrix();
    //glTranslatef(-x,-y,1);
}

/**
 * Sets properties of the GLUT library to make it ready for 3D rendering
*/
void myInit() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
    glEnable(GL_LIGHT5);
    glEnable(GL_LIGHT6);
    glEnable(GL_LIGHT7);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
}

/**
 * Draws the scene
*/
void Draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(1,0.79,0.79,0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(translateX, translateY, translateZ);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
    glScalef(0.3, 0.3, 0.3);
 
    Ground *ground = new Ground(150, 130);
    (*ground).drawGroundAll();

    CBlock *cblock = new CBlock(60, 0);
    (*cblock).drawCBlock();

    Library *library = new Library(0, 60);
    (*library).drawLibrary();

    Auditorium *auditorium = new Auditorium(-120, 0);
    (*auditorium).drawAuditorium();

    glPushMatrix();
    glTranslatef(12,  42.5, 2);
    drawBush();
    glTranslatef(12.112,  0, 0);
    drawBush();
    glTranslatef(12.114,  0, 0);
    drawBush();
    glTranslatef(12.116,  0, 0);
    drawBush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12,  42.5, 2);
    drawBush();
    glTranslatef(-12.112,  0, 0);
    drawBush();
    glTranslatef(-12.114,  0, 0);
    drawBush();
    glTranslatef(-12.116,  0, 0);
    drawBush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12,  -77.5, 2);
    drawBush();
    glTranslatef(12.112,  0, 0);
    drawBush();
    glTranslatef(12.114,  0, 0);
    drawBush();
    glTranslatef(12.116,  0, 0);
    drawBush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12,  -77.5, 2);
    drawBush();
    glTranslatef(-12.112,  0, 0);
    drawBush();
    glTranslatef(-12.114,  0, 0);
    drawBush();
    glTranslatef(-12.116,  0, 0);
    drawBush();
    glPopMatrix();

    glutSwapBuffers();
}

/**
 * Handles the regular keystrokes
 * @param[in] key button that is pressed
 * @param[in] x current x coordinate
 * @param[in] y current y coordinate
*/
void RegularKeys(unsigned char key, int x, int y) {
    
    switch (key) {
        case 27:
            exit(0);

        case 'i':
            translateY -= 1.0f;
            break;

        case 'k':
            translateY += 1.0f;
            break;

        case 'w':
            angleX += 1.5f;
            break;

        case 's':
            angleX -= 1.5f;
            break;

        case 'a':
            angleY += 1.5f;
            break;

        case 'd':
            angleY -= 1.5f;
            break;

        case 'j':
            angleZ += 1.5f;
            break;

        case 'l':
            angleZ -= 1.5f;
            break;

        case 'r':
            angleX = 0.0f;
            angleY = 0.0f;
            angleZ = 0.0f;

            translateX = 0.0f;
            translateY = 0.0f;
            translateZ = -20.0f;
    }

    glutPostRedisplay();
}

/**
 * Handles the special keystrokes
 * @param[in] key button that is pressed
 * @param[in] x current x coordinate
 * @param[in] y current y coordinate
*/
void SpecialKeys(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_UP:
            translateZ += 1.0f;
            break;
        
        case GLUT_KEY_DOWN:
            translateZ -= 1.0f;
            break;

        case GLUT_KEY_LEFT:
            translateX -= 1.0f;
            break;

        case GLUT_KEY_RIGHT:
            translateX += 1.0f;
            break;
    }

    glutPostRedisplay();
}

/**
 * Handles the mouse click
 * @param[in] button button that is pressed (left or right)
 * @param[in] state button up or down
 * @param[in] x current x coordinate
 * @param[in] y current y coordinate
*/
void Mouse(int button, int state, int x, int y) {
    if(state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON) {
        angleY += 10;
    } else if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
        angleY -= 10;
    } else if(state == GLUT_DOWN && button == 3) {
        angleX += 5;
    } else if(state == GLUT_DOWN && button == 4) {
        angleX -= 5;
    }

    glutPostRedisplay();
}

/**
 * Handles the mouse wheel scroll
 * @param[in] wheel mouse wheel
 * @param[in] direction direction of scroll
 * @param[in] x current x coordinate
 * @param[in] y current y coordinate
*/
void MouseWheel(int wheel, int direction, int x, int y) {
    wheel = 0;

    if(direction == -1) {
        zoom -= 0.5;
    } else if(direction == 1) {
        zoom += 0.5;
    }

    glutPostRedisplay();
}

/**
 * Handles the resize of the GLUT window
 * @param[in] w width of the viewport
 * @param[in] h height of the viewport
*/
void HandleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

/**
 * Driver function for drawing the scene using GLUT library
*/
int main(int argc, char **argv) {
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);

    //Window Properties
    glutCreateWindow("Scene in OpenGL");
    
    //Customise GLUT
    myInit();

    //Set handler functions
    glutDisplayFunc(Draw);
    glutKeyboardFunc(RegularKeys);
    glutSpecialFunc(SpecialKeys);
    glutMouseFunc(Mouse);
    glutMouseWheelFunc(MouseWheel);
    glutReshapeFunc(HandleResize);

    char const* fname = "bush.obj";

    loadObj(fname);

    glutMainLoop();

    return 0;
}