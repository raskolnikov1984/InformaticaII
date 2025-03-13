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

int GuiaLab::sum_first_n_terms(int n_term) {

  int sum = (n_term * (n_term + 1)) / 2;

  return sum;
}

unsigned long long GuiaLab::calculate_factorial(int n_term) {
  if (n_term == 0) {
    return 1;
  }
  return n_term * calculate_factorial(n_term - 1);
}

double GuiaLab::calculate_perimeter_circle(double n) {
  float PI = 3.1416;
  return 2 * PI * n;
}

double GuiaLab::calculate_area_circle(double n) {
  float PI = 3.1416;
  return PI * (n * n);
}

int GuiaLab::calculate_firts_five_powers(int number) {
  int last_power = 0;
  int power;
  for (int i = 1; i < 6; i++) {
    power = calculate_a_power_b(number, i);
    cout << "The power #" << i << " is: " << calculate_a_power_b(number, i)
         << endl;

    if (i == 5) {
      last_power = power;
    };
  };
  return last_power;
}

int GuiaLab::calculate_dividers(int number) {
  int last_divider = 0;
  for (int i = 1; i < number + 1; i++) {
    if (number % i == 0) {
      cout << "The number " << i << " is divider of " << number << endl;
    };

    if (i == number) {
      last_divider = i;
    };
  };

  return last_divider;
}

void GuiaLab::print_parallel_colunms(int number) {
  int iter = number;
  for (int i = 1; i < iter + 1; i++) {
    cout << i << " " << number << endl;
    number--;
  };
}
