#include <iostream>
#include <vector>

using namespace std;

// for 10, 60 is a period of the last digit of Fibonacci number
int FibonacciNumSum(long long m, long long n){
    
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

    int result_m, result_n;

    if (m==0){
        result_m = 0;
    }
    else{
        int m_index = (m-1)%60;
        result_m = period[m_index];
    }

    if (n<=1){
        result_n = n;
    }
    else{
        int n_index = n%60;
        result_n = period[n_index];
    }

    int partial = result_n - result_m;
    if (partial < 0){
        partial += 10;
    }
    return partial;
}

int main(){

    long long m;
    long long n;
    cin >> m;
    cin >> n;
    cout << FibonacciNumSum(m, n) << endl;

    return 0;
}