#include <iostream>

#include "room.h"
#include "seat.h"

using namespace std;

Room::Room(int rows, int numbers) : rows(rows), numbers(numbers), state('o'){
    seats = fill_seats();
}

Seat** Room::fill_seats(){
    Seat** tempSeats = new Seat*[rows];
    for (int i = 0; i < rows; ++i) {
        tempSeats[i] = new Seat[numbers];
        for (int j = 0; j < numbers; ++j) {
            tempSeats[i][j] = Seat(i + 1, j + 1);
        }
    }
    return tempSeats;
}

Room::~Room(){
    for (int i = 0; i < rows; ++i) {
        delete[] seats[i];
    }
    delete[] seats;
}

bool Room::reserveSeat(int row, int number){
    return true;
}

void Room::printRoom() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < numbers; ++j) {
            cout << seats[i][j].getState() << " ";
        }
        cout << std::endl;
    }
}
