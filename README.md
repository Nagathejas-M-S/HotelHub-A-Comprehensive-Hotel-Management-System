# HotelHub-A-Comprehensive-Hotel-Management-System

## Project Description
HotelHub is a simple yet effective hotel management system built in C++. This console-based application allows hotel staff to manage guest check-ins, check-outs, room reservations, and billing. With a focus on simplicity and efficiency, HotelHub keeps track of guest details, room assignments, and billing information in a file, ensuring data persistence across sessions.

## Features
Guest Management: Add new guests with room reservations.
Room Availability: Automatically checks for room availability before reserving a room.
Billing System: Calculates total billing based on the number of nights stayed by the guest.
Data Persistence: Guest data is saved to a file and loaded upon startup, ensuring no loss of information.
Room Management: Allows for the removal of unreserved rooms to keep the system up-to-date.

## Installation
Clone the Repository:  
git clone https://github.com/Nagathejas-M-S/HotelHub-A-Comprehensive-Hotel-Management-System.git
cd hotelhub
Compile the Code:
g++ -o hotel_management hotel_management.cpp

## Usage
Run the Application:
./hotel_management
Follow the Menu:
1. Add Guest: Enter the guest's name and assign them a room.
2. Display Guests: View all currently checked-in guests and their room numbers.
3. Check Out Guest: Enter the room number to check out a guest and calculate their bill.
4. Remove Unreserved Rooms: Remove guests who have checked out from the system.
5. Exit: Safely close the application.

## Code Structure
Guest Class:
Stores information about the guest, including name, room number, reservation status, and total bill.
Hotel Class:
Manages the list of guests, handles room reservations, check-outs, and billing. Also manages file operations for saving and loading guest data.
Main Function:
Provides the user interface through a simple console menu, allowing users to interact with the hotel management system.
