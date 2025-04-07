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

TEST(Seat, SeatTest){
    Seat seat(1, 10);
    EXPECT_EQ(seat.getRow(), 1);
    EXPECT_EQ(seat.getNumber(), 10);
    EXPECT_EQ(seat.getState(), '-');
};
