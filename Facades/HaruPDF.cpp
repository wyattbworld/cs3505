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

const char pdfName[] = "sinePDF.pdf"; //The filename that the pdf will save to
const HPDF_PageSizes pageSize = HPDF_PAGE_SIZE_A5; //The size of the pdf
const HPDF_PageDirection pageDirection = HPDF_PAGE_PORTRAIT;

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
    
}

void HaruPDF::Save()
{
    HPDF_SaveToFile (pdf, pdfName);
}

void HaruPDF::Close()
{
    HPDF_Free(pdf);
}