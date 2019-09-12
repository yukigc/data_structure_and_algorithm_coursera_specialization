#include <iostream>
#include <vector>

using namespace std;

int FibSquared(long long n){

    if (n<=1){
        return n;
    }
    
    vector<int> period;
    period.push_back(0);
    period.push_back(1);
    int num = 1;
    int last = 0;
    for (int i=0; i<58; i++){
        int temp = num;
        num = (num + last)%10;
        last = temp;
        period.push_back(num);
    }

    return period[n%60]*(period[n%60]+period[(n-1)%60])%10;
}

int main(){

    long long n;
    cin >> n;
    cout << FibSquared(n) << endl;

    return 0;
}