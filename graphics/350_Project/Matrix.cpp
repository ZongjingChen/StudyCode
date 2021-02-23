#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix4::Matrix4(){
    ix = jy = kz = ow = 1;
    jx = kx = ox = 
    iy = ky = oy = 
    iz = jz = oz = 
    iw = jw = kw = 0; 
}

Matrix4::Matrix4(float pIx, float pJx, float pKx, float pOx,
                 float pIy, float pJy, float pKy, float pOy,
                 float pIz, float pJz, float pKz, float pOz,
                 float pIw, float pJw, float pKw, float pOw){
    ix = pIx;   jx = pJx;   kx = pKx;   ox = pOx;
    iy = pIy;   jy = pJy;   ky = pKy;   oy = pOy;
    iz = pIz;   jz = pJz;   kz = pKz;   oz = pOz;
    iw = pIw;   jw = pJw;   kw = pKw;   ow = pOw;
}

void Matrix4::print(){
    cout << ix << ' ' << jx << ' ' << kx << ' ' << ox << '\n';
    cout << iy << ' ' << jy << ' ' << ky << ' ' << oy << '\n';
    cout << iz << ' ' << jz << ' ' << kz << ' ' << oz << '\n';
    cout << iw << ' ' << jw << ' ' << kw << ' ' << ow << '\n';
}

Matrix4 Translate3D(float tX, float tY, float tZ){
    Matrix4 result;
    result.ox = tX;
    result.oy = tY;
    result.oz = tZ;
    return result;
}

Matrix4 Scale3D(float sX, float sY, float sZ){
    Matrix4 result;
    result.ix = sX;
    result.jy = sY;
    result.kz = sZ;
    return result;
}

Matrix4 RotateX3D(float degrees){
    float radians = degrees * M_PI / 180.0;
    Matrix4 result;
    result.jy = cos(radians);
    result.ky = sin(radians);
    result.jz = -sin(radians);
    result.kz = cos(radians);
    return result;
}

Matrix4 RotateY3D(float degrees){
    float radians = degrees * M_PI / 180.0;
    Matrix4 result;
    result.ix = cos(radians);
    result.kx = -sin(radians);
    result.iz = sin(radians);
    result.kz = cos(radians);
    return result;
}

Matrix4 RotateZ3D(float degrees){
    float radians = degrees * M_PI / 180.0;
    Matrix4 result;
    result.ix = cos(radians);
    result.jx = sin(radians);
    result.iy = -sin(radians);
    result.jy = cos(radians);
    return result;
}

Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ){
    return RotateX3D(degreesX) * RotateY3D(degreesY) * RotateZ3D(degreesZ);
}

Matrix4 Rotate3D(float degrees, Vector4 vec){
    float a = atanf(vec.x / vec.z) * M_PI / 180.0;
    float b = acosf(vec.y / vec.magnitude()) * M_PI / 180.0;
    degrees = degrees * M_PI / 180.0;
    return RotateY3D(-a) * RotateX3D(-b) * RotateY3D(degrees) * RotateX3D(b) * RotateY3D(a);
}

Matrix4 LookAt(Vector4 eye, Vector4 spot, Vector4 up){
    Vector4 look = (spot - eye).normalize();

    Vector4 right = look.cross(up);

    up = right.cross(look);

    Matrix4 s1 = Translate3D(-eye.x, -eye.y, -eye.z);
    Matrix4 s2
    (right.x, right.y, right.z, 0,
     up.x   , up.y   , up.z   , 0,
     -look.x, -look.y, -look.z, 0,
     0      , 0      , 0      , 1);
    return s2*s1;
}

Matrix4 Orthographic(float minX, float maxX, float minY, float maxY, float minZ, float maxZ){
    Matrix4 translate = Translate3D(-(maxX-minX), -(maxY-minY), -(maxZ-minZ));
    Matrix4 scale = Scale3D(2/(maxX-minX), 2/(maxY-minY), 2/(maxZ-minZ));
    return scale * translate;
}

//implements far-shortening using a perspective matrix
Matrix4 Perspective(float fovY, float aspect, float nearZ, float farZ){
    fovY = fovY * M_PI / 180.0;
    float f = 1.0/(tan(fovY/2));
    float ix = f/aspect;
    float kz = (farZ + nearZ) / (nearZ - farZ);
    float oz = (2 * nearZ * farZ)/(nearZ - farZ);
    return Matrix4
    (
        ix,0,0,0,
        0,f,0,0,
        0,0,kz,oz,
        0,0,-1,0
    ); 
}

Matrix4 Viewport(float x, float y, float width, float height){
    Matrix4 translate1 = Translate3D(1,1,-1);
    Matrix4 scale1 = Scale3D(0.5, 0.5, 0.5);
    Matrix4 scale2 = Scale3D(width, height, 1);
    Matrix4 translate2 = Translate3D(x, y, 0);
    return translate2 * scale2 * scale1 * translate1;
}

