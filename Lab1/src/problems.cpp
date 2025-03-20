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

int Guia1Problems::calculate_sum_time(int first_time, int second_time) {
  int a = first_time, b = second_time;
  unsigned short int ha, hb, ma, mb, ht = 0, mt = 0;

  if (a > 2359 || a < 0) {
    cout << a << " is an invalid time" << endl;
    return 0;
  }

  if (b > 2359 || b < 0) {
    cout << b << " is an invalid time" << endl;
    return 0;
  }

  ha = a / 100;
  hb = b / 100;

  ma = a % 100;
  mb = b % 100;

  if (ma >= 60) {
    cout << ma << " is an invalid time" << endl;
    return 0;
  } else if (mb >= 60) {
    cout << mb << " is an invalid time" << endl;
    return 0;
  } else {
    mt = ma + mb;
    while (mt >= 60) {
      // Si la suma de los minutos es mayor a 60, esto significa que se suma una
      // hora.
      ht++;
      mt -= 60;
    }
    ht += (ha + hb);
    if (ht > 24) {
      // Si se pasan las 24 horas el contador se reinicia a 00:00.
      ht -= 24;
    }
  }

  if (ht == 24 && mt > 0) {
    ht *= 0;
  };

  cout << "The time is: " << ht << ":" << mt << endl;

  ht = ht * 100 + mt;

  return ht;
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

int Guia1Problems::calculate_sum_even_numbers_in_fibonacci(int n_term) {
  int firts_term = 1, second_term = 1, b = 1, sum = firts_term + second_term,
      sumEven = 0;
  do {
    if (sum % 2 == 0) {
      sumEven += sum;
    }
    firts_term = second_term;
    second_term = sum;
    sum = firts_term + second_term;

  } while (sum < n_term);

  return sumEven;
}

int Guia1Problems::sum_n_commons_multiples(int a, int b, int c) {
  int *multiples = new int;
  int positions = 0;
  int sum = 0;

  for (int i = 1; i < c; i++) {
    if (a * i < c) {
      sum += a * i;
      *(multiples + positions) = a * i;
      positions++;
    }
  }
  for (int x = 1; x < c; x++) {
    if (b * x < c && (b * x) % a != 0) {
      sum += b * x;
      *(multiples + positions) = b * x;
      positions++;
    }
  }

  for (int i = 0; i < positions; i++) {
    cout << *(multiples + i);
    if (i != positions - 1) {
      cout << '+';
    } else {
      cout << '=' << sum;
    }
  }
  delete multiples;
  multiples = nullptr;

  return sum;
}

int Guia1Problems::power(int base, int exponent) {
  int result = 1;
  for (int i = 0; i < exponent; i++) {
    result *= base;
  }

  return result;
}

int Guia1Problems::sum_powers_of_digits(int number) {
  int sum = 0, remainder = 0;

  if (number >= 10) {
    do {
      remainder = number % 10;
      sum += power(remainder, remainder);
      number = number / 10 - remainder / 10;
    } while (number / 10 >= 1);
    cout << "The result of sum is: ";
  }
  return sum + power(number, number);
}

bool Guia1Problems::is_prime(int number) {
  /*
   * Calculate until square root
   */
  if (number <= 1) {
    return false;
  }
  for (int div = 2; div * div <= number; div++) {
    if (number % div == 0) {
      return false;
    }
  }
  return true;
}

int Guia1Problems::calculate_n_term_prime(int position) {
  int num = 2;   // Comenzamos desde el primer número primo
  int count = 0; // Contador de números primos encontrados
  int value = 0;

  while (count < position) {
    if (is_prime(num)) {
      count++;
      value = num;
    }
    num++;
  }
  cout << "The prime in position: " << position << " is " << value << endl;

  return value;
}

int Guia1Problems::greatest_common_factor(int a, int b) {
  if (b == 0)
    return a;
  else
    return greatest_common_factor(b, a % b);
}

int Guia1Problems::least_common_multiple(int a, int b) {
  /*
   * calcula el mínimo común múltiplo de dos números utilizando la fórmula
   * lcm(a, b) = a * (b / gcd(a, b)).
   */
  return a * (b / greatest_common_factor(a, b));
}

int Guia1Problems::least_common_multiple_until_number(int number) {
  int result = 1;
  for (int i = 1; i <= number; i++) {
    result = least_common_multiple(result, i);
  }
  cout << "El minimo comun multiplo es: " << result << endl;

  return result;
}

int Guia1Problems::maxime_prime_factor(int number) {
  int maxime = 0;
  for (int i = 2; i <= number; i++) {
    if (number % i == 0) {
      if (is_prime(i)) {
        maxime = i;
      }
    }
  }
  cout << "The maxime prime factor is: " << maxime << endl;

  return maxime;
}

int Guia1Problems::sum_primes_until_number(int number) {
  int sum = 0;
  for (int i = 2; i < number; i++) {
    if (is_prime(i)) {
      sum += i;
    }
  }
  cout << "The sum of primes until number " << number << " is: " << sum << endl;

  return sum;
}

int Guia1Problems::calculate_largest_palindrome(int quantity_digits) {
  int firts_number = 0, second_number = 0, max_product = 0, product;
  int upper_limit = power(10, quantity_digits) - 1;

  int lower_limit = 1 + upper_limit / 10;

  for (int i = upper_limit; i >= lower_limit; i--) {
    for (int j = i; j >= lower_limit; j--) {
      product = i * j;
      if (product < max_product) {
        break;
      }

      int number = product;
      int reverse = 0;

      while (number != 0) {
        reverse = reverse * 10 + number % 10;
        number /= 10;
      }

      if (product == reverse && product > max_product) {
        max_product = product;
        firts_number = i;
        second_number = j;
      }
    }
  }
  cout << firts_number << "*" << second_number << "=" << max_product << endl;
  return max_product;
}

int Guia1Problems::fill_matrix_clockwise(int dimension) {
  /* dimesion (int): An odd number for square matrix nxn*/

  // Matrix para guardar la espiral
  int espiral[dimension][dimension];

  // inicializar la matriz con ceros
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      espiral[i][j] = 0;
    }
  }

  // generar la espiral
  int num = power(dimension, 2);
  int suma_diagonales = 0;
  int fil = 0;
  int col = dimension - 1;
  int limite_superior = 0;
  int limite_inferior = dimension - 1;
  int limite_izquierdo = 0;
  int limite_derecho = dimension - 1;
  int numero_ceros = 0;

  while (num >= 1) {
    // llenar fila hacia la izquierda
    for (int j = col; j >= limite_izquierdo; j--) {
      espiral[fil][j] = num;
      num--;
    }

    limite_superior++;
    // llenar columna hacia arriba
    for (int i = fil + 1; i <= limite_inferior; i++) {
      espiral[i][limite_izquierdo] = num;
      num--;
    }

    // llenar fila hacia la derecha
    for (int j = limite_izquierdo + 1; j <= limite_derecho; j++) {
      espiral[limite_inferior][j] = num;
      num--;
    }

    limite_inferior--;
    // llenar columna hacia abajo
    for (int i = limite_inferior; i >= limite_superior; i--) {
      espiral[i][limite_derecho] = num;
      num--;
    }
    limite_izquierdo++;
    limite_derecho--;

    // siguiente fila
    fil = limite_superior;
    col = limite_derecho;
  }

  for (int Aij = 0; Aij < dimension; Aij++) {
    suma_diagonales = suma_diagonales + espiral[Aij][Aij];
  }

  for (int Aij = 0, Bij = (dimension - 1); Bij >= 0; Aij++, Bij--) {
    suma_diagonales = suma_diagonales + espiral[Aij][Bij];
  }
  cout << endl;
  for (int i = 0; i < dimension; i++) {
    cout << "\t\t";
    for (int j = 0; j < dimension; j++) {
      if (espiral[i][j] < 10) {
        cout << 0 << espiral[i][j] << " ";
      } else {
        cout << espiral[i][j] << " ";
      }
    }
    cout << endl;
  }
  cout << "En una espiral de: " << dimension << "x" << dimension
       << ", la suma es: " << suma_diagonales - 1 << endl;

  return 0;
}

int Guia1Problems::collatz(long long n) {
  /*la función collatz toma un número n y devuelve la longitud de su serie de
   * Collatz. La variable length se inicializa en 1 porque el primer término de
   * la serie es n. Luego, iteramos hasta que lleguemos a 1 y en cada iteración,
   * verificamos si el número es par o impar y lo seguimos la regla
   * correspondiente.*/

  int length = 1;
  while (n > 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n * 3 + 1;
    }
    length++;
  }
  return length;
}

int Guia1Problems::largest_seed_collatz() {
  /*leemos el número k del usuario y luego iteramos sobre todas las semillas
   * menores que k. En cada iteración, calculamos la longitud de la serie de
   * Collatz para esa semilla y si es mayor que la longitud máxima actual,
   * actualizamos la longitud máxima y la semilla correspondiente.*/

  long long k;
  cout << "Ingrese un numero: ";
  cin >> k;
  int max_length = 0;
  long long seed = 0;
  for (long long i = 1; i < k; i++) {
    int length = collatz(i);
    if (length > max_length) {
      max_length = length;
      seed = i;
    }
  }

  /*Imprimimos la semilla con la serie más larga y la longitud de esa serie.
   * Luego, para imprimir la serie de Collatz, simplemente iteramos sobre la
   * semilla, siguiendo la regla de la serie de Collatz, e imprimimos cada
   * término de la serie.*/

  cout << "La serie mas larga es con la semilla: " << seed << ", teniendo "
       << max_length << " terminos." << endl;
  cout << "La serie es: ";
  while (seed > 1) {
    cout << seed << ", ";
    if (seed % 2 == 0) {
      seed /= 2;
    } else {
      seed = seed * 3 + 1;
    }
  }
  cout << "1" << endl;

  return 0;
}

int Guia1Problems::count_divisors(int n) {
  /*Función que cuenta los divisores de un número n*/

  int contador = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      // Si i es un divisor, también lo es n/i
      contador += (i * i == n) ? 1 : 2;
    }
  }
  return contador;
}

int Guia1Problems::triangular_number_sequence() {
  int k, n = 1;
  cout << "Ingrese el número de divisores que desea buscar: ";
  cin >> k;
  while (count_divisors(n * (n + 1) / 2) <= k) {
    n++;
  }
  cout << "El número es: " << n * (n + 1) / 2 << " que tiene "
       << count_divisors(n * (n + 1) / 2) << " divisores." << endl;
  return 0;
}
