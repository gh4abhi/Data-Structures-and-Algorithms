#include "Vehicle.cpp"

class Car: public Vehicle
{
public:
    int numGears;
    void print()
    {
        cout<<"Number of tyres : "<<numTyres<<endl;
        cout<<"Color : "<<color<<endl;
        cout<<"Number of gears : "<<numGears<<endl;
    }
}