#include <iostream>
#include "Transportation.h"
#include <limits>

using namespace std;

class Cargo_Transportation : protected Transportation
{
    protected:
    int Cargo_Weight;
    int Cargo_Value;
    string Cargo_Type;

    public:
    Cargo_Transportation()
    { //Конструктор за замовчуванням
        Cargo_Weight = 0;
        Cargo_Value = 0;
        Transportation_ID = 0;
        Transportation_Time = 0;
        Break_Time = 0;
        Cargo_Type = "None";
        Vehicle = "None";
        Departure = "None";
        Destination = "None";

    }

    ~Cargo_Transportation()
    {

    }

        // Метод для вводу даних з клавіатури
        void Cargo_Create() {
        for (;;) 
        {

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Enter the city of departure: " << endl;
        getline(cin, Departure);

        if (Departure.empty()) {
            cout << "Name of city can't be empty, try again" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the city of destination: " << endl;
        getline(cin, Destination);

        if (Destination.empty()) {
            cout << "Name of city can't be empty, try again" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the vehicle: " << endl;
        getline(cin, Vehicle);

        if (Vehicle.empty()) {
            cout << "Name of vehicle can't be empty, try again" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the transportation ID: " << endl;
        cin >> Transportation_ID;

        if (cin.fail() || Transportation_ID <= 0) {
            cout << "Transportation ID must be a positive integer. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the transportation time in minutes: " << endl;
        cin >> Transportation_Time;

        if (cin.fail() || Transportation_Time <= 0) {
            cout << "Transportation time must be a positive integer. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the break time for transportation in minutes: " << endl;
        cin >> Break_Time;

        if (cin.fail() || Break_Time <= 0) {
            cout << "Break time must be a positive integer. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the cargo value: " << endl;
        cin >> Cargo_Value;

        if (cin.fail() || Cargo_Value < 0) {
            cout << "Cargo value must be a non-negative integer. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer before next line input
        cout << "Enter the cargo type: " << endl;
        getline(cin, Cargo_Type);

        if (Cargo_Type.empty()) {
            cout << "Cargo type can't be empty, try again" << endl;
            continue;
        }

        cout << "Enter the weight of cargo: " << endl;
        cin >> Cargo_Weight;

        if (cin.fail() || Cargo_Weight <= 0) {
            cout << "Cargo weight must be a positive integer. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "New transportation created successfully!" << endl;
        break;
    }
}


        // Метод для виведення інформації про перевезення
    void Cargo_Print() {
        cout << "Transportation Information: " << endl;
        cout << "Departure City: " << Departure << endl;
        cout << "Destination City: " << Destination << endl;
        cout << "Vehicle: " << Vehicle << endl;
        cout << "Transportation ID: " << Transportation_ID << endl;
        cout << "Transportation time: " << Transportation_Time << " minutes." << endl;
        cout << "Break time: " << Break_Time << " minutes." << endl;
        cout << "Time Remained: " << Remain_Time() << " minutes." << endl;
        cout << "Cargo type: " << Cargo_Type << endl;
        cout << "Cargo value: " << Cargo_Value << " hryvnyas" << endl;
        cout << "Cargo weight: " << Cargo_Weight << " kilograms" << endl;
    }
};