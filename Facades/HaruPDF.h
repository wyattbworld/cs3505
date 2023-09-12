///@author C Wyatt Bruchhauser
///@date September 12, 2023
///Professor: David Johnson
///Class: CS3505 - Software Practice II
///Organization: University of Utah Kalhert School of Computing
///@brief This function is a facade for the HARUPDF library and provides
///only the most basic functionality to create a pdf and put words
///on a pdf.
#ifndef HARU_PDF
#define HARU_PDF

class HaruPDF {

public:

/// @brief Constructs a HaruPDF and opens a new pdf.
HaruPDF();

/// @brief Draws a character onto a pdf
/// @param x The x position you want to place it on
/// @param y The y position you want to place it on.
/// @param c The character you want to draw.
void DrawCharacter(float x, float y, char c);

/// @brief Saves the current file.
void Save();

/// @brief Closes the current file.
void Close();

};

#endif