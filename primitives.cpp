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

void drawCuboid(float h, float l, float w, float x, float y) {
    for(float i = x-w/2;i <= x+w/2; i++) {
        glPushMatrix();
        for(float j = y-l/2; j <= y + l/2; j++) {
            glPushMatrix();
            glTranslatef(i, j, h/2);
            glutSolidCube(h);
            glPopMatrix();
        }
        glPopMatrix();
    }
}

void drawCuboidVertical(float w, float h, float l, float x, float y) {
    for(float i = x;i <= x+h; i++) {
        glPushMatrix();
        for(float j = y-l/2; j <= y + l/2; j++) {
            glPushMatrix();
            glTranslatef(x, j, i-x + w/2);
            glutSolidCube(w);
            glPopMatrix();
        }
        glPopMatrix();
    }
}

void drawCuboidParallel(float w, float h, float l, float x, float y) {
    for(float i = x-l/2;i <= x+l/2; i++) {
        glPushMatrix();
        for(float j = y; j <= y + h; j++) {
            glPushMatrix();
            glTranslatef(i, y, j-y + w/2);
            glutSolidCube(w);
            glPopMatrix();
        }
        glPopMatrix();
    }
}

Ground::Ground(float w, float l) {
    this->width = w;
    this->length = l;
}

void Ground::drawGround() {
    float w = this->width;
    float l = this->length;
    
    glColor3f(0.13, 0.5, 0.1);
    glPushMatrix();
    drawQuad(w/2, l/2, 0, -w/2, l/2, 0, -w/2, -l/2, 0, w/2, -l/2, 0);
    glPopMatrix();
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
    glPushMatrix();
    drawQuad(5, l/2, 0.1, -5, l/2, 0.1, -5, -l/2, 0.1, 5, -l/2, 0.1);

    drawQuad(w/2, 5, 0.1, -w/2, 5, 0.1, -w/2, -5, 0.1, w/2, -5, 0.1);
    glPopMatrix();
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
    glColor3ub(102,156,178);
    draw_circle(0.0f, 0.0f, 0.1f, 3.5);

    glTranslatef(0, 0, 0);
    glColor3ub(126,103,61);
    gluCylinder(quad, 2, 2, 1.5, 50, 20);
    draw_circle(0.0f, 0.0f, 1.5f, 2);
    glColor3ub(102,156,178);
    draw_circle(0.0f, 0.0f, 0.1f, 1.5);

    glColor3ub(126,103,61);
    glTranslatef(0, 0, 0);
    gluCylinder(quad, 1, 1, 2.0f, 50, 20);
    draw_circle(0.0f, 0.0f, 2.0f, 1);
}

void drawSpikeBushBranch() {
    glPushMatrix();
    glRotatef(20, 0, 1, 0);

    glColor3ub(0,100,0);
    glutSolidCone(0.1, 0.5, 20, 20);
    glTranslatef(0, 0, 0.39);
    glRotatef(15, 0, 1, 0);

    glColor3ub(107,142,35);
    glutSolidCone(0.1, 0.5, 20, 20);
    glTranslatef(0, 0, 0.39);
    glRotatef(10, 0, 1, 0);

    glColor3ub(107,142,35);
    glutSolidCone(0.1, 0.5, 20, 20);
    glTranslatef(0, 0, 0.39);
    glRotatef(8, 0, 1, 0);

    glColor3ub(107,142,35);
    glutSolidCone(0.1, 0.5, 20, 20);
    glTranslatef(0, 0, 0.39);
    glRotatef(1, 0, 1, 0);

    glColor3ub(34,139,34);
    glutSolidCone(0.1, 0.5, 20, 20);
    glTranslatef(0, 0, 0.39);

    glColor3ub(64,109,34);
    glutSolidCone(0.1, 0.5, 20, 20);
    glPopMatrix();
}

void drawSpikeBush(float x, float y) {

    glPushMatrix();

    glTranslatef(x, y, -4.05f);
    drawSpikeBushBranch();

    for(int i = 0;i <= 18; i++) {
        glRotatef(20, 0, 0, 1);
        drawSpikeBushBranch();
    }

    glPopMatrix();
}

void Ground::drawBushes() {

    glPushMatrix();

    float x = 10;

    while(x <= this->width/2 - 10) {
        drawSpikeBush(x, 0);
        x += 10;
    }

    x = -10;

    while(x >= -this->width/2 + 10) {
        drawSpikeBush(x, 0);
        x -= 10;
    }

    float y = 10;

    while(y <= this->length/2 - 10) {
        drawSpikeBush(0, y);
        y += 10;
    }

    y = -10;

    while(y >= -this->length/2 + 10) {
        drawSpikeBush(0, y);
        y -= 10;
    }

    glPopMatrix();
}

void Ground::drawGroundAll() {

    glPushMatrix();

    glTranslatef(-20, 0, 0);
    drawGround();
    drawFootPathBorders();
    drawFootPathBase();
    drawFootPathBushes();
    drawFootPathFountainBase();
    drawBushes();

    glPopMatrix();
}

CBlock::CBlock(float x, float y) {
    this->x = x;
    this->y = y;
}

void CBlock::drawStage() {
    float x = this->x;
    float y = this->y;

    //glTranslatef(x, y, 0.1);
    
    glColor3ub(85, 87, 86);
    //drawQuad(x-10, y + 20, 0.2, x-20, y + 20, 0.2, x-20, y - 20, 0.2, x-10, y-20, 0.2);

    glPushMatrix();
    drawCuboid(2, 30, 20, x, y);
    glTranslatef(0, 0, 2);
    drawCuboid(1, 28, 18, x, y);
    glTranslatef(0, 0, 1);
    drawCuboid(1, 26, 16, x, y);
    glTranslatef(0, 0, 1);
    drawCuboid(1, 24, 14, x, y);
    glPopMatrix();

    glPushMatrix();
    drawCuboidVertical(1, 5, 31, x+7, y);
    glTranslatef(0,0,5);
    glColor3ub(27, 31, 84);
    drawCuboidVertical(1, 6, 31, x+7, y);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 0);
    drawQuad(x+6.4, y-10, 12, x+6.4, y-8, 12, x+6.4, y-8, 10, x+6.4, y-10, 10);
    glColor3ub(53, 81, 92);
    drawQuad(x+6.4, y-8, 12, x+6.4, y-6, 12, x+6.4, y-6, 10, x+6.4, y-8, 10);
    glColor3ub(255, 0, 0);
    drawQuad(x+6.4, y-6, 12, x+6.4, y-4, 12, x+6.4, y-4, 10, x+6.4, y-6, 10);
    glPopMatrix();
}

void CBlock::drawSideBuildings() {
    float x = this->x;
    float y = this->y;

    glColor3ub(220,210,168);
    drawCuboid(2, 25, 20, x-0.2, y - 29.5);
    drawCuboid(2, 25, 20, x-0.2, y + 29.5);

    glPushMatrix();
    glTranslatef(0, 0, 23);
    drawCuboid(2, 25, 20, x, y - 29.5);
    drawCuboid(2, 25, 20, x, y + 29.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 11);
    drawCuboid(3, 24, 19, x, y - 29.5);
    drawCuboid(3, 24, 19, x, y + 29.5);
    glPopMatrix();

    glPushMatrix();
    drawCuboidVertical(3, 22, 24, x + 9.5, y - 29.5);
    drawCuboidVertical(3, 22, 24, x + 9.5, y + 29.5);
    glPopMatrix();


    drawCuboidParallel(2, 22, 19, x-0.5, y - 42);
    drawCuboidParallel(2, 22, 19, x-0.5, y + 42);

    drawCuboidParallel(2, 22, 5, x + 7, y - 17);
    drawCuboidParallel(2, 22, 5, x + 7, y + 17);

    glPushMatrix();
    glColor3ub(127,67,43);
    glTranslatef(0, 0, 2);
    drawCuboidVertical(2,2, 22, x-10, y-29.5);
    drawCuboidVertical(2,2, 22, x-10, y+29.5);
    glPopMatrix();

    drawCuboidVertical(2,21.5, 1, x-10.1, y-20.5);
    drawCuboidVertical(2,21.5, 1, x-10.1, y-26.0);
    drawCuboidVertical(2,21.5, 1, x-10.1, y-31.5);
    drawCuboidVertical(2,21.5, 1, x-10.1, y-37.0);

    drawCuboidVertical(2,21.5, 1, x-10.1, y+20.5);
    drawCuboidVertical(2,21.5, 1, x-10.1, y+26.0);
    drawCuboidVertical(2,21.5, 1, x-10.1, y+31.5);
    drawCuboidVertical(2,21.5, 1, x-10.1, y+37.0);
}

void drawHemisphere(double r, int lats, int longs) 
{
    int i, j;
    int halfLats = lats / 2; 
    for(i = 0; i <= halfLats; i++) 
    {
        double lat0 = M_PI * (-0.5 + (double) (i - 1) / lats);
        double z0 = sin(lat0);
        double zr0 = cos(lat0);

        double lat1 = M_PI * (-0.5 + (double) i / lats);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for(j = 0; j <= longs; j++)
        {
            double lng = 2 * M_PI * (double) (j - 1) / longs;
            double x = cos(lng);
            double y = sin(lng);

            // glTexCoordf()
            glNormal3f(x * zr0, y * zr0, -z0);
            glVertex3f(x * zr0, y * zr0, -z0);       

            // glTexCoordf()
            glNormal3f(x * zr1, y * zr1, -z1);
            glVertex3f(x * zr1, y * zr1, -z1);
        }
        glEnd();
    }
}

void CBlock::drawMainBuilding() {
    float x = this->x;
    float y = this->y;

    glColor3ub(85, 87, 86);
    drawCuboid(2, 180, 40, x+30, y);

    glPushMatrix();
    glColor3ub(220,210,168);
    glTranslatef(0, 0, 40);
    drawCuboid(2, 115, 40, x+30, y);
    glTranslatef(0, 0, -2);
    drawCuboid(2, 50, 40, x+30, y);
    glPopMatrix();

    glPushMatrix();
    drawCuboidVertical(2, 20, 50, x+10, y);
    drawCuboidParallel(2, 38, 40, x+30, y + 25);
    drawCuboidParallel(2, 38, 40, x+30, y - 25);
    glTranslatef(0, 0, 20);
    drawCuboidVertical(2, 20, 25, x+10, y + 25);
    drawCuboidVertical(2, 20, 25, x+10, y - 25);
    drawCuboidVertical(2, 20, 3, x+10, y + 5);
    drawCuboidVertical(2, 20, 3, x+10, y - 5);
    glPopMatrix();

    glPushMatrix();
    drawCuboid(2, 20, 20, x-20, y-55);
    drawCuboid(2, 20, 20, x-20, y+55);
    glTranslatef(0, 0, 30);
    drawCuboid(10, 13.2, 13.2, x-20, y-55);
    drawCuboid(10, 13.2, 13.2, x-20, y+55);
    glPopMatrix();

    drawCuboidParallel(4, 30, 1.5, x-28.35, y - 46);
    drawCuboidParallel(4, 30, 1.5, x-28.35, y + 46);

    drawCuboidParallel(2, 30, 39, x-11, y - 65.3);
    drawCuboidParallel(2, 30, 39, x-11, y + 65.3);
    
    //drawCuboidVertical(2, 30, 25, x + 9, y - 78.3);
    drawCuboidParallel(2, 30, 40, x + 30, y - 90.3);
    drawCuboidParallel(2, 30, 40, x + 30, y + 90.3);

    glColor3ub(145, 127, 87);
    drawCuboidVertical(2, 40, 80, x + 50, y);
    drawCuboidVertical(2, 30, 60, x + 50, y-60);
    drawCuboidVertical(2, 30, 60, x + 50, y+60);

    glPushMatrix();
    glColor3ub(220,210,168);
    glTranslatef(0, 0, 30);
    drawCuboid(2, 40, 40, x + 30, y - 70.3);
    drawCuboid(2, 40, 40, x + 30, y + 70.3);
    glPopMatrix();

    glColor3ub(145, 127, 87);
    glTranslatef(x+30, y, 42);
    glScalef(20, 20, 20);
    drawHemisphere(100, 100, 100);
}

void CBlock::drawCBlock() {
    glPushMatrix();
    drawStage();
    drawSideBuildings();
    drawMainBuilding();
    glPopMatrix();
}

Library::Library(float x, float y) {
    this->x = x;
    this->y = y;
}

void Library::drawSideBuilding() {

    float x = this->x;
    float y = this->y;

    glPushMatrix();
    glColor3ub(220,210,168);
    drawCuboid(2, 20, 20, x-83.5, y-5.5);
    glTranslatef(0, 0, 30);
    drawCuboid(10, 13.2, 13.2, x-83.5, y-5.5);
    glPopMatrix();

    drawCuboidParallel(4, 30, 1.5, x-74.8, y - 14.5);
}

void Library::drawMainBuilding() {
    float x = this->x;
    float y = this->y;
    
    glPushMatrix();
    glColor3ub(85, 87, 86);
    glTranslatef(0, 0, -1);
    drawCuboid(2, 50, 165, x - 10, y + 30);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(220,210,168);
    glTranslatef(0, 0, 15);
    drawCuboid(6, 50, 165, x - 10, y + 30);
    glTranslatef(0, 0, 18);
    drawCuboid(6, 50, 165, x - 10, y + 30);
    glPopMatrix();
}

void Library::drawLibrary() {
    drawMainBuilding();
    drawSideBuilding();
} 