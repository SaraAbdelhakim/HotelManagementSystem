#pragma once
#include <string>
#include <iostream>
#include "Date.h"
#include "Guest.h"
#include "room.h"
using namespace std;


class Booking{
	int bookingId{};
	Room* room{};
	Guest* guest{};
	Date checkInDate;
	Date checkOutDate;
	int numOfGuests{};
	double totalBill{};
	string paymentStatus;
	int numOfNights{};
	string bookingStatus;
	string GuestName;
public:
	//default constructor
	Booking() {}

	//constructor with all attrributes
	Booking(int bookingId, string bookingStatus, Guest* guest, Room* room, const Date& checkInDate, const Date& checkOutDate)
		: bookingId(bookingId), bookingStatus(bookingStatus), guest(guest), room(room), checkInDate(checkInDate), checkOutDate(checkOutDate) {}

	//setters
	void setBookingId(int bookingId);

	void setCheckInDate(Date& checkInDate);
	void setCheckOutDate(Date& checkOutDate);
	void setNumOfGuests(int numOfGuests);
	void setTotalBill(double totalBill);
	void setPaymentStatus(string paymentStatus);
	void setBookingStatus(string bookingStatus);
	void setRoom(Room* room);
	void setGuest(Guest* guest);



	//getters
	int getBookingId() const;

	string getCheckInDate();
	string getCheckOutDate();
	int getNumOfGuests() const;
	double getTotalBill() const;
	string getPaymentStatus() const;
	string getBookingStatus() const;
	Room* getRoom();

	Guest* getGuest();

	//other Operations
	void BookRoom();
	void PrintBookingDetails();
	int calculateNumOfNights();
	double calculateTotalBill();
	void cancelBooking();
	void checkIn(Date& checkInDate);
	void checkOut(Date& checkOutDate);
};

