#ifndef Matrix_H
#define Matrix_H
#define _USE_MATH_DEFINES
#include <math.h>
#include "Vector.h"
struct Matrix4{
    float ix, jx, kx, ox;
    float iy, jy, ky, oy;
    float iz, jz, kz, oz;
    float iw, jw, kw, ow;

    Matrix4();
    Matrix4(float pIx, float pJx, float pKx, float pOx,
            float pIy, float pJy, float pKy, float pOy,
            float pIz, float pJz, float pKz, float pOz,
            float pIw, float pJw, float pKw, float pOw);
    void print();

    Matrix4 operator * (Matrix4 const &obj){
        Matrix4 result;
        result.ix = ix*obj.ix + jx*obj.iy + kx*obj.iz + ox*obj.iw;
        result.jx = ix*obj.jx + jx*obj.jy + kx*obj.jz + ox*obj.jw;
        result.kx = ix*obj.kx + jx*obj.ky + kx*obj.kz + ox*obj.kw;
        result.ox = ix*obj.ox + jx*obj.oy + kx*obj.oz + ox*obj.ow;

        result.iy = iy*obj.ix + jy*obj.iy + ky*obj.iz + oy*obj.iw;
        result.jy = iy*obj.jx + jy*obj.jy + ky*obj.jz + oy*obj.jw;
        result.ky = iy*obj.kx + jy*obj.ky + ky*obj.kz + oy*obj.kw;
        result.oy = iy*obj.ox + jy*obj.oy + ky*obj.oz + oy*obj.ow;

        result.iz = iz*obj.ix + jz*obj.iy + kz*obj.iz + oz*obj.iw;
        result.jz = iz*obj.jx + jz*obj.jy + kz*obj.jz + oz*obj.jw;
        result.kz = iz*obj.kx + jz*obj.ky + kz*obj.kz + oz*obj.kw;
        result.oz = iz*obj.ox + jz*obj.oy + kz*obj.oz + oz*obj.ow;

        result.iw = iw*obj.ix + jw*obj.iy + kw*obj.iz + ow*obj.iw;
        result.jw = iw*obj.jx + jw*obj.jy + kw*obj.jz + ow*obj.jw;
        result.kw = iw*obj.kx + jw*obj.ky + kw*obj.kz + ow*obj.kw;
        result.ow = iw*obj.ox + jw*obj.oy + kw*obj.oz + ow*obj.ow;

        return result;
    }
    Vector4 operator * (Vector4 const &obj){
        Vector4 result;
        result.x = this->ix*obj.x + this->jx*obj.y + this->kx*obj.z + this->ox*obj.w;
        result.y = this->iy*obj.x + this->jy*obj.y + this->ky*obj.z + this->oy*obj.w;
        result.z = this->iz*obj.x + this->jz*obj.y + this->kz*obj.z + this->oz*obj.w;
        result.w = this->iw*obj.x + this->jw*obj.y + this->kw*obj.z + this->ow*obj.w;
        return result;
    }

    Matrix4 operator * (float scalar){
        Matrix4 result;
        result.ix = this->ix*scalar;
        result.jx = this->jx*scalar;
        result.kx = this->kx*scalar;
        result.ox = this->ox*scalar;

        result.iy = this->iy*scalar;
        result.jy = this->jy*scalar;
        result.ky = this->ky*scalar;
        result.oy = this->oy*scalar;

        result.iz = this->iz*scalar;
        result.jz = this->jz*scalar;
        result.kz = this->kz*scalar;
        result.oz = this->oz*scalar;

        result.iw = this->iw*scalar;
        result.jw = this->jw*scalar;
        result.kw = this->kw*scalar;
        result.ow = this->ow*scalar;

        return result;
    }
};


Matrix4 Translate3D(float tX, float tY, float tZ);
Matrix4 Scale3D(float sX, float sY, float sZ);
Matrix4 RotateX3D(float degrees);
Matrix4 RotateY3D(float degrees);
Matrix4 RotateZ3D(float degrees);
Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ);
Matrix4 Rotate3D(float degrees, Vector4 vec);
Matrix4 LookAt(Vector4 eye, Vector4 spot, Vector4 up);
Matrix4 Orthographic(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
Matrix4 Perspective(float fovY, float aspect, float nearZ, float farZ);
Matrix4 Viewport(float x, float y, float width, float height);

#endif