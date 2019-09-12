#include <iostream>

using namespace std;

int FibonacciNum(int n){
    int num;
    int last;

    if (n<=1){
        num = n;
    }
    else{
        last = 0;
        num = 1;
        for (int i=0; i<n-1; i++){
            int temp = num;
            num = num + last;
            last = temp;
        }
    }
    return num;
}

int main(){

    int n;
    cin >> n;
    cout << FibonacciNum(n) << endl;
    return 0;
}
