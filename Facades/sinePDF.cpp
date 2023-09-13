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

    HaruPDF pdf;
    Sine wave(1.0, 180.0, 360 / strlen (waveText)); //We are going to iterate over all 360 degrees, so we need to add 360 / the number of characters to get our increment.

    pdf.Open();

    pdf.DrawCharacter(0, 0, 'c');
    pdf.DrawCharacter(0, 400, 'a');
    pdf.DrawCharacter(575, 0 , 'd'); 
    pdf.DrawCharacter(575, 400 , 'b');

    for (int i = 0; i < strlen (waveText); i++)
    {
        pdf.DrawCharacter(wave.currentAngle() / 360 * 610 , 200 - wave.currentHeight() * 200 /3, waveText[i]);
        wave++;
    }

    pdf.Save();
    pdf.Close();

    cout << "it worked" << endl;
    return 0;

}