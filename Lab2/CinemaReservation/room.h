#ifndef ROOM_H
#define ROOM_H
#include "./seat.h"

class Room {
private:
    int rows;
    int numbers;
    char state;
    Seat** seats;

public:
    Room(int rows, int numbers);

    ~Room();

    int getRows() const {
        return this->rows;
    }

    int getNumbers() const {
        return this->numbers;
    }

    char getState() const {
        return this->state;
    }

    void printRoom() const;

protected:

    Seat** fill_seats();
};

#endif // ROOM_H
