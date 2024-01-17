#include <iostream>
#include <cmath>
#define Pi 3.14
using namespace std;

class Pendulum{
    private:
    double lenght;
    double gravity;
    double period;
    double calculatePeriod(){
        period = 2 * Pi * sqrt(lenght/gravity);
        return period;
    }
    public:
    Pendulum(double lenght,double gravity){
        this->lenght=lenght;
        this->gravity=gravity;
    }
    void displayInfo(){
        cout << endl << "The lenght of pendulum is: " << lenght << endl;
        cout << "The gravity value is: " << gravity << endl;
        cout << "The period of pendulum is: " << calculatePeriod() << endl;
    }
};

int main(){
    Pendulum pendulum(1.5,9.8);
    pendulum.displayInfo();
}
