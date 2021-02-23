#include"Color.h"
#include<math.h>

using namespace std;

    //Set color to black
    Color::Color(){
        red = 0;
        green = 0;
        blue = 0;
        alpha = 0;
    }

    Color::Color(float pRed, float pGreen, float pBlue, float pAlpha){
        red = pRed;
        green = pGreen;
        blue = pBlue;
        alpha = pAlpha;
    }

    //clamp the value of each channel
    void Color::clamp(){
        red = fmax(red,0);
        red = fmin(red,1);

        green = fmax(green,0);
        green = fmin(green,1);

        blue = fmax(blue,0);
        blue = fmin(blue,1);

        alpha = fmax(alpha,0);
        alpha = fmin(alpha,1);
    }

    

