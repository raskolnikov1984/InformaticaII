#include "return_cash_calculator.h"

using namespace std;

int main()
{
    ReturnCashStruc result;
    int return_cash = 15600;

    cout << "Please type the amount to return: ";
    cin >> return_cash;

    cout << "The amount to return: " << return_cash << endl;

    result = calculate_return_cash(return_cash);
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

    return 0;
}
