#include "guia1.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  GuiaLab guia;
  int number;

  // Ejercicio 1
  cout << "Exercise 1: Remainder of 8 / 3: " << guia.get_remainder(8, 3)
       << endl;

  // Ejercicio 2
  cout << "Please, Type number: " << endl;
  cin >> number;
  cout << "Excercise 2: The number is: " << guia.is_even_or_odd(number) << endl;
}
