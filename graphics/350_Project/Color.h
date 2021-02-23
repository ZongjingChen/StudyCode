#ifndef Color_H
#define Red Color(1,0,0,1)
#define Green Color(0,1,0,1)
#define Blue Color(0,0,1,1)
#define Black Color(0,0,0,0)
#define White Color(1,1,1,1)
#define Color_H

struct Color{
    float red;
    float green;
    float blue;
    float alpha;

    Color();
    Color(float pRed, float pGreen, float pBlue, float pAlpha);
    void clamp();

   Color operator + (Color const &obj){
       Color result;
       result.red = red + obj.red;       
       result.green = green + obj.green;
       result.blue = blue + obj.blue;
       result.alpha = alpha + obj.alpha;
       result.clamp();
       return result;
   }

   Color operator - (Color const &obj){
       Color result;
       result.red = red - obj.red;       
       result.green = green - obj.green;
       result.blue = blue - obj.blue;
       result.alpha = alpha - obj.alpha;
       result.clamp();
       return result;
   }
    
   Color operator * (float n){
       Color result;
       result.red = red * n;
       result.green = green * n;
       result.blue = blue * n;
       result.alpha = alpha * n;
       result.clamp();
       return result;
   }
   

};

#endif