#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Define a structure for room
struct Room
{
    int roomNumber;
    string roomType;
    bool isBooked;
    Room *next;

    Room(int number, string type, bool booked = false)
    {
        roomNumber = number;
        roomType = type;
        isBooked = booked;
        next = nullptr;
    }
};

class HotelManagement
{
private:
    Room *head;

public:
    HotelManagement()
    {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int roomNumber, string roomType)
    {
        if (roomNumber <= 0 || roomType.empty())
        {
            cout << "Invalid room details." << endl;
            return;
        }
        Room *newRoom = new Room(roomNumber, roomType);
        newRoom->next = head;
        head = newRoom;
        cout << "Room added at the beginning." << endl;
    }

    // Insert at a specific position
    void insertAtPosition(int position, int roomNumber, string roomType)
    {
        if (position <= 0 || roomNumber <= 0 || roomType.empty())
        {
            cout << "Invalid input." << endl;
            return;
        }
        Room *newRoom = new Room(roomNumber, roomType);
        if (position == 1)
        {
            newRoom->next = head;
            head = newRoom;
            cout << "Room added at position 1." << endl;
            return;
        }
        Room *temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; ++i)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Position out of bounds." << endl;
            delete newRoom;
            return;
        }
        newRoom->next = temp->next;
        temp->next = newRoom;
        cout << "Room added at position " << position << "." << endl;
    }

    // Insert at the end
    void insertAtEnd(int roomNumber, string roomType)
    {
        if (roomNumber <= 0 || roomType.empty())
        {
            cout << "Invalid room details." << endl;
            return;
        }
        Room *newRoom = new Room(roomNumber, roomType);
        if (!head)
        {
            head = newRoom;
            cout << "Room added at the end." << endl;
            return;
        }
        Room *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newRoom;
        cout << "Room added at the end." << endl;
    }

    // Delete from the beginning
    void deleteFromBeginning()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Room *toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Room deleted from the beginning." << endl;
    }

    // Delete a specific node by room number
    void deleteRoom(int roomNumber)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (head->roomNumber == roomNumber)
        {
            Room *toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Room " << roomNumber << " deleted." << endl;
            return;
        }
        Room *temp = head;
        while (temp->next && temp->next->roomNumber != roomNumber)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            Room *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Room " << roomNumber << " deleted." << endl;
        }
        else
        {
            cout << "Room " << roomNumber << " not found." << endl;
        }
    }

    // Delete from the end
    void deleteFromEnd()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
            cout << "Room deleted from the end." << endl;
            return;
        }
        Room *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Room deleted from the end." << endl;
    }

    // Display all rooms
    void displayRooms()
    {
        if (!head)
        {
            cout << "No rooms available." << endl;
            return;
        }
        Room *temp = head;
        cout << "\nRoom Details:\n";
        while (temp)
        {
            cout << "Room Number: " << temp->roomNumber << endl;
            cout << "Room Type: " << temp->roomType << endl;
            cout << "Status: " << (temp->isBooked ? "Booked" : "Available") << endl;
            temp = temp->next;
        }
    }

    // Destructor to clean up memory
    ~HotelManagement()
    {
        Room *temp = head;
        while (temp)
        {
            Room *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
};

// Function to validate integer input
int getValidInteger()
{
    int value;
    while (true)
    {
        cin >> value;
        if (cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer: ";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Function to validate string input
string getValidString()
{
    string value;
    while (true)
    {
        getline(cin, value);
        if (value.empty())
        {
            cout << "Invalid input. Please enter a valid string: ";
        }
        else
        {
            return value;
        }
    }
}

int main()
{
    HotelManagement hotel;
    int choice;

    do
    {
        cout << "\nHotel Management System" << endl;
        cout << "1. Add Room at Beginning" << endl;
        cout << "2. Add Room at Specific Position" << endl;
        cout << "3. Add Room at End" << endl;
        cout << "4. Display Rooms" << endl;
        cout << "5. Delete Room from Beginning" << endl;
        cout << "6. Delete Specific Room" << endl;
        cout << "7. Delete Room from End" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        choice = getValidInteger();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Room Number: ";
            int roomNumber = getValidInteger();
            cout << "Enter Room Type: ";
            string roomType = getValidString();
            hotel.insertAtBeginning(roomNumber, roomType);
            break;
        }
        case 2:
        {
            cout << "Enter Position: ";
            int position = getValidInteger();
            cout << "Enter Room Number: ";
            int roomNumber = getValidInteger();
            cout << "Enter Room Type: ";
            string roomType = getValidString();
            hotel.insertAtPosition(position, roomNumber, roomType);
            break;
        }
        case 3:
        {
            cout << "Enter Room Number: ";
            int roomNumber = getValidInteger();
            cout << "Enter Room Type: ";
            string roomType = getValidString();
            hotel.insertAtEnd(roomNumber, roomType);
            break;
        }
        case 4:
            hotel.displayRooms();
            break;
        case 5:
            hotel.deleteFromBeginning();
            break;
        case 6:
        {
            cout << "Enter Room Number to Delete: ";
            int roomNumber = getValidInteger();
            hotel.deleteRoom(roomNumber);
            break;
        }
        case 7:
            hotel.deleteFromEnd();
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
