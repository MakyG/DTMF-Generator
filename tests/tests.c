/**
 * @file       tests.c
 * @author     Ondřej Ševčík
 * @date       9/2019
 * @brief      Tests for task7
 * **************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

/* Private includes -------------------------------------------------------- */
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#include "../src/dtmf.h"
#include "../src/vector.h"
#include "../src/wavfile.h"
#include "minunit.h"

/* Private defines --------------------------------------------------------- */
#define M_PI2 3.14159265358979323846f

////////////////////////////// IMPORTANT ///////////////////////////////////////
/////////// Source repository: https://github.com/siu/minunit //////////////////
/////////// For more info consult with this page ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

MU_TEST(test_dtmf_generate) {
  Vector_t *testVector = Vector_Create(1024, 1024);
  if (testVector == NULL) {
      mu_assert(0, "Vector init error");
  }
  {
    DTMF_Generate(testVector, '1');
    DTMF_Generate(testVector, '2');
    DTMF_Generate(testVector, '3');
  }
  mu_assert_int_eq(-794, testVector->items[10]);
  mu_assert_int_eq(-322, testVector->items[100]);
  mu_assert_int_eq(1414, testVector->items[1000]);
  mu_assert_int_eq(-1111, testVector->items[1250]);
  mu_assert_int_eq(1606, testVector->items[1450]);
  mu_assert_int_eq(390, testVector->items[2250]);
  mu_assert_int_eq(-1111, testVector->items[2750]);
  mu_assert_int_eq(1663, testVector->items[3250]);
  mu_assert_int_eq(1961, testVector->items[4250]);
  mu_assert_int_eq(1110, testVector->items[5250]);
  mu_assert_int_eq(-390, testVector->items[6250]);
  mu_assert_int_eq(-1663, testVector->items[7250]);
  mu_assert_int_eq(-1980, testVector->items[8250]);
  mu_assert_int_eq(-1555, testVector->items[9250]);
  mu_assert_int_eq(-804, testVector->items[10250]);
  mu_assert_int_eq(-168, testVector->items[11250]);

  Vector_t *testVector2 = Vector_Create(1024, 1024);
  int length = WAVFILE_SAMPLES_PER_SECOND;
  int volume = 1000;

  for (int i = 0; i < length; i++) {
    double t = (double)i / WAVFILE_SAMPLES_PER_SECOND;
    Vector_Append(testVector2, (volume * sin(697 * t * 2 * M_PI2)) +
                                   (volume * sin(1209 * t * 2 * M_PI2)));
  }
  for (int i = 0; i < length; i++) {
    double t = (double)i / WAVFILE_SAMPLES_PER_SECOND;
    Vector_Append(testVector2, (volume * sin(697 * t * 2 * M_PI2)) +
                                   (volume * sin(1336 * t * 2 * M_PI2)));
  }
  for (int i = 0; i < length; i++) {
    double t = (double)i / WAVFILE_SAMPLES_PER_SECOND;
    Vector_Append(testVector2, (volume * sin(697 * t * 2 * M_PI2)) +
                                   (volume * sin(1477 * t * 2 * M_PI2)));
  }

  mu_assert_int_eq(
      0, memcmp(testVector->items, testVector2->items, testVector->size));
}

MU_TEST(test_dtmf_generate_null) { DTMF_Generate(NULL, '3'); }

MU_TEST(test_dtmf_generate_wrong_digit) {
  Vector_t *testVector = Vector_Create(1024, 1024);
  mu_assert(DTMF_Generate(testVector, 'X') == false,
            "Function DTMF_Generate should return false, got true instead");
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_dtmf_generate_wrong_digit);
  MU_RUN_TEST(test_dtmf_generate);
  MU_RUN_TEST(test_dtmf_generate_null);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();

  return 0;
}
