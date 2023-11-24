#pragma once

#define IN
#define OUT
#define INOUT

enum class GenderBook
{
	Novel,
	Comic,
	Poem,
	Autobiography,
	Encyclopedia,
	Thriller,
	Cookery
};

enum class BookingStatus {
	Requested,
	Pending,
	Confirmed,
	CheckedIn,
	CheckedOut,
	Canceled,
	Abandoned
};

