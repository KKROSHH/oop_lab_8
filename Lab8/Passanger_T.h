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
        cout << "Enter the city of departure: ";
        getline(cin, Departure);

        cout << "Enter the city of destination: ";
        getline(cin, Destination);

        cout << "Enter the vehicle: ";
        getline(cin, Vehicle);

        cout << "Enter the transportation ID: ";
        cin >> Transportation_ID;

        cout << "Enter the transportation time in minutes: ";
        cin >> Transportation_Time;

        cout << "Enter the break time for transportation in minutes: ";
        cin >> Break_Time;

        cout << "Enter the amount of seats: ";
        cin >> Seats_Number;

        cout << "Enter the amount of tickets: ";
        cin >> Tickets_All;

        cout << "Enter the amount of sold tickets: ";
        cin >> Tickets_Sold;

        // Валідація даних
        if (!cin.fail() &&
            Tickets_Sold >= 0 &&
            Seats_Number > 0 &&
            Tickets_All > 0 &&
            Transportation_ID > 0 &&
            Transportation_Time > 0 &&
            Break_Time > 0) 
        {
            cout << "New transportation created successfully!" << endl;
            break;
        } 
        else 
        {
            cout << "One of the fields has an incorrect value! Please try again." << endl;
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
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
