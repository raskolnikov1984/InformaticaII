#include "guia1.h"
#include <cmath>
#include <iostream>

using namespace std;

int GuiaLab::get_remainder(int a, int b) { return a % b; }
const char *GuiaLab::is_even_or_odd(int number) {
  if (number % 2 == 1) {
    return "impar";
  } else {
    return "par";
  }
}
int GuiaLab::who_is_bigger(int a, int b) { return (a > b) ? a : b; }
int GuiaLab::who_is_smallest(int a, int b) { return (a < b) ? a : b; }
int GuiaLab::calculate_a_divided_b(int a, int b) {
  if (b == 0) {
    cout << "Error: No se puede dividir por cero." << std::endl;
    return 0;
  } else {
    int resultado = round(static_cast<double>(a) / b);
    return resultado;
  }
}

int GuiaLab::calculate_a_power_b(int a, int b) {
  int power = 1;
  for (int i = 0; i < b; i++) {
    power *= a;
  }
  return power;
}
