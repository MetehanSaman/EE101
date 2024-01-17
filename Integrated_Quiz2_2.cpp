#include <iostream>
using namespace std;

int main(){
    int number;
    cout << "Give the number: ";
    cin >> number;
    int array[number][number];
    for(int i = 0;i < number;i++){
        for(int j = 0;j < number;j++){
            array[j][i] = i*j;
        }
    }
    cout << "Matrix Pattern:" << endl;
    for(int i = 0;i < number;i++){
        for(int j = 0;j < number;j++){
            cout << array[i][j] << " ";
        }
    cout << endl;
    }
}
