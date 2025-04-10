#ifndef SEAT_H
#define SEAT_H

class Seat {

private:
    int row;
    int number;

public:
    char state;
    Seat() : row(0), number(0), state('-') {}

    Seat(int row, int number) : row(row), number(number), state('-') {}

    const int getRow(){
        return this->row;
    }

    const int getNumber(){
        return this->number;
    }

    const char getState(){
        return this->state;
    }
};

#endif // SEAT_H
