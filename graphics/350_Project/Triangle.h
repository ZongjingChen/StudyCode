#ifndef Triangle_H
#define Triangle_H 
#include "Color.h"
#include "Vector.h"
#include "Matrix.h"
struct Triangle3D;
struct Triangle2D{
    Vector2 v1, v2, v3;
    Color c1, c2, c3;

    Triangle2D();
    Triangle2D(Triangle3D obj);
    Triangle2D(Vector2 pV1, Vector2 pV2, Vector2 pV3, Color pC1, Color pC2, Color pC3);
    bool inside(int x, int y);
    void calculateBarycentricCoordinates(Vector2 P, float& lamda1, float& lamda2, float& lamda3);
};

struct Triangle3D{
    Vector4 v1,v2,v3;
    Color c1,c2,c3;
    bool shouldDraw;

    Triangle3D();
    Triangle3D(Vector4 pV1, Vector4 pV2, Vector4 pV3, Color pC1, Color pC2, Color pC3);
    void transform(Matrix4 obj);
};
#endif

