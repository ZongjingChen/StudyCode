#include "Vector.h"
#include <iostream>
using namespace std;
Vector2::Vector2(){
    x = 0.0;
    y = 0.0;
}

Vector2::Vector2(float pX, float pY){
    x = pX;
    y = pY;
}

float Vector2::magnitude(){
    return sqrt(x*x + y*y);
}

float Vector2::dot(Vector2 obj){
    return x*obj.x + y*obj.y;
}

Vector2 Vector2::normalize(){    
    float magnitude = this->magnitude();
    return Vector2(x/magnitude,y/magnitude);
}

Vector2 Vector2::perpendicular(){
    return Vector2(-y,x);
}

float determinant(Vector2 a, Vector2 b){    
    return (b.x*a.y - b.y*a.x);
}

Vector4::Vector4(){
    x = 0.0;
    y = 0.0;
    z = 0.0;
    w = 0.0;
}

Vector4::Vector4(float pX, float pY, float pZ, float pW){
    x = pX;
    y = pY;
    z = pZ;
    w = pW;
}

float Vector4::magnitude(){
    return sqrt(x*x + y*y + z*z + w*w);
}

float Vector4::dot(Vector4 obj){
    return x*obj.x + y*obj.y + z*obj.z + w*obj.w;
}

Vector4 Vector4::normalize(){
    float magnitude = this->magnitude();
    return Vector4(x/magnitude,y/magnitude,z/magnitude,w/magnitude);
}

Vector4 Vector4::cross(Vector4 b){
    Vector4 n(0,0,0,0);
    n.x = y * b.z - z * b.y;
    n.y = z * b.x - x * b.z;
    n.z = x * b.y - y * b.x;
    return n.normalize();
}

void Vector4::print(){
    cout << x <<' ' << y <<' ' << z << ' ' << w << ' ' << '\n';
}





