#include <iostream>
#include <cctype> // Para toupper()

#include "room.h"
#include "seat.h"

using namespace std;

Room::Room(int rows, int numbers) : rows(rows), numbers(numbers), state('o'){
    rowMap = new RowMapper[rows];
    seats = fill_seats();
    initRowMap(rowMap);
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

void Room::initRowMap(RowMapper rowMap[]) {
    for (int i = 0; i < rows; i++) {
        rowMap[i].rowChar = 'A' + i; // 'A'=0, 'B'=1, ..., 'O'=14
        rowMap[i].rowIndex = i;
    }
}

int Room::getRowIndex(RowMapper rowMap[], char row) {
    // Función para buscar el índice de una fila
    row = toupper(row); // Convertir a mayúscula
    for (int i = 0; i < rows; i++) {
        if (rowMap[i].rowChar == row) {
            return rowMap[i].rowIndex;
        }
    }
    return -1; // Fila no encontrada
}

bool Room::reserveSeat(char row, int number){
    bool reservedSeat;
    int rowSeat = getRowIndex(this->rowMap, row);

    seats[rowSeat][number].state = '+';
    reservedSeat = true;

    this->reservedSeats++;

    return reservedSeat;
}

void Room::printRoom() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < numbers; ++j) {
            cout << seats[i][j].getState() << " ";
        }
        cout << std::endl;
    }
}
