#include <string>
#include <vector>
using namespace std;
#pragma once

class Room {
	int roomNum{};
	string roomStatus;
	int maxOccupancy{};
	double roomPrice{};
public:
	//default constructor
	Room() : roomNum(000), roomStatus("Available"), maxOccupancy(0), roomPrice(0.0) {}

	//constructor with all attrributes
	Room(int roomNum, string roomStatus, int maxOccupancy, double roomPrice) :
		roomNum(roomNum), roomStatus(roomStatus), maxOccupancy(maxOccupancy),
		roomPrice(roomPrice){}

	//Getters and Setters
	int getRoomNum();
	void setRoomNum(int roomNum);
	string getRoomStatus() const;
	void setRoomStatus(string roomStatus);
	int getMaxOccupancy() const;
	void setMaxOccupancy(int maxOccupancy);
	double getRoomPrice() const;
	void setRoomPrice(double roomPrice);

	void getRoomInfo();


	//Other operations
	bool isAvailable();

	//bookRoom and cancelBooking both exists in Hotel class 
	//but the difference is that here responsible for managing the booking of a specific room
	//while in Hotel responsible for managing the overall booking of rooms in the hotel and usually called by Guest obj
	void bookRoom();
	void cancelBooking();
	friend class Booking;
};