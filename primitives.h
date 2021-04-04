#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

/**
 * Draws a quadrilateral face
 * @param[in] a1 x coordinate of first point
 * @param[in] a2 y coordinate of first point
 * @param[in] a3 z coordinate of first point
 * @param[in] b1 x coordinate of second point
 * @param[in] b2 y coordinate of second point
 * @param[in] b3 z coordinate of second point
 * @param[in] c1 x coordinate of third point
 * @param[in] c2 y coordinate of third point
 * @param[in] c3 z coordinate of third point
 * @param[in] d1 x coordinate of fourth point
 * @param[in] d2 y coordinate of fourth point
 * @param[in] d3 z coordinate of fourth point
*/
void drawQuad(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3, float d1, float d2, float d3);

class Ground {
    float width;
    float length;
    float x;
    float y;

    public:
        Ground(float w, float l);
        void drawGround();
        void drawFootPathBorders();
        void drawFootPathBase();
        void drawFootPathBushes();
        void drawFootPathFountainBase();
        void drawBushes();
        void drawGroundAll();
};

class CBlock {
    float x;
    float y;

    public:
        CBlock(float x, float y);
        void drawStage();
        void drawCBlock();
        void drawSideBuildings();
        void drawMainBuilding();
};

class Library {
    float x;
    float y;

    public:
        Library(float x, float y);
        void drawSideBuilding();
        void drawLibrary();
        void drawMainBuilding();
};

class Auditorium {
    float x;
    float y;

    public:
        Auditorium(float x, float y);
        void drawAuditorium();
};