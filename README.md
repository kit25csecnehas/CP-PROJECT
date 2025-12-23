# CP-PROJECT
📌 Project Overview

The Vehicle Rental System is a console-based mini project developed using C programming.
It demonstrates file handling, structures, and menu-driven programming to manage vehicles for rent.
The system allows users to view available vehicles, add new vehicles temporarily, save them to a file, rent vehicles, and return rented vehicles.

This project is suitable for college mini-projects, lab exams, and viva presentations.

🎯 Objectives

To understand file handling in C

To use structures for real-world data modeling

To implement a menu-driven application

To manage vehicle availability dynamically

⚙️ Features

📄 Stores vehicle details in a file (vehicle.txt)

➕ Add new vehicles temporarily (output only)

💾 Save vehicles to file only when confirmed

📋 Display vehicles directly from file

🚘 Rent a vehicle (updates availability)

🔁 Return a rented vehicle

❌ Prevents accidental file modification

✅ Simple and user-friendly console interface

🧱 Data Structure Used
struct Vehicle {
    int id;
    char name[20];
    char number[20];
    float rentHour;
    float rentDay;
    int available;
};

📁 File Format (vehicle.txt)
VehicleID  Name  Number  RentPerHour  RentPerDay  Availability


Example:

1 LAMBO TN10AB1234 300 2500 1
2 BMW   TN10AB5678 400 3000 1


1 → Available

0 → Rented

🖥️ Menu Options

Add Vehicle (Temporary – Output Only)

Display Vehicles

Save Last Added Vehicle

Rent Vehicle

Return Vehicle

Exit

🛠️ Technologies Used

Language: C

Concepts:

Structures

File Handling

Functions

Conditional Statements

Loops

Compiler: GCC / OnlineGDB

▶️ How to Run

Clone or download the repository

Create a file named vehicle.txt with sample vehicle data

Compile the program:

gcc vehicle_rental.c -o vehicle_rental


Run:

./vehicle_rental

🎓 Educational Value

This project helps students understand:

Real-time application of C programming

Persistent storage using files

Logical separation between temporary and permanent data

Mini-project development workflow

📌 Future Enhancements

Billing calculation

Customer details

Admin login system

Vehicle deletion option

Graphical interface (GUI)

🧑‍🎓 Author
Neha s
C Programming Mini Project

📜 License

This project is created for educational purposes only.
