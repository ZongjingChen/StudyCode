#ifndef Raster_H
#define Raster_H
#include "Color.h"
#include "Vector.h"
#include "Triangle.h"
#include "Model.h"

class Raster{
private:
    int width;
    int height;
    Color* pixels;
    float* depthPixels;
public:
    Raster();
    Raster(int pWidth, int pHeight, Color pFillColor);
    void destruct();

    int getWidth();
    int getHeight();
    Color getColorPixel(int x, int y);
    void setColorPixel(int x, int y, Color pFillColor);
    float getDepthPixel(int x, int y);
    void setDepthPixel(int x, int y, float depth);
    void clear(Color pFillColor);
    void clear(float depth);

    void writeToPPM();
    void drawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor);
    void drawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2);
    void drawTriangle2D_DotProduct(Triangle2D obj);
    void drawTriangle3D_Barycentric(Triangle3D obj);
    void drawModel(Model obj);

};

#endif