#pragma once
#include <string>
#include <vector>
#include "room.h"
#include "Booking.h"
#include "Guest.h"
#include "Staff.h"
using namespace std;


// class for bill and payment to be created

class Hotel {
	string hotelName;
	string address;
	string city;
	string phoneNumber;
	int RoomCount{};
	int StaffCount{};
	int BookingCount{};
	int GuestCount{};
	vector<Room> rooms;
	vector<Staff> staff;
	vector<Booking> bookings;
	vector<Guest> guests;
public:
	//default constructor
	Hotel() {}
	//constructor with all attrributes
	Hotel(string hotelName, string address, string city, string phoneNumber);

	void setName(string hotelName);
	void setAddress(string address);
	void setCity(string city);
	void setPhone(string phoneNumber);
	void setRoomCount(int RoomCount);
	void setStaffCount(int StaffCount);
	void setBookingCount(int BookingCount);
	void setGuestCount(int GuestCount);

	string getName() const;
	string getAddress() const;
	string getCity() const;
	string getPhone() const;
	int getRoomCount() const;
	int getStaffCount() const;
	int getBookingCount() const;
	int getGuestCount() const;


	void addRoom(Room& room);
	void removeRoom(int roomNum);
	Room* getRoomById(int roomNum);
	vector<Room> getUnoccupiedRooms();
	void printUnoccupiedRooms();
	void bookRoom(int roomNum);

	void addBooking(Booking& booking);
	void removeBooking(int bookingId);
	void cancelBooking(int bookingId);
	Booking* getBookingById(int bookingId);

	double calculateBill(int bookingId);

	void addStaff(const Staff& employee);
	void removeStaff(string staffName);
	Staff* getStaffByName(string staffName);

	void addGuest(const Guest& guest);
	void removeGuest(string guestName);
	Guest* getGuestByName(string guestName);

	double getTotalRevenue();

	void getHotelInfo();
	void getRoomInfo(int roomNum);
	void getStaffInfo(string staffName);
	void deleteRoomsDynamically();
	void deleteBookingsDynamically();
	void deleteGuestsDynamically();
	void deleteStaffDynamically();
};
