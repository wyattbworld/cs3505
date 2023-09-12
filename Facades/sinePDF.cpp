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
    pdf.Save();
    pdf.Close();

    cout << "it worked" << endl;
    return 0;

}