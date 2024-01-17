#include <iostream>

using namespace std;

int main(){
    char degree = 176;//I tried to implement degree symbol but I am not sure if it is working
    double Fahrenheit,Celsius;
    int process;
    bool done = false;
    cout << "Welcome to temperature converter!" << endl;
    do{
        cout << "1-Convert from Celsius to Fahrenheit" << endl;
        cout << "2-Convert from Fahrenheit to Celsius" << endl;
        cout << "Please enter the number of option which you want to use: ";
        cin >> process;
        switch (process)
        {
        case 1:
            cout << "Please enter the temperature in Celsius: ";
            cin >> Celsius;
            Fahrenheit = (Celsius * 9/5) + 32;
            cout << "Equivalent temperature in Fahrenheit: " << Fahrenheit << degree << "F" << endl;
            done = true;
            break;
        case 2:
            cout << "Please enter the temperature in Fahrenheit: ";
            cin >> Fahrenheit;
            Celsius =  (Fahrenheit - 32) * 5/9;
            cout << "Equivalent temperature in Celsius: " << Celsius << degree << "C"<<endl;
            done = true;
            break;
        
        default:
            cout << "You entered wrong number, please enter 1 or 2!" << endl;
            break;
        }
    }while(done != true);}