#include "Booking.h"

//setters
void Booking::setBookingId(int bookingId)
{
	this->bookingId = bookingId;
}

void Booking::setCheckInDate(Date& checkInDate)
{
	this->checkInDate = checkInDate;
}

void Booking::setCheckOutDate(Date& checkOutDate)
{
	this->checkOutDate = checkOutDate;
}

void Booking::setNumOfGuests(int numOfGuests) 
{
	this->numOfGuests = numOfGuests;
}

void Booking::setTotalBill(double totalBill)
{
	this->totalBill = totalBill;
}

void Booking::setPaymentStatus(string paymentStatus)
{
	this->paymentStatus = paymentStatus;
}

void Booking::setBookingStatus(string bookingStatus) 
{
	this->bookingStatus = bookingStatus;
}

void Booking::setRoom(Room* room)
{
	this->room = room;
}

void Booking::setGuest(Guest* guest)
{
	this->guest = guest;
}

//getters
int Booking::getBookingId() const
{
	return bookingId;
}

string Booking::getCheckInDate()
{
	int year = checkInDate.getYear();
	int month = checkInDate.getMonth();
	int day = checkInDate.getDay();
	string strYear = to_string(year);
	string strMonth = to_string(month);
	string strDay = to_string(day);
	return strYear + "/" + strMonth + "/" + strDay;
}

string Booking::getCheckOutDate()
{
	int year = checkOutDate.getYear();
	int month = checkOutDate.getMonth();
	int day = checkOutDate.getDay();
	string strYear = to_string(year);
	string strMonth = to_string(month);
	string strDay = to_string(day);
	return strYear + "/" + strMonth + "/" + strDay;
}

int Booking::getNumOfGuests() const
{
	return numOfGuests;
}

double Booking::getTotalBill() const
{
	return totalBill;
}

string Booking::getPaymentStatus() const
{
	return paymentStatus;
}

string Booking::getBookingStatus() const
{
	return bookingStatus;
}

Room* Booking::getRoom()
{
	return room;
}

Guest* Booking::getGuest() 
{
	return guest;
}

//other Operations

void Booking::PrintBookingDetails() 
{
	cout << "Booking Details: " << endl;
	cout << "Booking ID: " << getBookingId() << endl;
	cout << "Booking Status: " << getBookingStatus() << endl;
	cout << "Guest Name: " << guest->getName() << endl;
	cout << "Room Number: " << room->getRoomNum() << endl;
	cout << "Number Of Guests: " << getNumOfGuests() << endl;
	cout << "Total Price: " << calculateTotalBill() << endl;
	cout << "Payment Status: " << getPaymentStatus() << endl;
	cout << "Number Of Nights: " << calculateNumOfNights() << endl;
}

int Booking::calculateNumOfNights()
{
	int year, month, day;

	year = checkOutDate.getYear() - checkInDate.getYear();
	month = checkOutDate.getMonth() - checkInDate.getMonth();
	day = checkOutDate.getDay() - checkInDate.getDay();

	numOfNights = (year * 365) + (month * 30) + day;
	return numOfNights;
}

double Booking::calculateTotalBill() 
{
	double bill = 0;
	bill = room->getRoomPrice() * calculateNumOfNights();
	return bill;
}

void Booking::cancelBooking()
{
	this->bookingStatus = "cancelled";
	room->setRoomStatus("available");
}

void Booking::BookRoom()
{
	this->bookingStatus = "confirmed";
	room->setRoomStatus("booked");
}

void Booking::checkIn(Date& checkInDate)
{
	this->checkInDate = checkInDate;
	room->setRoomStatus("booked");
}
void Booking::checkOut(Date& checkOutDate)
{
	this->checkOutDate = checkOutDate;
	room->setRoomStatus("available");
}
