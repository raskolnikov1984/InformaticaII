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

ReturnCashStruc calculate_return_cash(int return_cash) {y
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
        Serial.print("You can't complete this expected amount. : ");
        Serial.println(return_cash);
    }

    return return_cash_struc;
}

void setup() {
    Serial.begin(9600);
    
}

void loop() {
    if (Serial.available() > 0) {
        int amountToReturn = Serial.parseInt(); // Leer el monto ingresado

        if (amountToReturn == -1) {
            Serial.println("Saliendo...");
            while (true); // Detener el programa
        }

        Serial.print("Monto a devolver: ");
        Serial.println(amountToReturn);

        ReturnCashStruc result = calculate_return_cash(amountToReturn);

        // Imprimir el resultado
        Serial.print("Fifty Thousand COP: ");
        Serial.println(result.fiftyThousandCOP);
        Serial.print("Twenty Thousand COP: ");
        Serial.println(result.twentyThousandCOP);
        Serial.print("Ten Thousand COP: ");
        Serial.println(result.tenThousandCOP);
        Serial.print("Five Thousand COP: ");
        Serial.println(result.fiveThousandCOP);
        Serial.print("Two Thousand COP: ");
        Serial.println(result.twoThousandCOP);
        Serial.print("One Thousand COP: ");
        Serial.println(result.oneThousandCOP);
        Serial.print("Five Hundred COP: ");
        Serial.println(result.fiveHoundredCOP);
        Serial.print("Two Hundred COP: ");
        Serial.println(result.twoHoundredCOP);
        Serial.print("One Hundred COP: ");
        Serial.println(result.oneHoundredCOP);
        Serial.print("Fifty COP: ");
        Serial.println(result.fiftyCOP);
        Serial.print("Remainder COP: ");
        Serial.println(result.remainderCOP);

        Serial.println("Ingrese el monto a devolver en COP (o -1 para salir):");
    }
}
