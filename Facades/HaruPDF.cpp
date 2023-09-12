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

HPDF_Doc pdf;
HPDF_Page page;

HaruPDF::HaruPDF ()
{
    pdf = HPDF_New (NULL, NULL);
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
}

void HaruPDF::Open()
{
    
}

void HaruPDF::DrawCharacter(float x, float y, char c)
{

}

void HaruPDF::Save()
{
    HPDF_SaveToFile (pdf, "MagicNumber.pdf");
}

void HaruPDF::Close()
{
    HPDF_Free(pdf);
}