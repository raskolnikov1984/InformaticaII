#ifdef GUIA1PROBLEMS_H
#endif

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

class Guia1Problems {
public:
  const char *is_vowel_or_consonant(int c);

  ReturnCashStruc calculate_return_cash(int return_cash);

  bool isValidDate(int day, int month);

  void printDiamond();
};
