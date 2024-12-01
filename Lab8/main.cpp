#include <iostream>
#include "Passanger_T.h"
#include"Cargo_T.h"

using namespace std;



int main(int argc, char const *argv[])
{
    Passanger_Transportation Railway;
    Cargo_Transportation Delivery;
    
    Railway.Pass_Create();
    Railway.Pass_Print();

    cout << "\n" << endl;

    Delivery.Cargo_Create();
    cout << "\n" << endl;
    Delivery.Cargo_Print();
}
