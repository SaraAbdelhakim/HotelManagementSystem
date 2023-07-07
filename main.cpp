#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include "hotel.h"

using namespace std;

// Function to create a Room object from user input
Room* createRoomFromUserInput(Hotel& hotel) {
    int roomNum;
    string roomStatus;
    int maxOccupancy;
    double roomPrice;

    // take the data from the user
    cout << "Enter room number: ";
    cin >> roomNum;

    cout << "Enter room status: ";
    cin >> roomStatus;

    cout << "Enter maximum occupancy: ";
    cin >> maxOccupancy;

    cout << "Enter room price: ";
    cin >> roomPrice;

    // Create a Room object dynamically
    Room* room = new Room(roomNum, roomStatus, maxOccupancy, roomPrice);
    hotel.addRoom(*room);
    // Return the dynamically allocated Room object
    return room;
}

// Function to create a Guest object from user input
Guest* createGuestFromUserInput(Hotel& hotel) {

    string first_name;
    string last_name;
    string gender;
    int age;
    string nationality;
    string address;
    string phone;

    try
    {
        // take the data from the user
        cout << "Enter first name: ";
        cin >> first_name;

        cout << "Enter last name: ";
        cin >> last_name;

        cout << "Enter gender: ";
        cin >> gender;

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter nationality: ";
        cin >> nationality;

        cout << "Enter address: ";
        cin >> address;

        cout << "Enter phone: ";
        cin >> phone;
        // Create a Guest object dynamically
        Guest* guest = new Guest(first_name, last_name, gender, age, address, phone, nationality);
        hotel.addGuest(*guest);
        // Return the dynamically allocated Guest object
        return guest;
    }
    catch (const exception& e)
    {
        cout << "An error occurred: " << e.what() << endl;
    }
}

// Function to create a Staff object from user input
Staff* createStaffFromUserInput(Hotel& hotel) {
    string first_name;
    string last_name;
    string gender;
    int age;
    string position;
    double salary;
    Date EmploymentDate;
    int shiftHours;

    // take the data from the user
    cout << "Enter first name: ";
    cin >> first_name;

    cout << "Enter last name: ";
    cin >> last_name;

    cout << "Enter gender: ";
    cin >> gender;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter position: ";
    cin >> position;

    cout << "Enter salary: ";
    cin >> salary;

    int year, month, day;
    cout << "Enter employment year: ";
    cin >> year;

    cout << "Enter employment month: ";
    cin >> month;

    cout << "Enter employment day: ";
    cin >> day;

    EmploymentDate.setYear(year);
    EmploymentDate.setMonth(month);
    EmploymentDate.setDay(day);

    cout << "Enter shiftHours: ";
    cin >> shiftHours;

    // Create a Staff object dynamically
    Staff* staff = new Staff(first_name, last_name, gender, age, position, salary, EmploymentDate, shiftHours);
    hotel.addStaff(*staff);
    // Return the dynamically allocated Staff object
    return staff;
}

// Function to create a Booking object from user input
Booking* createBookingFromUserInput(Hotel &hotel) {
    int bookingId;
    string status;
    int roomNum;
    string guestName;
    Date checkInDate;
    Date checkOutDate;

    // take the data from the user
    cout << "Enter Booking Id: ";
    cin >> bookingId;

    cout << "Enter Booking Status: ";
    cin >> status;

    cout << "Enter Room Number: ";
    cin >> roomNum;

    cout << "Enter Guest Name: ";
    cin >> guestName;

    // Create a Room object dynamically
    Room* room = hotel.getRoomById(roomNum);

    // Create a Guest object dynamically
    Guest* guest = hotel.getGuestByName(guestName); 

    // take the check-in date from the user
    int inYear, inMonth, inDay;
    cout << "Enter Check-in Year: ";
    cin >> inYear;

    cout << "Enter Check-in Month: ";
    cin >> inMonth;

    cout << "Enter Check-in Day: ";
    cin >> inDay;

    checkInDate.setYear(inYear);
    checkInDate.setMonth(inMonth);
    checkInDate.setDay(inDay);

    // take the check-out date from the user
    int outYear, outMonth, outDay;
    cout << "Enter Check-out Year: ";
    cin >> outYear;

    cout << "Enter Check-out Month: ";
    cin >> outMonth;

    cout << "Enter Check-out Day: ";
    cin >> outDay;

    checkOutDate.setYear(outYear);
    checkOutDate.setMonth(outMonth);
    checkOutDate.setDay(outDay);

    // Create a Booking object dynamically
    Booking* booking = new Booking(bookingId, status, guest, room, checkInDate, checkOutDate);
    hotel.addBooking(*booking);
    return booking;
}

// Function to save a Room object to a file
void saveRoomToFile(Room& room, const string& filename) {
    ofstream file(filename, ios::app);
    // Open the file for writing
    if (file.is_open()) {
        // Write room details to the file
        file << room.getRoomNum() << "," 
            << room.getRoomStatus() << ","
            << room.getMaxOccupancy() << "," 
            << room.getRoomPrice() << endl;
        //Close the file
        file.close();
        cout << "Room saved to file successfully."<< endl;
    }
    else {
        cerr << "Error: Unable to open the file."<< endl;
    }
}

// Function to save a Guest object to a file
void saveGuestToFile(Guest& guest, const string& filename) {
    // Open the file for writing
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        // Write guest details to the file
        file << guest.getName() << "," 
            << guest.getGender() << "," 
            << guest.getAge() << ","
            << guest.getAddress() << "," 
            << guest.getPhone() << "," 
            << guest.getNationality() << endl;
        // Close the file
        file.close();
        cout << "Guest saved to file successfully." << endl;
    }
    else {
        cerr << "Error: Unable to open the file." << endl;
    }
}

// Function to save a Staff object to a file
void saveStaffToFile(Staff& staff, const string& filename) {
    // Open the file for writing
    ofstream file(filename, ios::app);
    // Write staff details to the file
    if (file.is_open()) {
        file << staff.getName() << "," 
            << staff.getGender() << "," 
            << staff.getAge() << ","
            << staff.getPosition() << "," 
            << staff.getSalary() << ","
            << staff.getEmploymentDate()<< endl;
        // Close the file
        file.close();
        cout << "Staff saved to file successfully." << endl;
    }
    else {
        cerr << "Error: Unable to open the file." << endl;
    }
}

// Function to save a Booking object to a file
void saveBookingToFile(Booking& booking, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << booking.getBookingId() << ","
            << booking.getBookingStatus() << ","
            << booking.getGuest()->getName() << ","
            << booking.getRoom()->getRoomNum() << ","
            << booking.getCheckInDate() << ","
            << booking.getCheckOutDate() << ","
            << booking.calculateTotalBill() << endl;
        file.close();

        cout << "Booking saved to file successfully." << endl;
    }
    else {
        cerr << "Error: Unable to open the file." << endl;
    }
}

// Function to save the Hotel object to a file
void saveHotelToFile(const Hotel& hotel, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << hotel.getName() << "," << hotel.getAddress() << ","
            << hotel.getCity() << "," << hotel.getPhone() << ","
            << hotel.getRoomCount() << "," << hotel.getStaffCount() << ","
            << hotel.getBookingCount() << endl;
        file.close();
        cout << "Hotel saved to file successfully." << endl;
    }
    else {
        cerr << "Error: Unable to open the file." << endl;
    }
}

// Function to display booking information based on booking ID
void showBookingInformation(const string& filename)
{
    int bookingId;
    cout << "Enter the Booking ID: ";
    cin >> bookingId;
    ifstream file(filename);
    if (file.is_open())
    {
        bool bookingFound = false;
        string line;
        while (getline(file, line))
        {
            // Assuming each line contains booking information separated by commas
            istringstream iss(line);
            int id;
            string status;
            int roomNum;
            string guestName;
            //int checkInYear, checkInMonth, checkInDay;
            //int checkOutYear, checkOutMonth, checkOutDay;

            // Extract the booking information from the line
            if(iss>>id && id == bookingId)
            { 
                bookingFound = true;
                iss.ignore();
                getline(iss, status, ',');
                iss.ignore();
                getline(iss, guestName, ',');
                iss >> roomNum;


                // Print the booking information
                cout << "Booking ID: " << id << endl;
                cout << "Booking Status: " << status << endl;
                cout << "Guest Name: " << guestName << endl;
                cout << "Room Number: " << roomNum << endl;

               // cout << "Check-in Date: " << checkInYear << "/" << checkInMonth << "/" << checkInDay << endl;
               // cout << "Check-out Date: " << checkOutYear << "/" << checkOutMonth << "/" << checkOutDay << endl;
                cout << endl;
                break;
                
            }
        }
        if (!bookingFound) {
            cout << "Booking not found." << endl;
        }
        file.close();
    }
    else
    {
        cerr << "Error: Unable to open the file." << endl;
    }
}

// Function to display room information based on room number
void showRoomInformation(const string& filename)
{
    int roomNum;
    cout << "Enter the Room number: ";
    cin >> roomNum;
    ifstream file(filename);
    if (file.is_open())
    {
        bool roomFound = false;
        string line;
        while (getline(file, line))
        {
            // Assuming each line contains guest information separated by commas
            istringstream iss(line);

            int number;
            string roomStatus;
            int maxOccupancy;
            double roomPrice;

            if(iss>>number && number == roomNum)
            {
                roomFound = true;
                // Extract the room information from the line
                iss.ignore();
                getline(iss, roomStatus, ',');
                iss >> maxOccupancy;
                iss.ignore();
                iss >> roomPrice;

                // Print the guest information
                cout << "Room Number: " << number << endl;
                cout << "Room Status: " << roomStatus << endl;
                cout << "Max Occupancy: " << maxOccupancy << endl;
                cout << "Room Price: " << roomPrice << endl;
                cout << endl;
                
                break;
            }
        }
        if (!roomFound) {
            cout << "Room not found." << endl;
        }
        file.close();
    }
    else
    {
        cerr << "Error: Unable to open the file." << endl;
    }
}

// Function to change room availability in the room.txt file
void changeRoomAvailability(int roomNumber, bool availability) {
    ifstream inputFile("rooms.txt");
    ofstream outputFile("temp.txt");

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        int currentRoomNumber;
        string currentRoomAvailability;
        int maxOccupancy;
        double roomPrice;

            if (iss >> currentRoomNumber)
            {
                iss.ignore();
                getline(iss, currentRoomAvailability, ',');
                iss >> maxOccupancy;
                iss.ignore();
                iss >> roomPrice;
                if (currentRoomNumber == roomNumber) {
                    outputFile << currentRoomNumber << "," << (availability ? "available" : "booked") 
                                << "," << maxOccupancy << "," << roomPrice << endl;
                    found = true;
                }
                else {
                    outputFile << line << endl;
                }
            
            }
    }

    inputFile.close();
    outputFile.close();

    remove("rooms.txt");
    rename("temp.txt", "rooms.txt");

    if (found) {
        cout << "Room availability updated successfully." << endl;
    }
    else {
        cout << "Room not found in the file." << endl;
    }
}

void changeBookingStatus(int bookingId, const string& newStatus) {
    ifstream inputFile("bookings.txt");
    ofstream outputFile("temp.txt");

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        int currentBookingId;
        string currentStatus;
        string guestName;
        int roomNum;

        if (iss >> currentBookingId) {
            iss.ignore();
            getline(iss, currentStatus, ',');
            getline(iss, guestName, ',');
            iss >> roomNum;

            if (currentBookingId == bookingId) {
                outputFile << currentBookingId << "," << newStatus << "," << guestName << "," << roomNum << endl;
                found = true;
            }
            else {
                outputFile << line << endl;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if (found) {
        cout << "Booking status updated successfully." << endl;
    }
    else {
        cout << "Booking not found in the file." << endl;
    }
}

void printAvailableRooms() {
    ifstream file("rooms.txt");
    if (file.is_open()) {
        vector<Room> rooms;
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            int roomNum;
            string roomStatus;
            int maxOccupancy;
            double roomPrice;

            if (iss >> roomNum)
            {
                iss.ignore();
                getline(iss, roomStatus, ',');
                iss >> maxOccupancy;
                iss.ignore();
                iss >> roomPrice;
                rooms.emplace_back(Room(roomNum, roomStatus, maxOccupancy, roomPrice));
            }

        }
        file.close();

        // Print the available room numbers
        cout << "Available Room Numbers:" << endl;
        for (Room& room : rooms) {
            if (room.getRoomStatus()=="available") {
                cout << room.getRoomNum() << endl;
            }
        }
    }
    else {
        cout << "Unable to open the room file." << endl;
    }
}

void copyBillsToFile() {
    ifstream inputFile("bookings.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open file: bookings.txt" << endl;
        return;
    }

    ofstream outputFile("bills.txt", ios::app); // Open the file in append mode
    if (!outputFile.is_open()) {
        cout << "Failed to open file: bills.txt" << endl;
        inputFile.close();
        return;
    }

    int bookingId;
    cout << "Enter the Booking ID: ";
    cin >> bookingId;

    string line;
    bool bookingFound = false;

    while (getline(inputFile, line)) {
        // Parse the line and extract booking information
        int id;
        string status;
        int roomNum;
        string guestName;
        int checkInYear, checkInMonth, checkInDay;
        int checkOutYear, checkOutMonth, checkOutDay;
        double bill;

        // Assuming each line contains booking information separated by commas
        istringstream iss(line);

        // Extract the booking information from the line
        if (iss >> id && id == bookingId) {
            bookingFound = true;
            iss.ignore();
            getline(iss, status, ',');
            iss.ignore();
            getline(iss, guestName, ',');
            iss >> roomNum;
            iss.ignore();
            iss >> checkInYear;
            iss.ignore();
            iss >> checkInMonth;
            iss.ignore();
            iss >> checkInDay;
            iss.ignore();
            iss >> checkOutYear;
            iss.ignore();
            iss >> checkOutMonth;
            iss.ignore();
            iss >> checkOutDay;
            iss.ignore();
            iss >> bill;

            // Write the booking ID and bill to the bills.txt file
            outputFile << "Booking ID: " << bookingId << ", Bill Amount: " << bill << " EUR" << endl;
        }
    }

    if (!bookingFound) {
        cout << "Booking ID not found." << endl;
    }

    inputFile.close();
    outputFile.close();
}

double getTotalRevenue() {
    ifstream inputFile("bills.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open file: bills.txt" << endl;
        return 0;
    }

    double totalRevenue = 0;
    string line;
    while (getline(inputFile, line)) {
        // Parse the line and extract the bill amount
        size_t startPos = line.find(",") + 14; // Find the starting position of the bill amount
        size_t endPos = line.find(" EUR");   // Find the ending position of the bill amount
        if (startPos != string::npos && endPos != string::npos) {
            string billAmountStr = line.substr(startPos, endPos - startPos);
            double billAmount = stod(billAmountStr);
            totalRevenue += billAmount;
        }
    }

    inputFile.close();
    return totalRevenue;
}


int main() {
    // Create instances of the necessary classes
    Hotel hotel;
    // Initialize the hotel, load data from file, etc.
    char another = 'Y';
    int choice;
    do {
        system("COLOR BF");
        system("cls");
        // Display menu options
        cout << "======= Hotel Management System =======" << endl;
        cout << "1. Add Rooms to your Hotel" << endl; //DONE
        cout << "2. Check-in" << endl; //DONE
        cout << "3. Check-out" << endl;
        cout << "4. Book a room" << endl; //DONE
        cout << "5. Cancel booking" << endl;
        cout << "6. Show available rooms" << endl; //DONE 
        cout << "7. Show booking information" << endl; //DONE
        cout << "8. Show room information" << endl;  //DONE
        cout << "9. Show total revenue" << endl; //DONE
        cout << "10. Exit" << endl; //DONE
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            another = 'Y';
            // Use the createRoomFromUserInput function to get a Room object from user input
            while (another == 'Y' || another == 'y')
            {
                Room* room = createRoomFromUserInput(hotel);

                // Save the room to a file
                saveRoomToFile(*room, "rooms.txt");
                cout << endl << "****************************************" << endl;
                cout << "Add another Room (Y/N) ?";
                //flush the output buffer of the stream
                fflush(stdin);
                another = _getche();
                cout << endl << "****************************************" << endl;
            }
            break;

        }
        case 2:
        {
            // Perform check-in operation
            // Prompt user for necessary information (guest details, room number, etc.)
            // Call appropriate functions/methods to handle check-in
            // Use the createGuestFromUserInput function to get a Room object from user input
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                int roomNum;
                Guest* guest = createGuestFromUserInput(hotel);
                cout << "Enter room number: ";
                cin >> roomNum;
                changeRoomAvailability(roomNum, false);
                // Save the guest to a file
                saveGuestToFile(*guest, "guests.txt");
                cout << endl << "****************************************" << endl;
                cout << "Press (N) to go back ";
                //flush the output buffer of the stream
                fflush(stdin);
                another = _getche();
                cout << endl << "****************************************" << endl;
            }
            break; 
        }
        case 3:
        {  // Perform check-out operation
            // Prompt user for necessary information (room number, etc.)
            // Call appropriate functions/methods to handle check-out
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                int roomNum;
                cout << "Enter room number: ";
                cin >> roomNum;
                changeRoomAvailability(roomNum, true);
                copyBillsToFile();
                cout << endl << "****************************************" << endl;
                cout << "Press (N) to go back ";
                //flush the output buffer of the stream
                fflush(stdin);
                another = _getche();
                cout << endl << "****************************************" << endl;
            }

            break;
        }
        case 4:
        {
            // Use the createBookingFromUserInput function to get a Booking object from user input
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                Booking* booking = createBookingFromUserInput(hotel);
                // Save the booking to a file
                saveBookingToFile(*booking, "bookings.txt");
                int roomNum;
                cout << "Enter room number: ";
                cin >> roomNum;
                changeRoomAvailability(roomNum, false);
                cout << endl << "****************************************" << endl;
                cout << "Make another booking (Y / N) ? ";
                //flush the output buffer of the stream
                fflush(stdin);
                another = _getche();
                cout << endl << "****************************************" << endl;
            }
            break; 
        }
        case 5:
        {
            // Perform cancel booking operation
           // Prompt user for necessary information (booking ID, etc.)
           // Call appropriate functions/methods to handle cancel booking
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                int bookingID;
                cout << "Enter the bookingID to be cancelled: ";
                cin >> bookingID;
                changeBookingStatus(bookingID, "cancelled");
                cout << endl << "****************************************" << endl;
                cout << "Press (N) to go back  ";
                //flush the output buffer of the stream
                fflush(stdin);
                another = _getche();
                cout << endl << "****************************************" << endl;
            }
            break;
        }
        case 6:
        {
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                // Show available rooms
                printAvailableRooms();
                cout << endl << "****************************************" << endl;
                cout << "Press (N) to return ";
                //flush the output buffer of the stream
                fflush(stdin);
                another = _getche();
                cout << endl << "****************************************" << endl;
            }
            break;
        }
        case 7:
        {
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                // Show Booking information
                showBookingInformation("bookings.txt");
                cout << endl << "****************************************" << endl;
                cout << "Show another Booking (Y / N)? ";
                //flush the output buffer of the stream
                fflush(stdin);
                another = _getche();
                cout << endl << "****************************************" << endl;
            }
            break;
        }
        case 8:
        {
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                // Show room information
                showRoomInformation("rooms.txt");
                cout << endl << "****************************************" << endl;
                cout << "Show another Room (Y / N)? ";
                //flush the output buffer of the stream
                fflush(stdin);
                another = _getche();
                cout << endl << "****************************************" << endl;
            }
            break;
        }
        case 9:
        {
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                cout << "Total Revenue of the Hotel: " << getTotalRevenue() << " EUR" << endl;
                cout << endl << "****************************************" << endl;
                cout << "Press (N) to return ";
                //flush the output buffer of the stream
                fflush(stdin);
                another = _getche();
                cout << endl << "****************************************" << endl;
            }
            break;
        }
        case 10:
        {
            cout << "We are sad to see you go :( Goodbye!" << endl;
            exit(0);
            break;
        }
        default:
        {
            cout << "Please Enter a valid choice." << endl; }
        }
    } while (choice != 10);

    hotel.deleteRoomsDynamically();
    hotel.deleteGuestsDynamically();
    hotel.deleteBookingsDynamically();
    hotel.deleteStaffDynamically();
    return 0;
}