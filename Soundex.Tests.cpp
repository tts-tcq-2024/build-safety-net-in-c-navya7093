#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
 //AAA
  char soundex[5];
  generateSoundex("CA^BBg2", soundex);
  ASSERT_STREQ(soundex,"C120");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
 //AAA
  char soundex[5];
  generateSoundex("Emmb3$", soundex);
  ASSERT_STREQ(soundex,"E510");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_4) {
 //AAA
  char soundex[5];
  generateSoundex("E", soundex);
  ASSERT_STREQ(soundex,"E000");
}
