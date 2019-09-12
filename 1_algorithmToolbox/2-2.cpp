#include <iostream>

using namespace std;

int FibonacciNumDigit(int n){
    int num = 1;
    int last = 0;

    if (n<=1){
        num = n;
    }
    else{
        int temp;
        for (int i=0; i<n-1; i++){
            temp = num;
            num = num + last;
            num = num%10;
            last = temp;
        }
    }
    return num;
}

int main(){

    int n;
    cin >> n;
    cout << FibonacciNumDigit(n) << endl;

    return 0;
}
