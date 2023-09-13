///@author C Wyatt Bruchhauser
///@date September 6, 2023
///Professor: David Johnson
///Class: CS3505 - Software Practice II
///Organization: University of Utah Kalhert School of Computing
///Sine: This class describes a sine wave where the user can input an amplitude and wavelength. The user can iterate through the class and get the coordinates in the form of an ostream.

#ifndef SINE_H
#define SINE_H

#include <iostream>
#include "hpdf.h"

class Sine {

    
    double amplitude; //The height of the peak of the wave.
    double wavelength; //The distance traveled in one period.
    double angleIncrement; //The amount you want the angle to change for each increment.
    double currAngle; //The current angle we are iterating through.

    public:
    /// @brief This constructor will create a Sine object that the user can iterate through.
    /// @param amplitude //The height of the peak of the wave.
    /// @param wavelength //The amount you want the angle to change for each increment.
    /// @param angleIncrement //The amount you want each iteration to change the angle.
    Sine(double amplitude, double wavelength, double angleIncrement);

    /// @brief Gets the current angle.
    /// @return Returns the current angle.
    double currentAngle();
    
    /// @brief Gets the height of the sine wave at the current angle
    /// @return The height of the sine wave
    double currentHeight();

    /// @brief increments the angle by the angleIncrement (prefix)
    Sine& operator++();

    /// @brief increemnts the angle by the angleIcrement (postix)
    Sine operator++ (int);

    /// @brief converts the current position of the wave into in output file in the form.
    /// currentAngle, currentHeight
    /// @param output std::cout
    /// @param sine the wave you want to capture the state of.
    friend std::ostream& operator<<(std::ostream& output, Sine sine);
    
    
    private:
    ///@brief Converts degrees to radians.
    ///@param degrees the number of degrees you want to convert.
    double degreesToRadians(double degrees);
};

#endif