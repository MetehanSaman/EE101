#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float MOI,Radius,Mass;
    cout << "Please enter the mass of semi-circle as kg: ";
    cin >> Mass;
    while(Mass <= 0){
        cout << "Mass can not be zero or negative. Please enter correct value: ";
        cin >> Mass;
    }
    cout << "Please enter the radius of semi-circle as meters: ";
    cin >> Radius;
    while(Radius <= 0){
        cout << "Radius can not be zero or negative. Please enter correct value: ";
        cin >> Radius;
    }
    MOI = Mass*pow(Radius,2)/2;
    cout << "The moment of inertia of semi-circle is: " << MOI << " kg.m.m" << endl;
}
