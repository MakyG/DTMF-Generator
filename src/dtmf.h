/**
 * @file       dtmf.h
 * @author     Ondřej Ševčík
 * @date       9/2019
 * @brief      Header file for DTMF generator
 * **************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU. All rights reserved.
 */

#ifndef DTMF_H
#define DTMF_H

/* Public includes --------------------------------------------------------- */
#include "vector.h"

/* Public defines ---------------------------------------------------------- */

/**
 * @brief DTMF_Generate Generates sin waves lowtone frequency and hightone
 * frequency sin waves and then adds their sum value to the vector
 * @param vector    vector where is sum of two sin waves stored
 * @param symbol  the digit that determines lowtone and hightone frequency
 * @return Returns true if tone  was generated, return false if symbol is wrong
 */
bool DTMF_Generate(Vector_t *vector, char symbol);

#endif  // DTMF_H
