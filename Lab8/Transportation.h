#include <iostream>
#pragma once


using namespace std;


class Transportation {
    protected:

        std::string Vehicle; // Тип транспорту для перевезення
        int Transportation_ID; //Номер рейсу
        int Transportation_Time; // Час транспортування (в хвилинах)
        int Break_Time; // Час загрузки, вигрузки (в хвилинах)
        std::string Departure; // Місто відправки
        std::string Destination; // Місто призначення

    int Remain_Time()
    {
        int r_time = Transportation_Time - Break_Time;
        return r_time;
    }

    public:
    Transportation() { //Конструктор за замовчуванням

        Vehicle = "None";
        Transportation_Time = 0;
        Break_Time = 0;
        Transportation_ID = 0;
    }
    
    



};
