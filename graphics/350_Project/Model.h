#ifndef Model_H
#define Model_H
#include <vector>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include "Vector.h"
#include "Triangle.h"
using namespace std;

class Model{
    private:
    vector<Triangle3D> triangles;
    
    public:
    Model();
    int numTriangles();
    void transform(Matrix4 obj);
    void readFromOBJFile(string filepath, Color pFillColor);
    void homogenize();
    void performBackfaceCulling(Vector4 eye, Vector4 spot);
    Triangle3D operator[] (int i){
        return triangles.at(i);
    }
};
#endif