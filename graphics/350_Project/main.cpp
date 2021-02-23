#include "Color.h"
#include "Raster.h"
#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <ctime>

using namespace std;

#define WIDTH 100
#define HEIGHT 100
int main(){



    
    Raster c(WIDTH,HEIGHT,White);

    Model teapot;
    teapot.readFromOBJFile("./teapot.obj",Red);
    Matrix4 modelMatrixTeapot =Translate3D(50,50,-35) * RotateZ3D(45.0) * Scale3D(0.5,0.5,0.5);
    Vector4 eye(50,50,30,1);
    Vector4 spot(50,50,-30,1);
    teapot.performBackfaceCulling(eye,spot);

    Matrix4 viewMatrix = LookAt(eye, spot, Vector4(0,1,0,0)); 

    Matrix4 perspectiveMatrix = Perspective(70.0, c.getWidth()/c.getHeight(), 0.01, 88.5);
    Matrix4 viewportMatrix = Viewport(0,0,c.getWidth(),c.getHeight());
    teapot.transform(perspectiveMatrix * viewMatrix * modelMatrixTeapot);
    teapot.homogenize();
    teapot.transform(viewportMatrix);

    
    
    //bunny
    Model bunny;
    bunny.readFromOBJFile("./bunny.obj", Blue);
    Matrix4 modelMatrixBunny = Translate3D(70,30,-60) * RotateZ3D(-40.0)* Scale3D(500,500,500);
    bunny.performBackfaceCulling(eye,spot);
    bunny.transform(perspectiveMatrix * viewMatrix * modelMatrixBunny);    
    bunny.homogenize();
    bunny.transform(viewportMatrix);
    

    //put the teapot in front of the bunny
    c.drawModel(teapot);
    c.drawModel(bunny);
    c.writeToPPM();
    
    

   /*
    Raster c(WIDTH,HEIGHT,White);

    Model teapot;
    teapot.readFromOBJFile("./teapot.obj",Red);
    c.drawModel(teapot);   
    Matrix4 modelMatrixTeapot = Translate3D(50,50,-30) * RotateZ3D(45.0) * Scale3D(0.5,0.5,0.5);
    //modelMatrixTeapot.print();
    */

    /*
    Vector4 eye(50,50,30,1);
    Vector4 spot(50,50,-30,1);
    teapot.performBackfaceCulling(eye,spot);
    Matrix4 viewMatrix = LookAt(eye, spot, Vector4(0,1,0,0));     
    Matrix4 perspectiveMatrix = Perspective(70, c.getWidth()/c.getHeight(), 0.01, 88.5);
    Matrix4 viewportMatrix = Viewport(0,0,c.getWidth(),c.getHeight());
    */

    //teapot.transform(modelMatrixTeapot);
    /*
    teapot.transform(viewMatrix);
    teapot.transform(perspectiveMatrix);
    teapot.homogenize();
    teapot.transform(viewportMatrix);
    */
    /*
    c.drawModel(teapot);   
    c.writeToPPM();
    */
    /*
    bunny.readFromOBJFile("./bunny.obj", Blue);

    Matrix4 modelMatrixBunny = Translate3D(70,30,-60) * RotateZ3D(-20.0)* Scale3D(500,500,500);

    bunny.performBackfaceCulling(eye,spot);    
    bunny.transform(perspectiveMatrix * viewMatrix * modelMatrixBunny);    
    bunny.homogenize();

    bunny.transform(viewportMatrix);

    c.drawModel(bunny);
    
    c.drawModel(bunny);
    
    */
    

    
    time_t rawtime;
    struct tm *ptminfo;
    time(&rawtime);
    ptminfo = localtime(&rawtime);
    printf("current: %02d-%02d-%02d %02d:%02d:%02d\n",
            ptminfo->tm_year + 1900, ptminfo->tm_mon + 1, ptminfo->tm_mday,
            ptminfo->tm_hour, ptminfo->tm_min, ptminfo->tm_sec);

    
    return 0;
    

}