#define GUIA1PROBLEM_H

class Guia1Problems {
public:
  struct ReturnCashStruc {
    int fiftyThousandCOP = 0;
    int twentyThousandCOP = 0;
    int tenThousandCOP = 0;
    int fiveThousandCOP = 0;
    int twoThousandCOP = 0;
    int oneThousandCOP = 0;
    int fiveHoundredCOP = 0;
    int twoHoundredCOP = 0;
    int oneHoundredCOP = 0;
    int fiftyCOP = 0;
    int remainderCOP = 0;
  };

  const char *is_vowel_or_consonant(int c);

  ReturnCashStruc calculate_return_cash(int return_cash);

  bool isValidDate(int day, int month);

  void printDiamond(int odd_number);

  float calculate_aproximate_euluer_value(int number);

  int calculate_sum_time(int first_time, int second_time);

  int calculate_sum_even_numbers_in_fibonacci(int n_term);

  int sum_n_commons_multiples(int a, int b, int c);

  int power(int base, int exponent);

  int sum_powers_of_digits(int number);

  bool is_prime(int number);

  int calculate_n_term_prime(int number);

  int least_common_multiple(int a, int b);

  int greatest_common_factor(int a, int b);

  int least_common_multiple_until_number(int number);

  int maxime_prime_factor(int number);

  int sum_primes_until_number(int number);

  int calculate_largest_palindrome(int quantity_digits);

  int fill_matrix_clockwise(int dimesion);
};
