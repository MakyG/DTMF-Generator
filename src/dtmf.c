/**
 * @file       dtmf.c
 * @author     Tomáš Makyča
 * @date       9/2019
 * @brief      Implementation of function for DTMF generator
 * **************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU. All rights reserved.
 */

/* Private includes -------------------------------------------------------- */
#include <math.h>

#include "dtmf.h"
#include "wavfile.h"

/* Private defines --------------------------------------------------------- */
#define M_PI2 3.14159265358979323846f
#define VOLUME 1000

/* Function definition ----------------------------------------------------- */
bool DTMF_Generate(Vector_t *vector, char symbol) {
    if (vector == NULL)
        return false;

    double frekvence1 = 0;
    double frekvence2 = 0;

    // ŘÁDKY
    if(symbol == '1' || symbol == '2' || symbol == '3' || symbol == 'A'){
        frekvence1 = 697;
    }
    else if(symbol == '4' || symbol == '5' || symbol == '6' || symbol == 'B'){
        frekvence1 = 770;
    }
    else if(symbol == '7' || symbol == '8' || symbol == '9' || symbol == 'C'){
        frekvence1 = 852;
    }
    else if(symbol == '*' || symbol == '0' || symbol == '#' || symbol == 'D'){
        frekvence1 = 941;
    }
    else if (symbol != ' ') {
        return false;
    }

    // SLOUPCE
    if(symbol == '1' || symbol == '4' || symbol == '7' || symbol == '*'){
        frekvence2 = 1209;
    }
    if(symbol == '2' || symbol == '5' || symbol == '8' || symbol == '0'){
        frekvence2 = 1336;
    }
    if(symbol == '3' || symbol == '6' || symbol == '9' || symbol == '#'){
        frekvence2 = 1477;
    }
    if(symbol == 'A' || symbol == 'B' || symbol == 'C' || symbol == 'D'){
        frekvence2 = 1633;
    }


    for (int i = 0; i < 8000; i++)
    {
        double vysledek1 = sin(2 * M_PI2 * frekvence1 * i/8000) * VOLUME;
        double vysledek2 = sin(2 * M_PI2 * frekvence2 * i/8000) * VOLUME;

        double vysledekFinal = (vysledek1 + vysledek2);

        Vector_Append(vector, vysledekFinal);
    }
    return true;
}
