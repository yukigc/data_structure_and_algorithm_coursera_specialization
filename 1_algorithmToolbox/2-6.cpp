#include <iostream>
#include <vector>

using namespace std;

// for 10, 60 is a period of the last digit of Fibonacci number
int FibonacciNumSum(long long n){
    if (n<=1){
        return n;
    }

    vector<int> period;
    period.push_back(0);
    period.push_back(1);
    int num = 1;
    int last = 0;
    int sum = 1;
    for (int i=0; i<58; i++){
        int temp = num;
        num = (num + last)%10;
        last = temp;
        sum  = (sum + num)%10;
        period.push_back(sum);
    }

    int n_index = n%60;

    return period[n_index];
}

int main(){

    long long n;
    cin >> n;
    cout << FibonacciNumSum(n) << endl;

    return 0;
}