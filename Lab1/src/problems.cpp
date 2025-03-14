#include "problems.h"

const char *Guia1Problems::is_vowel_or_consonant(int c) {
  int lower_case_vowels[5] = {97, 101, 105, 105, 117};
  int to_lower_case = c + 32;

  if (c >= 97 && c <= 122) {
    for (int i = 0; i < 6; i++) {
      if (c == lower_case_vowels[i]) {
        return "is a vowel";
      };
    };

    return "is a consonant";
  };
  return "undefined";
}
