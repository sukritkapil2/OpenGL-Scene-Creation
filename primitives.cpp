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