///@author C Wyatt Bruchhauser
///@date September 12, 2023
///Professor: David Johnson
///Class: CS3505 - Software Practice II
///Organization: University of Utah Kalhert School of Computing
///@brief This function is a facade for the HARUPDF library and provides
///only the most basic functionality to create a pdf and put words
///on a pdf.

#include "HaruPDF.h"
#include "hpdf.h"

#include <string.h>

HPDF_Doc pdf;
HPDF_Page page;
HPDF_Font font;

const char pdfName[] = "sinePDF.pdf"; //The filename that the pdf will save to
const HPDF_PageSizes pageSize = HPDF_PAGE_SIZE_A5; //5.83 x 8.27in
const HPDF_PageDirection pageDirection = HPDF_PAGE_LANDSCAPE; 
const char fontName[] = "Courier-Bold";
HPDF_REAL textLeading = 20;
HPDF_REAL grayStroke = 0;
HPDF_REAL textSize = 30;

HaruPDF::HaruPDF ()
{
      
}

void HaruPDF::Open()
{
    pdf = HPDF_New (NULL, NULL);
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, pageSize, pageDirection);
}

void HaruPDF::DrawCharacter(float x, float y, char c)
{
    HPDF_Page_BeginText (page);
    font = HPDF_GetFont (pdf, fontName, NULL);
    HPDF_Page_SetTextLeading (page, textLeading);
    HPDF_Page_SetGrayStroke (page, grayStroke);
    HPDF_Page_SetFontAndSize (page, font, textSize);
    
    char buf[2]; //Going to store the character we are going to print.
    buf[0] = c;
    buf[1] = 0;

    HPDF_Page_MoveTextPos (page, x, y);
    HPDF_Page_ShowText (page, buf);
    HPDF_Page_EndText(page);
}

void HaruPDF::Save()
{
    HPDF_SaveToFile (pdf, pdfName);
}

void HaruPDF::Close()
{
    HPDF_Free(pdf);
}