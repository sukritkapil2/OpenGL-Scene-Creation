#include "primitives.h"

using namespace std;

void drawQuad(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3, float d1, float d2, float d3) {
    glBegin(GL_QUADS);

    if(a3 == b3 && b3 == c3 && c3 == d3) glNormal3f(0, 0, 1);

    glVertex3f(a1, a2, a3);
    glVertex3f(b1, b2, b3);
    glVertex3f(c1, c2, c3);
    glVertex3f(d1, d2, d3);

    glEnd();
}

Ground::Ground(float w, float l) {
    this->width = w;
    this->length = l;
}

void Ground::drawGround() {
    float w = this->width;
    float l = this->length;
    
    glColor3f(0.13, 0.5, 0.1);
    drawQuad(w/2, l/2, 0, -w/2, l/2, 0, -w/2, -l/2, 0, w/2, -l/2, 0);
}

void Ground::drawFootPathBorders() {
    float w = this->width;
    float l = this->length;

    float y_coord = -l/2 + 0.5;
    glColor3ub(255, 255, 255);

    while(y_coord <= -5) {
        glPushMatrix();
        glTranslatef(-5, y_coord, 0.5);
        glutSolidCube(1);
        y_coord += 1;
        glPopMatrix();
    }

    y_coord = -l/2 + 0.5;
    glColor3ub(255, 255, 255);

    while(y_coord <= -5) {
        glPushMatrix();
        glTranslatef(5, y_coord, 0.5);
        glutSolidCube(1);
        y_coord += 1;
        glPopMatrix();
    }

    y_coord = 5;
    glColor3ub(255, 255, 255);

    while(y_coord <= l/2 - 0.5) {
        glPushMatrix();
        glTranslatef(-5, y_coord, 0.5);
        glutSolidCube(1);
        y_coord += 1;
        glPopMatrix();
    }

    y_coord = 5;
    glColor3ub(255, 255, 255);

    while(y_coord <= l/2 - 0.5) {
        glPushMatrix();
        glTranslatef(5, y_coord, 0.5);
        glutSolidCube(1);
        y_coord += 1;
        glPopMatrix();
    }

    float x_coord = 5;
    glColor3ub(255, 255, 255);

    while(x_coord <= w/2 - 0.5) {
        glPushMatrix();
        glTranslatef(x_coord, -5, 0.5);
        glutSolidCube(1);
        x_coord += 1;
        glPopMatrix();
    }

    x_coord = 5;
    glColor3ub(255, 255, 255);

    while(x_coord <= w/2 - 0.5) {
        glPushMatrix();
        glTranslatef(x_coord, 5, 0.5);
        glutSolidCube(1);
        x_coord += 1;
        glPopMatrix();
    }

    x_coord = -5;
    glColor3ub(255, 255, 255);

    while(x_coord >= -w/2 - 0.5) {
        glPushMatrix();
        glTranslatef(x_coord, 5, 0.5);
        glutSolidCube(1);
        x_coord -= 1;
        glPopMatrix();
    }

    x_coord = -5;
    glColor3ub(255, 255, 255);

    while(x_coord >= -w/2 - 0.5) {
        glPushMatrix();
        glTranslatef(x_coord, -5, 0.5);
        glutSolidCube(1);
        x_coord -= 1;
        glPopMatrix();
    }
}

void Ground::drawFootPathBase() {
    float w = this->width;
    float l = this->length;

    glColor3ub(174,149,94);
    drawQuad(5, l/2, 0.1, -5, l/2, 0.1, -5, -l/2, 0.1, 5, -l/2, 0.1);

    drawQuad(w/2, 5, 0.1, -w/2, 5, 0.1, -w/2, -5, 0.1, w/2, -5, 0.1);
}

void Ground::drawFootPathBushes() {
    float w = this->width;
    float l = this->length;

    float y_coord = -l/2 + 5;
    glColor3ub(0, 100, 0);

    while(y_coord <= -8) {
        glPushMatrix();
        glTranslatef(-0.8, y_coord, 1);
        glutSolidCube(2);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.8, y_coord, 1);
        glutSolidCube(2);
        glPopMatrix();
        
        y_coord += 1;
    }

    y_coord = 8;

    while(y_coord <= l/2-5) {
        glPushMatrix();
        glTranslatef(-0.8, y_coord, 1);
        glutSolidCube(2);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.8, y_coord, 1);
        glutSolidCube(2);
        glPopMatrix();
        
        y_coord += 1;
    }

    float x_coord = 8;

    while(x_coord <= w/2 - 5) {
        glPushMatrix();
        glTranslatef(x_coord, -0.8, 1);
        glutSolidCube(2);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(x_coord, 0.8, 1);
        glutSolidCube(2);
        glPopMatrix();
        
        x_coord += 1;
    }

    x_coord = -8;

    while(x_coord >= -w/2 + 5) {
        glPushMatrix();
        glTranslatef(x_coord, -0.8, 1);
        glutSolidCube(2);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(x_coord, 0.8, 1);
        glutSolidCube(2);
        glPopMatrix();
        
        x_coord -= 1;
    }
}

void draw_circle(float x, float y, float z, float radius) {
    glTranslatef(x, y, z);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;

    // this code (mostly) copied from question:
    glBegin(GL_POLYGON);
    glNormal3f(0, 0, 1);
    double angle1=0.0;
    glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    int i;
    for (i=0; i<circle_points; i++)
    {       
        glVertex2d(radius * cos(angle1), radius *sin(angle1));
        angle1 += angle;
    }
    glEnd();
}

void Ground::drawFootPathFountainBase() {
    GLUquadric *quad = gluNewQuadric();
    glTranslatef(0, 0, 0);
    glColor3ub(126,103,61);
    gluCylinder(quad, 4, 4, 2.5, 50, 20);

    draw_circle(0.0f, 0.0f, 2.5f, 4);
}