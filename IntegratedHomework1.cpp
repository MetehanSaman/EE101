#include <iostream>
#include <cmath>
#define PI 3.14
#define g 9.81

using namespace std;

int main(){
    int velocity, angle;
    double radian, height, flight_time;
    cout << "Please enter the initial velocity: ";
    cin >> velocity;
    cout << "Please enter the initial angle: ";
    cin >> angle;

    radian = angle * (PI/180);
    // H = (V^2 * (sin(θ))^2) / (2 * g)
    height = pow(velocity,2)*pow(sin(radian),2)/(2*g);
    // T = (2 * V * sin(θ)) / g
    flight_time = (2*velocity*sin(radian))/g;

    cout << "Max Height is: " << height << endl;
    cout << "Flight Time is: " << flight_time << endl;
    
    /*
    To see and check if values true:
    cout << sin(angle) << endl;
    cout << sin(radian) << endl;
    cout << velocity << endl;
    */

    //Metehan Saman 2211011032

    return 0;
}