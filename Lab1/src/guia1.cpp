#include "guia1.h"

int GuiaLab::get_remainder(int a, int b) { return a % b; }
const char *GuiaLab::is_even_or_odd(int number) {
  if (number % 2 == 1) {
    return "impar";
  } else {
    return "par";
  }
}
int GuiaLab::who_is_bigger(int a, int b) { return (a > b) ? a : b; }
