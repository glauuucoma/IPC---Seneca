/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Davyd Kuleba
Student ID#: 147894224
Email      : dkuleba@myseneca.ca
Section    : ZCC

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const char patSize = 'S';
    const double sSizePrice = 1796;
    const double mSizePrice = 2696;
    const double lSizePrice = 3597;
    float subTotal = (sSizePrice/100*8);
    
//    printf("%.2lf", sSizePrice / 100);
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $%.2lf\n", (float)sSizePrice/100);
    printf("Enter the price for a MEDIUM shirt: $%.2lf\n", (float)mSizePrice/100);
    printf("Enter the price for a LARGE shirt: $%.2lf\n\n", (float)lSizePrice/100);
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", (float)sSizePrice/100);
    printf("MEDIUM : $%.2lf\n", (float)mSizePrice/100);
    printf("LARGE  : $%.2lf\n\n", (float)lSizePrice/100);
    printf("Patty's shirt size is 'S'\n");
    printf("Number of shirts Patty is buying: 8\n\n");
    printf("Patty's shopping cart...\n");
    printf("Contains : 8 shirts\n");
    printf("Sub-total: $%8.4lf\n", subTotal);
    printf("Taxes    : $18.6800\n");
    printf("Total    : $162.3600\n");

    return 0;
}
