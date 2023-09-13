///@author C Wyatt Bruchhauser
///@date September 7, 2023
///Professor: David Johnson
///Class: CS3505 - Software Practice II
///Organization: University of Utah Kalhert School of Computing
///Sine: This class describes a sine wave where the user can input an amplitude and wavelength. The user can iterate through the class and get the coordinates in the form of an ostream.
#define _USE_MATH_DEFINES

#include "Sine.h"
#include <iostream>
#include <cmath>


Sine::Sine(double amplitude, double wavelength, double angleIncrement) : amplitude(amplitude), wavelength(wavelength), angleIncrement(angleIncrement) 
{
    currAngle = 0;
}
    


double Sine::currentAngle()
{
    return currAngle;
}
    

double Sine::currentHeight()
{
    return amplitude * sin(2*M_PI*degreesToRadians(currAngle)/degreesToRadians(wavelength));
}


Sine& Sine::operator++()
{
    currAngle = currAngle + angleIncrement;
    return *this;
}


Sine Sine::operator++ (int)
{
    return ++(*this);
}

/// @brief converts the current position of the wave into in output file in the form.
/// currentAngle, currentHeight
/// @param output std::cout
/// @param sine the wave you want to capture the state of.
std::ostream& operator<<(std::ostream& output, Sine sine)
{
    output << sine.currentAngle() << ", " << sine.currentHeight();
    return output; 
}

//@brief Converts degrees to radians.
//@param degrees the number of degrees you want to convert.
double Sine::degreesToRadians(double degrees)
{
    return degrees * M_PI /180;
}