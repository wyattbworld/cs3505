///@author C Wyatt Bruchhauser
///@date September 12, 2023
///Professor: David Johnson
///Class: CS3505 - Software Practice II
///Assignment: HW3 Facades and Makefiles
///Organization: University of Utah Kalhert School of Computing
///@brief This function generates a sine wave of text on a pdf.

#include "HaruPDF.h"
#include "Sine.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
int main (){

    const char* waveText = "I think this is a good text curve";
    const double canvasWidth = 580;
    const double canvasHeight = 400;
    const double degreesTwoPi = 360; //Number of degrees in a circle.
    const double waveHeightPercentage = 0.15; //How much height of the canvas should be occupied by the wave.
    HaruPDF pdf;
    Sine wave(canvasHeight * waveHeightPercentage, degreesTwoPi /2, degreesTwoPi / strlen (waveText)); //We are going to iterate over all 360 degrees, so we need to add 360 / the number of characters to get our increment.

    pdf.Open();

    for (unsigned int i = 0; i < strlen (waveText); i++)
    {
        pdf.DrawCharacter(wave.currentAngle() / degreesTwoPi * canvasWidth , canvasHeight/2 - wave.currentHeight(), waveText[i]);
        wave++;
    }

    pdf.Save();
    pdf.Close();

    cout << "it worked" << endl;
    return 0;

}