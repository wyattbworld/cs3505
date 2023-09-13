///@author C Wyatt Bruchhauser
///@date September 12, 2023
///Professor: David Johnson
///Class: CS3505 - Software Practice II
///Assignment: HW3 Facades and Makefiles
///Organization: University of Utah Kalhert School of Computing
///@brief This function generates a sine wave of text on a pdf.

#include "HaruPDF.h"
#include <iostream>

using std::cout;
using std::endl;
int main (){

    HaruPDF pdf;
    pdf.Open();
    pdf.DrawCharacter(0, 0, 'c');
    pdf.DrawCharacter(0, 400, 'a');
    pdf.DrawCharacter(575, 0 , 'd'); 
    pdf.DrawCharacter(575, 400 , 'b');
    pdf.Save();
    pdf.Close();

    cout << "it worked" << endl;
    return 0;

}