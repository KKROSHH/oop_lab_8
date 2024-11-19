#include <iostream>
#include "Transportation.h"

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

        for(;;)
        {
        cout << "Enter the city of departure: ";
        cin >> Departure;

        cout << "Enter the city of destination: ";
        cin >> Destination;

        cout << "Enter the vehicle: ";
        cin >> Vehicle;

        cout << "Enter the transportation ID: ";
        cin >> Transportation_ID;

        cout << "Enter the transportation time: ";
        cin >> Transportation_Time;

        cout << "Enter the break time for transportation: ";
        cin >> Break_Time;

        cout << "Enter the cargo value: ";
        cin >> Cargo_Value;

        cout << "Enter the cargo type: ";
        cin >> Cargo_Type;

        cout << "Enter the weight of cargo: ";
        cin >> Cargo_Weight;

        //Валідація даних
         if (!cin.fail() &&
            Cargo_Value >= 0 &&
            Cargo_Weight > 0 &&
            Transportation_ID > 0 &&
            Transportation_Time > 0 &&
            Break_Time > 0) 
        {
            cout << "New transportation created successfully!" << endl;
            break;
        } 
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