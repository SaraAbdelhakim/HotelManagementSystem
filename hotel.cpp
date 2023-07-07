#include "Hotel.h"
#include <iostream>

Hotel::Hotel(string hotelName, string address, string city, string phoneNumber)
{
	setName(hotelName);
	setAddress(address);
	setCity(city);
	setPhone(phoneNumber);
}

void Hotel::setName(string hotelName)
{
	this->hotelName = hotelName;
}

void Hotel::setAddress(string address)
{
	this->address = address;
}

void Hotel::setCity(string city)
{
	this->city = city;
}

void Hotel::setPhone(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Hotel::setRoomCount(int RoomCount)
{
	this->RoomCount = RoomCount;
}

void Hotel::setStaffCount(int StaffCount)
{
	this->StaffCount = StaffCount;
}

void Hotel::setBookingCount(int BookingCount)
{
	this->BookingCount = BookingCount;
}

void Hotel::setGuestCount(int GuestCount)
{
	this->GuestCount = GuestCount;
}

string Hotel::getName() const
{
	return hotelName;
}

string Hotel::getAddress() const
{
	return address;
}

string Hotel::getCity() const
{
	return city;
}

string Hotel::getPhone() const
{
	return phoneNumber;
}

int Hotel::getRoomCount() const
{
	return RoomCount;
}

int Hotel::getStaffCount() const
{
	return StaffCount;
}

int Hotel::getBookingCount() const
{
	return BookingCount;
}

int Hotel::getGuestCount() const
{
	return GuestCount;
}

void Hotel::addRoom(Room& room)
{
	rooms.push_back(room);
	RoomCount++;
}

void Hotel::removeRoom(int roomNum)
{
	for (auto i = rooms.begin(); i != rooms.end(); ++i) {
		if (i->getRoomNum() == roomNum) {
			rooms.erase(i);
			break;
		}
	}
	RoomCount--;
}

void Hotel::addBooking(Booking& booking)
{
	bookings.push_back(booking);
	BookingCount++;
}

void Hotel::removeBooking(int bookingId)
{
	for (auto i = bookings.begin(); i != bookings.end(); ++i) {
		if (i->getBookingId() == bookingId) {
			bookings.erase(i);
			break;
		}
	}
	BookingCount--;
}

Room* Hotel::getRoomById(int roomNum)
{
	//iterates over the range of rooms vector
	for (auto& room : rooms) {
		if (room.getRoomNum() == roomNum) {
			return &room;
		}
	}
	return nullptr; // Room not found
}

vector<Room> Hotel::getUnoccupiedRooms() {
	vector<Room> unoccupiedRooms;
	for (Room& room : rooms) {
		if (room.isAvailable()) {
			unoccupiedRooms.push_back(room);
		}
	}
	return unoccupiedRooms;
}

void Hotel::printUnoccupiedRooms()
{
	vector<Room> unoccupiedRooms = getUnoccupiedRooms();
	cout << "Available Rooms are: ";
	for (Room& room : unoccupiedRooms) {
		cout << room.getRoomNum() << ",";
		}
	cout << endl;
}


void Hotel::bookRoom(int roomNum) {
	// Find the room with the given room number
	Room* roomToBook = getRoomById(roomNum);

	// Check if the room was found
	if (roomToBook != nullptr) {
		// Check if the room is available to be booked
		if (roomToBook->isAvailable()) {
			// Book the room
			roomToBook->bookRoom();
			cout << "Room " << roomNum << " has been successfully booked."<<endl;
		}
		else {
			cout << "Room " << roomNum << " is already booked."<<endl
				<<"Please choose a room from the following list: "<<endl;
			getUnoccupiedRooms();
		}
	}
	else {
		cout << "Room " << roomNum<< " does not exist."<<endl;
	}
}

void Hotel::cancelBooking(int bookingId)
{
	for (Booking& booking : bookings) {
		if (booking.getBookingId() == bookingId) {
			Room* room=	booking.getRoom();
			room->cancelBooking();
			booking.setBookingStatus("Cancelled");
			return; // Exit the loop after cancelling the booking
		}
	}
	// If the booking ID was not found, display an appropriate message or throw an exception
	cout << "Booking ID not found."<<endl;
	

}

Booking* Hotel::getBookingById(int bookingId)
{
	//iterates over the range of bookings vector
	for (auto& booking : bookings) {
		if (booking.getBookingId() == bookingId) {
			return &booking;
		}
	}
	return nullptr; // Booking not found
}

double Hotel::calculateBill(int bookingId)
{
	double Bill;
	Booking* booking = getBookingById(bookingId);
	Bill= booking->calculateTotalBill();
	return Bill;
}

double Hotel::getTotalRevenue()
{
	double totalRevenue = 0.0;

	for (Booking& booking : bookings) {
		totalRevenue += booking.calculateTotalBill();
	}

	return totalRevenue;
}


void Hotel::addStaff(const Staff& employee)
{
	staff.push_back(employee);
	StaffCount++;
}

void Hotel::removeStaff(string staffName)
{
	
	for (auto i = staff.begin(); i != staff.end(); ++i) {
		if (i->getName() == staffName) {
			staff.erase(i);
			break;
		}
	}
	StaffCount--;
}

Staff* Hotel::getStaffByName(string staffName)
{
	//iterates over the range of staff vector
	for (auto& employee : staff) {
		if (employee.getName() == staffName) {
			return &employee;
		}
	}
	return nullptr; // staff not found
}

void Hotel::addGuest(const Guest& guest)
{
	guests.push_back(guest);
	GuestCount++;
}

void Hotel::removeGuest(string guestName)
{
	for (auto i = guests.begin(); i != guests.end(); ++i) {
		if (i->getName() == guestName) {
			guests.erase(i);
			break;
		}
	}
	GuestCount--;
}

Guest* Hotel::getGuestByName(string guestName)
{
	//iterates over the range of Guests vector
	for (auto& guest : guests) {
		if (guest.getName() == guestName) {
			return &guest;
		}
	}
	return nullptr; // Guest not found
}

void Hotel::getHotelInfo()
{
	cout << "Hotel Info: " << endl
		<< "Hotel Name: " << getName() << endl
		<< "Address: " << getAddress() << endl
		<< "City: " << getCity() << endl
		<< "Phone Number: " << getPhone() << endl
		<< "Number of Rooms: " << getRoomCount() << endl;
}

void Hotel::getRoomInfo(int roomNum)
{
	Room* room = getRoomById(roomNum);
	room->getRoomInfo();
}

void Hotel::getStaffInfo(string staffName)
{
	Staff* employee = getStaffByName(staffName);
	employee->getStaffInfo();
}

void Hotel::deleteRoomsDynamically()
{
	// Create a vector to store pointers to the rooms to be deleted
	vector<Room*> roomsToDelete;

	// Copy the pointers to the rooms to be deleted
	for (Room& room : rooms) {
		roomsToDelete.push_back(&room);
	}

	// Remove the rooms from the hotel and delete them
	for (Room* room : roomsToDelete) {
		removeRoom(room->getRoomNum());
		delete room;
	}
}

void Hotel::deleteBookingsDynamically()
{
	vector<Booking*> bookingsToDelete;

	for (Booking& booking : bookings) {
		bookingsToDelete.push_back(&booking);
	}

	for (Booking* booking : bookingsToDelete) {
		removeBooking(booking->getBookingId());
		delete booking;
	}
}

void Hotel::deleteGuestsDynamically()
{
	vector<Guest*> guestsToDelete;

	for (Guest& guest : guests) {
		guestsToDelete.push_back(&guest);
	}

	for (Guest* guest : guestsToDelete) {
		removeGuest(guest->getName());
		delete guest;
	}
}

void Hotel::deleteStaffDynamically()
{
	vector<Staff*> staffToDelete;

	for (Staff& employee : staff) {
		staffToDelete.push_back(&employee);
	}

	for (Staff* employee : staffToDelete) {
		removeStaff(employee->getName());
		delete employee;
	}
}


