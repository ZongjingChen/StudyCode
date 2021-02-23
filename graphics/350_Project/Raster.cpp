#include "Raster.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <limits>

using namespace std;

Raster::Raster(){
    width = 0;
    height = 0;
    pixels = nullptr;
    depthPixels = nullptr;
}

//new raster
Raster::Raster(int pWidth, int pHeight, Color pFillColor){
    width = pWidth;
    height = pHeight;
    pixels = new Color[width*height];
    depthPixels = new float[width*height];
    for(int i = 0; i < width*height; i++){
        pixels[i] = pFillColor;
        depthPixels[i] = numeric_limits<float>::max();
    }
}

void Raster::destruct(){
    delete[] pixels;
    delete[] depthPixels;
}

int Raster::getWidth(){
    return width;
}

int Raster::getHeight(){
    return height;
}

Color Raster::getColorPixel(int x, int y){
    int index = (height-y-1)*width + x;
    return pixels[index];
}

float Raster::getDepthPixel(int x, int y){
    int index = (height-y-1)*width + x;
    return depthPixels[index];
}

//set a pixel to a specified color
void Raster::setColorPixel(int x, int y, Color pFillColor){
    int index = (height-y-1)*width + x;
    pixels[index] = pFillColor;
}

void Raster::setDepthPixel(int x, int y, float depth){
    int index = (height-y-1)*width + x;
    depthPixels[index] = depth;
}

//set every pixels to black
void Raster::clear(Color pFillColor){
    for(int i = 0; i<width*height; i++){
        pixels[i] = pFillColor;
    }
}

void Raster::clear(float depth){
    for(int i = 0; i<width*height; i++){
        depthPixels[i] = depth;
    }
}

//write color of each pixel to FRAME_BUFFER.ppm
void Raster::writeToPPM(){
    ofstream out ("FRAME_BUFFER.ppm");
    out << "P3" << endl;
    out << width << " " << height << endl;
    out << "255" << endl;
    
    for (int i = height-1; i >= 0 ; i--){
        for(int j = 0; j < width; j++){
            int index = (height-i-1)*width + j;
            out << round(pixels[index].red*255) << " " << round(pixels[index].green*255) << " " << round(pixels[index].blue*255) << " ";
        }
        out << endl;
    }
    
    out.close();
}

//swap the coordinates of x1 and x2
void swap (float &x1, float &x2){
    float x;
    x = x1;
    x1 = x2;
    x2 = x;
}

//use DDA algorithm to draw a straight line
void Raster::drawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor){
    if(x1 > x2){
        swap(x1,x2);
        swap(y1,y2);
    }

    float dx = x2-x1;
    float dy = y2-y1;
    float slope = dy/dx;
 
   setColorPixel(round(x1),round(y1),fillColor); 
         
    if(fabs(slope) <= 1){
        //round the left point to the nearest x-is-integer point on line 
        float x = round(x1);
        y1 += (x-x1)*slope;
        x2 = round(x2);

        while(x < x2){
            x += 1;
            y1 += slope;
            if(x >= 0 && x < width && y1 >= 0 && y1 < height){
                setColorPixel(x,round(y1),fillColor);
            }            
        }
    }

    else{
        //round the left point to the nearest y-is-integer point on line
        float y = round(y1);
        x1 += (y-y1)*(1/slope);  
        y2 = round(y2);
        
        if(slope < 0){ 
            while (y > y2){
            x1 -= 1/slope;
            y -= 1;
                if(x1 >= 0 && x1 < width && y >= 0 && y < height){
                    setColorPixel(round(x1),y,fillColor);
                }
            }
        }
        else{  
            while (y < y2){
            x1 += 1/slope;
            y += 1;
                if(x1 >= 0 && x1 < width && y >= 0 && y < height){
                    setColorPixel(round(x1),y,fillColor);
                }
            }
        }
    }
}

void Raster::drawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2){
    if(x1 > x2){
        swap(x1,x2);
        swap(y1,y2);
        swap(color1, color2);
    }

    float dx = x2-x1;
    float dy = y2-y1;
    float slope = dy/dx;

    //new code
    Vector2 endPoint1(x1,y1);
    Vector2 endPoint2(x2,y2);
    Vector2 lineVector = endPoint2 - endPoint1;
    float magnitude = lineVector.magnitude();
    setColorPixel(round(x1),round(y1),color1); 
         
    if(fabs(slope) <= 1){
        //round the left point to the nearest x-is-integer point on line 
        float x = round(x1);
        y1 += (x-x1)*slope;
        x2 = round(x2);

        while(x < x2){
            x += 1;
            y1 += slope;
            if(x >= 0 && x < width && y1 >= 0 && y1 < height){
                
                Vector2 currentPoint(x,round(y1));
                Vector2 currentVector = currentPoint - endPoint1;
                float toEndPoint1 = currentVector.magnitude() /  magnitude;
                float toEndPoint2 = 1 - toEndPoint1;
                Color fillColor = color1*toEndPoint2 + color2*toEndPoint1;

                setColorPixel(x,round(y1),fillColor);
            }            
        }
    }

    else{
        //round the left point to the nearest y-is-integer point on line
        float y = round(y1);
        x1 += (y-y1)*(1/slope);  
        y2 = round(y2);
        
        if(slope < 0){ 
            while (y > y2){
            x1 -= 1/slope;
            y -= 1;
                if(x1 >= 0 && x1 < width && y >= 0 && y < height){
                    Vector2 currentPoint(round(x1),y);
                    Vector2 currentVector = currentPoint - endPoint1;
                    float toEndPoint1 = currentVector.magnitude() /  magnitude;
                    float toEndPoint2 = 1 - toEndPoint1;
                    Color fillColor = color1*toEndPoint2 + color2*toEndPoint1;  

                    setColorPixel(round(x1),y,fillColor);
                }
            }
        }
        else{  
            while (y < y2){
            x1 += 1/slope;
            y += 1;
                if(x1 >= 0 && x1 < width && y >= 0 && y < height){

                    Vector2 currentPoint(round(x1),y);
                    Vector2 currentVector = currentPoint - endPoint1;
                    float toEndPoint1 = currentVector.magnitude() /  magnitude;
                    float toEndPoint2 = 1 - toEndPoint1;
                    Color fillColor = color1*toEndPoint2 + color2*toEndPoint1;  

                    setColorPixel(round(x1),y,fillColor);
                }
            }
        }
    }
}

void Raster::drawTriangle2D_DotProduct(Triangle2D obj){
    for(int y = fmin(fmin(obj.v1.y,obj.v2.y), obj.v3.y); y <= fmax(fmax(obj.v1.y,obj.v2.y), obj.v3.y); y++){
        for(int x = fmin(fmin(obj.v1.x,obj.v2.x), obj.v3.x); x <= fmax(fmax(obj.v1.x,obj.v2.x), obj.v3.x); x++){
            if(x >= 0 && x < width && y >= 0 && y < height){
                if(obj.inside(x,y)){
                    setColorPixel(x,y,obj.c1);
                }
            }
        }
    }
}

void Raster::drawTriangle3D_Barycentric(Triangle3D pTriangle){
    if(pTriangle.shouldDraw){
        float lamda1, lamda2, lamda3;
        Triangle2D obj(pTriangle);

        for(int y = fmin(fmin(obj.v1.y,obj.v2.y), obj.v3.y); y <= fmax(fmax(obj.v1.y,obj.v2.y), obj.v3.y); y++){
            for(int x = fmin(fmin(obj.v1.x,obj.v2.x), obj.v3.x); x <= fmax(fmax(obj.v1.x,obj.v2.x), obj.v3.x); x++){
                if(x >= 0 && x < width && y >= 0 && y < height){
                    Vector2 current(float(x) + 0.5,float(y) + 0.5);
                    obj.calculateBarycentricCoordinates(current,lamda1,lamda2,lamda3);
                    if(lamda1>=0 && lamda2 >= 0 && lamda3 >=0){
                        
                        float depth = pTriangle.v1.z*lamda1 + pTriangle.v2.z*lamda2 + pTriangle.v3.z*lamda3;
                        if(depth < getDepthPixel(x,y)){
                            
                            Color fillColor;
                            fillColor = obj.c1*lamda1 + obj.c2*lamda2 + obj.c3*lamda3;
                            setColorPixel(x,y,fillColor);
                            setDepthPixel(x,y,depth);
                            
                        }
                    }
                }
            }
        }
    }
}

void Raster::drawModel(Model obj){
    for(int i = 0; i< obj.numTriangles(); i++){
        drawTriangle3D_Barycentric(obj[i]);
    }
}