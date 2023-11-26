#pragma once

#define IN
#define OUT
#define INOUT

enum class BookingStatus {
	Requested,
	Pending,
	Confirmed,
	CheckedIn,
	CheckedOut,
	Canceled,
	Abandoned
};

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7
};

