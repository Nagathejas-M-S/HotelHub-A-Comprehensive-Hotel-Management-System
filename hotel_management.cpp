#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Guest
{
public:
    std::string name;
    int roomNumber;
    bool reserved;
    double totalBill;

    // Default constructor
    Guest() : name(""), roomNumber(0), reserved(false), totalBill(0.0) {}

    // Parameterized constructor
    Guest(const std::string &guestName, int roomNum) : name(guestName), roomNumber(roomNum), reserved(true), totalBill(0.0) {}
};

class Hotel
{
private:
    std::vector<Guest> guests;
    std::string filename;

public:
    const double roomRate = 5000.0;
    //constructor
    Hotel(const std::string &fileName) : filename(fileName)
    {
        loadGuestsFromFile();
    }

    void addGuest()
    {
        Guest guest;
        std::cout << "Enter guest name: ";
        std::cin.ignore();
        std::getline(std::cin, guest.name);
        std::cout<<std::endl;

        // Check room availability
        int roomNumber;
        bool roomAvailable;
        do
        {
            roomAvailable = true;
            std::cout << "Enter room number: ";
            std::cin >> roomNumber;
            std::cout<<std::endl;
            for (const Guest &existingGuest : guests)
            {
                if (existingGuest.roomNumber == roomNumber)
                {
                    std::cout << "Room " << roomNumber << " is already occupied. Try another room.\n";
                    std::cout<<std::endl;
                    roomAvailable = false;
                    break;
                }
            }
        } while (!roomAvailable);

        guest.roomNumber = roomNumber;
        guest.reserved = true;
        guest.totalBill = 0.0;

        guests.push_back(guest);
        saveGuestsToFile();
    }

    void displayGuests() const
    {
        if (guests.empty())
        {
            std::cout << "All rooms are empty.\n";
            std::cout<<std::endl;
        }
        else
        {
            std::cout << "Guest List:\n";
            std::cout<<std::endl;
            for (const Guest &guest : guests)
            {
                std::cout << "Name: " << guest.name << ", Room Number: " << guest.roomNumber;
                if (guest.reserved)
                {
                    std::cout << ", Reserved: Yes";
                }
                else
                {
                    std::cout << ", Reserved: No";
                }
                std::cout << "\n";
            }
        }
    }

    void checkOutGuest()
    {
        int roomNumber;
        std::cout << "Enter the room number to check out: ";
        std::cin >> roomNumber;
        std::cout<<std::endl;

        for (auto it = guests.begin(); it != guests.end(); ++it)
        {
            if (it->roomNumber == roomNumber && it->reserved)
            {
                it->reserved = false;

                // Calculate and update the total bill
                int numNights;
                std::cout << "Enter the number of nights stayed: ";
                std::cin >> numNights;
                std::cout<<std::endl;
                it->totalBill = numNights * roomRate;
                std::cout << "Checked out successfully. Total Bill: Rs." << it->totalBill << "\n";

                // Save the updated guest list to the file
                saveGuestsToFile();
                return;
            }
        }

        std::cout << "Room " << roomNumber << " is not reserved or doesn't exist.\n";
    }

    void removeUnreservedRooms()
    {
        guests.erase(std::remove_if(guests.begin(), guests.end(),
                                    [](const Guest &guest)
                                    { return !guest.reserved; }),
                     guests.end());

        saveGuestsToFile();
    }

private:
    void saveGuestsToFile() const
    {
        std::ofstream outFile(filename);
        //write to file
        if (!outFile)
        {
            std::cerr << "Error opening file for writing." << std::endl;
            return;
        }

        for (const Guest &guest : guests)
        {
            outFile << guest.name << " " << guest.roomNumber << "\n";
        }
        outFile.close();
    }

    void loadGuestsFromFile()
    {
        std::ifstream inFile(filename);
        //read from file
        if (!inFile)
        {
            std::cerr << "Error opening file for reading." << std::endl;
            return;
        }

        Guest guest;
        while (inFile >> guest.name >> guest.roomNumber)
        {
            guest.reserved = true; // Assuming all loaded guests are currently reserved
            guest.totalBill = 0.0; // Initialize totalBill to 0
            guests.push_back(guest);
        }
        inFile.close();
    }
};

int main()
{
    Hotel hotel("guests.txt");

    int choice;
    while (true)
    {
        std::cout << "Hotel Management System\n";
        std::cout << "1. Add Guest\n";
        std::cout << "2. Display Guests\n";
        std::cout << "3. Check Out Guest\n";
        std::cout << "4. Remove Unreserved Rooms\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout<<std::endl;
        switch (choice)
        {
        case 1:
            hotel.addGuest();
            break;
        case 2:
            hotel.displayGuests();
            break;
        case 3:
            hotel.checkOutGuest();
            break;
        case 4:
            hotel.removeUnreservedRooms();
            break;
        case 5:
            std::cout << "Thank you, visit again!";
            std::cout<<std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
