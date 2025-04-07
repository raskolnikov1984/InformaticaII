#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "./room.h"
#include "./seat.h"

using namespace testing;

class CinemaReserve : public ::testing::Test {
protected:
    Room* room;

    void SetUp() override {
        room = new Room(15, 20);
    }

    void TearDown() override {
        delete room;
    }
};

TEST_F(CinemaReserve, CreateRoomTest){
    EXPECT_EQ(room->getRows(), 15);
    EXPECT_EQ(room->getNumbers(), 20);
    EXPECT_EQ(room->getState(), 'o');

    room->printRoom();

};

TEST_F(CinemaReserve, CoordinatesSeat){
    RowMapper rowMap[room->getRows()];
    room->initRowMap(rowMap);

    int rowIndexA = room->getRowIndex(rowMap, 'A');
    int rowIndexB = room->getRowIndex(rowMap, 'B');
    int rowIndexO = room->getRowIndex(rowMap, 'O');
    int rowIndexQ = room->getRowIndex(rowMap, 'Q');

    EXPECT_EQ(rowIndexA, 0);
    EXPECT_EQ(rowIndexB, 1);
    EXPECT_EQ(rowIndexO, 14);
    EXPECT_EQ(rowIndexQ, -1);
};

TEST_F(CinemaReserve, ReserveSeatTeas){
    int rowA = 'A';

    bool reservedSeatA10 = room->reserveSeat(rowA, 10);
    bool reservedSeatA11 = room->reserveSeat(rowA, 11);
    bool reservedSeatA12 = room->reserveSeat(rowA, 12);
    bool reservedSeatA13 = room->reserveSeat(rowA, 13);
    bool reservedSeatA14 = room->reserveSeat(rowA, 14);

    EXPECT_EQ(reservedSeatA10, true);
    EXPECT_EQ(reservedSeatA11, true);
    EXPECT_EQ(reservedSeatA12, true);
    EXPECT_EQ(reservedSeatA13, true);
    EXPECT_EQ(reservedSeatA14, true);

    EXPECT_EQ(room->reservedSeats, 5);

    int rowB = 'B';
    bool reservedSeatB1 = room->reserveSeat(rowB, 1);
    bool reservedSeatB2 = room->reserveSeat(rowB, 2);
    bool reservedSeatB3 = room->reserveSeat(rowB, 3);
    bool reservedSeatB4 = room->reserveSeat(rowB, 4);
    bool reservedSeatB5 = room->reserveSeat(rowB, 5);

    EXPECT_EQ(reservedSeatB1, true);
    EXPECT_EQ(reservedSeatB2, true);
    EXPECT_EQ(reservedSeatB3, true);
    EXPECT_EQ(reservedSeatB4, true);
    EXPECT_EQ(reservedSeatB5, true);

    EXPECT_EQ(room->reservedSeats, 10);

    room->printRoom();
};

TEST(Seat, SeatTest){
    Seat seat(1, 10);
    EXPECT_EQ(seat.getRow(), 1);
    EXPECT_EQ(seat.getNumber(), 10);
    EXPECT_EQ(seat.getState(), '-');
};
