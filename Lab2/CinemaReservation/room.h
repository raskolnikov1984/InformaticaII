#ifndef ROOM_H
#define ROOM_H
#include "./seat.h"

struct RowMapper {
    char rowChar;
    int rowIndex;
};

class Room {
private:
    int rows;
    int numbers;
    char state;

public:
    Seat** seats;
    RowMapper* rowMap;

    int reservedSeats;

    int unreservedSeats;

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

    bool reserveSeat(char row, int number);

    bool unReserveSeat(char row, int number);

    void initRowMap(RowMapper rowMap[]);

    int getRowIndex(RowMapper rowMap[], char row);

    void printRoom() const;

protected:

    Seat** fill_seats();
};


#endif // ROOM_H


