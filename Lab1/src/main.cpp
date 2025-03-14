#include "guia1.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  GuiaLab guia;
  int number, exercise = 0;

  cout << "Please choose the exercise (1 - 17)" << endl;
  cin >> exercise;

  switch (exercise) {
  case 1:
    // Ejercicio 1
    cout << "Exercise 1: Remainder of 8 / 3: " << guia.get_remainder(8, 3)
         << endl;
    break;
  case 2:
    // Ejercicio 2
    cout << "Please, Type number: " << endl;
    cin >> number;
    cout << "Excercise 2: The number is: " << guia.is_even_or_odd(number)
         << endl;
    break;
  case 3:
    cout << "The greatest number is: " << guia.who_is_bigger(7, 3) << endl;
    break;
  case 4:
    cout << "The smallest number is: " << guia.who_is_smallest(7, 3) << endl;
    break;
  case 5:
    cout << "The division A / B is: " << guia.calculate_a_divided_b(8, 3)
         << endl;
    break;
  case 6:
    cout << "The result to A power B is: " << guia.calculate_a_power_b(5, 3)
         << endl;
    break;
  case 7:
    cout << "The sum of the firts N-Term is: " << guia.sum_first_n_terms(5)
         << endl;
    break;
  case 8:
    cout << "The factorial is: " << guia.calculate_factorial(5);
    break;
  case 9:
    cout << "The perimeter of circle is: " << guia.calculate_perimeter_circle(1)
         << endl;
    cout << "The area of circle is: " << guia.calculate_area_circle(1) << endl;
    break;
  case 10:
    cout << "Type a number, please: " << endl;
    cin >> number;
    guia.print_multiples_less_than_hundred(number);
    break;
  case 11:
    cout << "Type a number, please: " << endl;
    cin >> number;
    guia.print_multiplication_table_of_n(number);
    break;
  case 12:
    cout << "Type the number to calculate firts five power" << endl;
    cin >> number;
    guia.calculate_firts_five_powers(number);
    break;
  case 13:
    cout << "Type a number N" << endl;
    cin >> number;
    guia.calculate_dividers(number);
    break;
  case 14:
    guia.print_parallel_colunms(50);
    break;
  default:
    cout << "Please choose a correct option";
  }

  return 0;
};
