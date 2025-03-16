#include "guia1.h"
#include "problems.h"
#include <iostream>

using namespace std;

char get_exercises_type() {
  char exercises_type = '0';
  while (exercises_type != 'e' && exercises_type != 'p') {
    cout << "Please choose a type of exercises, to exercises (e), to problems "
            "(p): "
         << endl;
    cin >> exercises_type;
  };

  return exercises_type;
}

int main() {
  GuiaLab guia;
  Guia1Problems guiaP;
  Guia1Problems::ReturnCashStruc result;
  int number, exercise = 0;
  int return_cash;
  char exercises_type = get_exercises_type();
  cout << "the exercise type choosed is: " << exercises_type << endl;

  if (exercises_type == 'e') {
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
      cout << "The perimeter of circle is: "
           << guia.calculate_perimeter_circle(1) << endl;
      cout << "The area of circle is: " << guia.calculate_area_circle(1)
           << endl;
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
  } else {
    int problem = 0;
    cout << "Please choose the problem (1 - 17)" << endl;
    cin >> problem;

    switch (problem) {
    case 1:
      char character;
      cout << "Please choose a character: " << endl;
      cin >> character;
      cout << character << " " << guiaP.is_vowel_or_consonant(character)
           << endl;
      break;
    case 2:
      cout << "Please Type the amount to return: " << endl;
      cin >> return_cash;
      result = guiaP.calculate_return_cash(return_cash);
      cout << "Billetes y monedas necesarios:" << endl;
      cout << "Billetes de $50,000: " << result.fiftyThousandCOP << endl;
      cout << "Billetes de $20,000: " << result.twentyThousandCOP << endl;
      cout << "Billetes de $10,000: " << result.tenThousandCOP << endl;
      cout << "Billetes de $5,000: " << result.fiveThousandCOP << endl;
      cout << "Billetes de $2,000: " << result.twoThousandCOP << endl;
      cout << "Billetes de $1,000: " << result.oneThousandCOP << endl;
      cout << "Monedas de $500: " << result.fiveHoundredCOP << endl;
      cout << "Monedas de $200: " << result.twoHoundredCOP << endl;
      cout << "Monedas de $100: " << result.oneHoundredCOP << endl;
      break;
    case 3:
      int month, day;
      cout << "Please type the month: ";
      cin >> month;
      cout << endl;
      cout << "Please type the day: ";
      cin >> day;
      cout << endl;

      guiaP.isValidDate(day, month);
      break;
    case 4:
      break;
    case 5:
      int odd_number;
      cout << "Please type a odd number: " << endl;
      cin >> odd_number;
      guiaP.printDiamond(odd_number);
    case 6:
      float euler;
      cout << "Please type a number to calculate euler" << endl;
      cin >> number;
      euler = guiaP.calculate_aproximate_euluer_value(number);

      cout << "The aproximate value of euler is: " << euler << endl;
    default:
      cout << "Please choose a correct option";
    };
  };
  return 0;
};
