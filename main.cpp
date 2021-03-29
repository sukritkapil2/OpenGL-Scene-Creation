/**
 * @file main.cpp
 * This is the driver file for the scene creation. It initializes glut and calls its methods
*/

//Necessary imports
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "primitives.h"

using namespace std;

/**
 * Sets properties of the GLUT library to make it ready for 3D rendering
*/
void myInit() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
}

/**
 * Draws the scene
*/
void Draw() {

}

/**
 * Handles the regular keystrokes
 * @param[in] key button that is pressed
 * @param[in] x current x coordinate
 * @param[in] y current y coordinate
*/
void RegularKeys(unsigned char key, int x, int y) {

}

/**
 * Handles the special keystrokes
 * @param[in] key button that is pressed
 * @param[in] x current x coordinate
 * @param[in] y current y coordinate
*/
void SpecialKeys(int key, int x, int y) {

}

/**
 * Handles the mouse click
 * @param[in] button button that is pressed (left or right)
 * @param[in] state button up or down
 * @param[in] x current x coordinate
 * @param[in] y current y coordinate
*/
void Mouse(int button, int state, int x, int y) {

}

/**
 * Handles the mouse wheel scroll
 * @param[in] wheel mouse wheel
 * @param[in] direction direction of scroll
 * @param[in] x current x coordinate
 * @param[in] y current y coordinate
*/
void MouseWheel(int wheel, int direction, int x, int y) {

}

/**
 * Handles the resize of the GLUT window
 * @param[in] w width of the viewport
 * @param[in] h height of the viewport
*/
void HandleResize(int w, int h) {

}

/**
 * Driver function for drawing the scene using GLUT library
*/
int main(int argc, char **argv) {
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);

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

    glutMainLoop();
}