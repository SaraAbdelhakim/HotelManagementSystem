#include "room.h"
#include <iostream>

void Room::setRoomNum(int roomNum)
{
	this->roomNum = roomNum;
}

void Room::setRoomPrice(double roomPrice)
{
	this->roomPrice = roomPrice;
}

void Room::setRoomStatus(string roomStatus)
{
	this->roomStatus = roomStatus;
}

void Room::setMaxOccupancy(int maxOccupancy)
{
	this->maxOccupancy = maxOccupancy;
}

int Room::getRoomNum()
{
	return roomNum;
}

double Room::getRoomPrice() const
{
	return roomPrice;
}

string Room::getRoomStatus() const
{
	return roomStatus;
}

int Room::getMaxOccupancy() const
{
	return maxOccupancy;
}

void Room::getRoomInfo()
{
	cout << "Room Info: " << endl
		<< "Room Number:" << getRoomNum() << endl
		<< "Room Status" << getRoomStatus() << endl
		<< "Max Occupancy" << getMaxOccupancy() << endl
		<< "Room Price: " << getRoomPrice() << endl;
}

bool Room::isAvailable()
{
	if (roomStatus == "available")
		return true;
	else
		return false;
}

void Room::bookRoom()
{
	this->roomStatus = "booked";
}

void Room::cancelBooking()
{
	this->roomStatus = "available";
}

