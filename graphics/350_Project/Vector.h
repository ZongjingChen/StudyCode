#ifndef Vector_H
#define Vector_H
#include <math.h>

struct Vector2{

    float x;
    float y;
    Vector2();
    Vector2(float pX, float pY);

    float magnitude();
    float dot(Vector2 obj);
    Vector2 normalize();
    Vector2 perpendicular();

    Vector2 operator + (Vector2 const &obj){
        Vector2 result;
        result.x = x + obj.x;
        result.y = y + obj.y;
        return result;
    }

    Vector2 operator - (Vector2 const &obj){
        Vector2 result;
        result.x = x - obj.x;
        result.y = y - obj.y;
        return result;
    }

    Vector2 operator * (float scalar){

        Vector2 result;
        result.x = x * scalar;
        result.y = y * scalar;
        return result;
    } 
};

struct Vector4{
    float x;
    float y;
    float z;
    float w;
    
    Vector4();
    Vector4(float x, float y, float z, float w);
    float magnitude();
    float dot(Vector4 obj);
    Vector4 normalize();
    Vector4 cross(Vector4 b);
    void print();


    Vector4 operator + (Vector4 const &obj){
        Vector4 result;
        result.x = x + obj.x;
        result.y = y + obj.y;
        result.z = z + obj.z;
        result.w = w + obj.w;
        return result;
    }

    Vector4 operator - (Vector4 const &obj){
        Vector4 result;
        result.x = x - obj.x;
        result.y = y - obj.y;
        result.z = z - obj.z;
        result.w = w - obj.w;
        return result;
    }

    Vector4 operator * (float scalar){
        Vector4 result;
        result.x = x * scalar;
        result.y = y * scalar;
        result.z = z * scalar;
        result.w = w * scalar;
        return result;
    }
};

float determinant(Vector2 a, Vector2 b);
#endif

