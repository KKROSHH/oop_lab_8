#include <iostream>
#include <limits>
#include "Transportation.h"

using namespace std;

class Passanger_Transportation : protected Transportation {
protected:
    int Seats_Number;
    int Tickets_All;
    int Tickets_Sold;


public:
    // Конструктор за замовчуванням
    Passanger_Transportation(){
        Seats_Number = 0;
        Tickets_All = 0;
        Tickets_Sold = 0;
        Departure = "None";
        Destination = "None";
        Vehicle = "None";
        Transportation_ID = 0;
        Transportation_Time = 0;
        Break_Time = 0;

    }

    ~Passanger_Transportation()
    {

    }


    // Метод для обчислення доступних квитків
    int Calculate_Tickets_Available() 
    {
        return Tickets_All - Tickets_Sold;
    }

    // Метод для вводу даних з клавіатури
   void Pass_Create() {
    for (;;) {

        cout << "Enter the city of departure: " << endl;
        getline(cin, Departure);

        if (Departure.empty())
        {
            cout << "Name of city can't be enpty, try again" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        cout << "Enter the city of destination: " << endl;
        getline(cin, Destination);

        if (Destination.empty())
        {
            cout << "Name of city can't be enpty, try again" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the vehicle: " << endl;
        getline(cin, Vehicle);

        if (Vehicle.empty())
        {
            cout << "Name of vehicle can't be enpty, try again" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the transportation ID: " << endl;
        cin >> Transportation_ID;

        if (cin.fail() || Transportation_ID <= 0)
        {
            cout << "Transportation ID must be a positive integer. Please try again." << endl;
            continue;
        }

        cout << "Enter the transportation time in minutes: " << endl;
        cin >> Transportation_Time;
        
        if (cin.fail() || Transportation_Time <= 0)
        {
            cout << "Transportation time must be a positive integer. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the break time for transportation in minutes: " << endl;
        cin >> Break_Time;

        if (cin.fail() || Break_Time <= 0)
        {
            cout << "Break time must be a positive integer. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the amount of seats: " << endl;
        cin >> Seats_Number;

        if (cin.fail() || Seats_Number <= 0)
        {
            cout << "Amount of seats must be a positive integer. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the amount of tickets: " << endl;
        cin >> Tickets_All;

        if (cin.fail() || Tickets_All <= 0)
        {
            cout << "Amount of tickets must be a positive integer. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter the amount of sold tickets: " << endl;
        cin >> Tickets_Sold;

        if (cin.fail() || Tickets_Sold < 0)
        {
            cout << "Amount of sold tickets must be a positive integer or zero. Please try again." << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

          cout << "New transportation created successfully!" << endl;
          break;
        
    }
}


    // Метод для виведення інформації про перевезення
    void Pass_Print() {
        cout << "Transportation Information: " << endl;
        cout << "Departure City: " << Departure << endl;
        cout << "Destination City: " << Destination << endl;
        cout << "Vehicle: " << Vehicle << endl;
        cout << "Transportation ID: " << Transportation_ID << endl;
        cout << "Transportation time: " << Transportation_Time << " minutes." << endl;
        cout << "Break time: " << Break_Time << " minutes." << endl;
        cout << "Time Remained: " << Remain_Time() << " minutes." << endl;
        cout << "Seats Number: " << Seats_Number << endl;
        cout << "Tickets Available: " << Calculate_Tickets_Available() << endl;
        cout << "Tickets Sold: " << Tickets_Sold << endl;
    }
};
