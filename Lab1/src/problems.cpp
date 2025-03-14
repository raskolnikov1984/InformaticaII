#include "problems.h"
#include <iostream>

using namespace std;

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

ReturnCashStruc Guia1Problems::calculate_return_cash(int return_cash) {
  ReturnCashStruc return_cash_struc;
  int denominations[10] = {50000, 20000, 10000, 5000, 2000,
                           1000,  500,   200,   100,  50};
  int *quantities[] = {
      &return_cash_struc.fiftyThousandCOP, &return_cash_struc.twentyThousandCOP,
      &return_cash_struc.tenThousandCOP,   &return_cash_struc.fiveThousandCOP,
      &return_cash_struc.twoThousandCOP,   &return_cash_struc.oneThousandCOP,
      &return_cash_struc.fiveHoundredCOP,  &return_cash_struc.twoHoundredCOP,
      &return_cash_struc.oneHoundredCOP,   &return_cash_struc.fiftyCOP};

  for (int i = 0; i < 10; i++) {
    if (return_cash >= denominations[i]) {
      *quantities[i] = return_cash / denominations[i];
      return_cash %= denominations[i];
    }
  }

  return_cash_struc.remainderCOP = return_cash;

  if (return_cash > 0) {
    cout << "You can't complete this expected amount. : " << return_cash
         << endl;
  }

  return return_cash_struc;
}
