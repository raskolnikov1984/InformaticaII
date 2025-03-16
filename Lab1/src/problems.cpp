#include "problems.h"
#include "guia1.h"
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

Guia1Problems::ReturnCashStruc
Guia1Problems::calculate_return_cash(int return_cash) {
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

bool Guia1Problems::isValidDate(int day, int month = 0) {
  if (month < 1 || month > 12) {
    cout << month << " is an invalid month." << endl;
    return false;
  }

  int daysByMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (month < 1 || day > daysByMonth[month]) {
    cout << day << "/" << month << " is an invalid date." << endl;
    return false;
  }

  if (month == 2 && day == 29) {
    cout << day << "/" << month << " possibly leap year." << endl;
    return true;
  } else {
    cout << day << "/" << month << " is a valid date." << endl;
  }

  return true;
}

void Guia1Problems::printDiamond(int odd_number) {
  char character = '*';
  char espaces = ' ';
  int rows, numesp, numcharacter;
  rows = odd_number;

  numesp = (rows + 1) / 2;
  numcharacter = 1;
  for (int i = 1; i < rows; i += 2) {
    cout << string(numesp, espaces) + string(numcharacter, character) << endl;
    numesp--;
    numcharacter += 2;
  }
  for (int i = 1; i < rows + 1; i += 2) {
    cout << string(numesp, espaces) + string(numcharacter, character) << endl;
    numesp++;
    numcharacter -= 2;
  }
}

int factorial(int numero) {
  double facto = numero;
  for (int i = 1; i < numero; i++) {
    facto = facto * (numero - i);
  }
  return facto;
}

unsigned long long calculate_factorial(int n_term) {
  if (n_term == 0) {
    return 1;
  }
  return n_term * calculate_factorial(n_term - 1);
}
float Guia1Problems::calculate_aproximate_euluer_value(int number) {
  float euler = 1;
  for (int i = 1; i < number; i++) {
    euler = euler + static_cast<float>(
                        (static_cast<float>(1) / calculate_factorial(i)));
  }
  return euler;
}
