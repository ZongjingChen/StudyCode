#include "Triangle.h"

Triangle2D::Triangle2D(){    
    v1 = Vector2();
    v2 = Vector2();
    v3 = Vector2();
    c1 = c2 = c3 = Black;
}

Triangle2D::Triangle2D(Triangle3D obj){
    Vector2 pV1(obj.v1.x, obj.v1.y);
    Vector2 pV2(obj.v2.x, obj.v2.y);
    Vector2 pV3(obj.v3.x, obj.v3.y);
    Color pC1 = obj.c1;
    Color pC2 = obj.c2;
    Color pC3 = obj.c3;
    if(pV1.x == pV2.x){
        if(pV3.x < pV1.x){
            v1 = pV3;
            c1 = pC3;
            if(pV1.y < pV2.y){
                v2 = pV1;
                c2 = pC1;
                v3 = pV2;
                c3 = pC2;
            }
            else{
                v2 = pV2;
                c2 = pC2;
                v3 = pV1;
                c3 = pC1;
            }
        }
        else{
            v2 = pV3;
            c2 = pC3;
            if(pV1.y < pV2.y){
                v1 = pV1;
                c1 = pC1;
                v3 = pV2;
                c3 = pC2;
            }
            else{
                v1 = pV2;
                c1 = pC2;
                v3 = pV1;
                c3 = pC1;
            }
        }
    }

    else if(pV1.x < pV2.x){
        if(pV1.x < pV3.x){
            v1 = pV1;
            c1 = pC1;
            if(pV2.y < pV3.y){
                v2 = pV2;
                c2 = pC2;
                v3 = pV3;
                c3 = pC3;
            }
            else if(pV3.y < pV2.y){
                v2 = pV3;
                c2 = pC3;
                v3 = pV2;
                c3 = pC3;
            }
            else{
                if(pV3.x > pV2.x){
                    v2 = pV3;
                    c2 = pC3;
                    v3 = pV2;
                    c3 = pC2;
                }
                else{
                    v2 = pV2;
                    c2 = pC2;
                    v3 = pV3;
                    c3 = pC3;
                }
            }            
        }
        else if(pV3.x < pV1.x){
            v1 = pV3;
            c1 = pC3;
            if(pV1.y<pV2.y){
                v2 = pV1;
                c2 = pC1;
                v3 = pV2;
                c3 = pC2;
            }
            else{
                v2 = pV2;
                c2 = pC2;
                v3 = pV1;
                c3 = pC1;
            }

        }
        else{
            v2 = pV2;
            c2 = pC2;
            if(pV1.y < pV3.y){
                v1 = pV1;
                c1 = pC1;
                v3 = pV3;
                c3 = pC3;
            }
            else{
                v1 = pV3;
                c1 = pC3;
                v3 = pV1;
                c3 = pC1;
            }
        }
    }

    else{
        if(pV3.x < pV2.x){
            v1 = pV3;
            c1 = pC3;
            if(pV2.y < pV1.y){
                v2 = pV2;
                c2 = pC2;
                v3 = pV1;
                c3 = pC1;
            }
            else{
                v2 = pV1;
                c2 = pC1;
                v3 = pV2;
                c3 = pC2;
            }
            
        }
        else if(pV3.x > pV2.x){
            v1 = pV2;
            c1 = pC2;
            if(pV1.y < pV3.y){
                v2 = pV1;
                c2 = pC1;
                v3 = pV3;
                c3 = pC3;
            }
            else if(pV3.y < pV1.y){
                v2 = pV3;
                c2 = pC3;
                v3 = pV1;
                c3 = pC1;
            }
            else{
                if(pV1.x > pV3.x){
                    v2 = pV1;
                    c2 = pC1;
                    v3 = pV3;
                    c3 = pC3;
                }
                else{
                    v2 = pV3;
                    c2 = pC3;
                    v3 = pV1;
                    c3 = pC1; 
                }
            }
        }
        else{
            v2 = pV1;
            c2 = pC1;
            if(pV2.y < pV3.y){
                v1 = pV2;
                c1 = pC2;
                v3 = pV3;
                c3 = pC3;
            }
            else{
                v1 = pV3;
                c1 = pC3;
                v3 = pV2;
                c3 = pC2;
            }
        }
    }
}

//store triangle with leftmost and lowest point v1, lower and righter point in the rest 2 points v2 and the last point v3
Triangle2D::Triangle2D(Vector2 pV1, Vector2 pV2, Vector2 pV3, Color pC1, Color pC2, Color pC3){
    if(pV1.x == pV2.x){
        if(pV3.x < pV1.x){
            v1 = pV3;
            c1 = pC3;
            if(pV1.y < pV2.y){
                v2 = pV1;
                c2 = pC1;
                v3 = pV2;
                c3 = pC2;
            }
            else{
                v2 = pV2;
                c2 = pC2;
                v3 = pV1;
                c3 = pC1;
            }
        }
        else{
            v2 = pV3;
            c2 = pC3;
            if(pV1.y < pV2.y){
                v1 = pV1;
                c1 = pC1;
                v3 = pV2;
                c3 = pC2;
            }
            else{
                v1 = pV2;
                c1 = pC2;
                v3 = pV1;
                c3 = pC1;
            }
        }
    }

    else if(pV1.x < pV2.x){
        if(pV1.x < pV3.x){
            v1 = pV1;
            c1 = pC1;
            if(pV2.y < pV3.y){
                v2 = pV2;
                c2 = pC2;
                v3 = pV3;
                c3 = pC3;
            }
            else if(pV3.y < pV2.y){
                v2 = pV3;
                c2 = pC3;
                v3 = pV2;
                c3 = pC3;
            }
            else{
                if(pV3.x > pV2.x){
                    v2 = pV3;
                    c2 = pC3;
                    v3 = pV2;
                    c3 = pC2;
                }
                else{
                    v2 = pV2;
                    c2 = pC2;
                    v3 = pV3;
                    c3 = pC3;
                }
            }            
        }
        else if(pV3.x < pV1.x){
            v1 = pV3;
            c1 = pC3;
            if(pV1.y<pV2.y){
                v2 = pV1;
                c2 = pC1;
                v3 = pV2;
                c3 = pC2;
            }
            else{
                v2 = pV2;
                c2 = pC2;
                v3 = pV1;
                c3 = pC1;
            }

        }
        else{
            v2 = pV2;
            c2 = pC2;
            if(pV1.y < pV3.y){
                v1 = pV1;
                c1 = pC1;
                v3 = pV3;
                c3 = pC3;
            }
            else{
                v1 = pV3;
                c1 = pC3;
                v3 = pV1;
                c3 = pC1;
            }
        }
    }

    else{
        if(pV3.x < pV2.x){
            v1 = pV3;
            c1 = pC3;
            if(pV2.y < pV1.y){
                v2 = pV2;
                c2 = pC2;
                v3 = pV1;
                c3 = pC1;
            }
            else{
                v2 = pV1;
                c2 = pC1;
                v3 = pV2;
                c3 = pC2;
            }
            
        }
        else if(pV3.x > pV2.x){
            v1 = pV2;
            c1 = pC2;
            if(pV1.y < pV3.y){
                v2 = pV1;
                c2 = pC1;
                v3 = pV3;
                c3 = pC3;
            }
            else if(pV3.y < pV1.y){
                v2 = pV3;
                c2 = pC3;
                v3 = pV1;
                c3 = pC1;
            }
            else{
                if(pV1.x > pV3.x){
                    v2 = pV1;
                    c2 = pC1;
                    v3 = pV3;
                    c3 = pC3;
                }
                else{
                    v2 = pV3;
                    c2 = pC3;
                    v3 = pV1;
                    c3 = pC1; 
                }
            }
        }
        else{
            v2 = pV1;
            c2 = pC1;
            if(pV2.y < pV3.y){
                v1 = pV2;
                c1 = pC2;
                v3 = pV3;
                c3 = pC3;
            }
            else{
                v1 = pV3;
                c1 = pC3;
                v3 = pV2;
                c3 = pC2;
            }
        }
    }
}

void Triangle2D::calculateBarycentricCoordinates(Vector2 P, float& lamda1, float& lamda2, float& lamda3){
    float area = determinant(v3-v1,v2-v1) / 2.0;
    float areaCurr = determinant(P-v1,v2-v1) / 2.0;
    lamda3 = areaCurr / area;
    areaCurr = determinant(v3-v1,P-v1)/2.0;
    lamda2 = areaCurr / area;
    lamda1 = 1-lamda3-lamda2;
}

bool Triangle2D::inside(int x, int y){
    Vector2 current(x,y);
    Vector2 e1_perp = (v2 - v1).perpendicular();
    Vector2 e2_perp = (v3 - v2).perpendicular();
    Vector2 e3_perp = (v1 - v3).perpendicular();

    float dotProduct1 = (current - v1).dot(e1_perp);
    float dotProduct2 = (current - v2).dot(e2_perp);
    float dotProduct3 = (current - v3).dot(e3_perp);

    return (dotProduct1 >= 0) && (dotProduct2 >= 0) && (dotProduct3 >= 0);

}

Triangle3D::Triangle3D(){
    v1 = Vector4(0,0,0,1);
    v2 = Vector4(0,0,0,1);
    v3 = Vector4(0,0,0,1);
    c1 = c2 = c3 = White;
    shouldDraw = true;
}

Triangle3D::Triangle3D(Vector4 pV1, Vector4 pV2, Vector4 pV3, Color pC1, Color pC2, Color pC3){
    v1 = pV1;
    v2 = pV2;
    v3 = pV3;
    c1 = pC1;
    c2 = pC2;
    c3 = pC3;
    shouldDraw = true;
}

void Triangle3D::transform(Matrix4 obj){
    Vector4 tV1,tV2,tV3;
    tV1.x = v1.x*obj.ix + v1.y*obj.jx + v1.z*obj.kx + v1.w*obj.ox;
    tV1.y = v1.x*obj.iy + v1.y*obj.jy + v1.z*obj.ky + v1.w*obj.oy;
    tV1.z = v1.x*obj.iz + v1.y*obj.jz + v1.z*obj.kz + v1.w*obj.oz;
    tV1.w = v1.x*obj.iw + v1.y*obj.jw + v1.z*obj.kw + v1.w*obj.ow;

    tV2.x = v2.x*obj.ix + v2.y*obj.jx + v2.z*obj.kx + v2.w*obj.ox;
    tV2.y = v2.x*obj.iy + v2.y*obj.jy + v2.z*obj.ky + v2.w*obj.oy;
    tV2.z = v2.x*obj.iz + v2.y*obj.jz + v2.z*obj.kz + v2.w*obj.oz;
    tV2.w = v2.x*obj.iw + v2.y*obj.jw + v2.z*obj.kw + v2.w*obj.ow;

    tV3.x = v3.x*obj.ix + v3.y*obj.jx + v3.z*obj.kx + v3.w*obj.ox;
    tV3.y = v3.x*obj.iy + v3.y*obj.jy + v3.z*obj.ky + v3.w*obj.oy;
    tV3.z = v3.x*obj.iz + v3.y*obj.jz + v3.z*obj.kz + v3.w*obj.oz;
    tV3.w = v3.x*obj.iw + v3.y*obj.jw + v3.z*obj.kw + v3.w*obj.ow;

    v1 = tV1;
    v2 = tV2;
    v3 = tV3;
}