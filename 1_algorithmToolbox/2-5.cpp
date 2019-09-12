#include <iostream>
#include <vector>

using namespace std;

int FibonacciNum(long long n, int m){
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
            num = num%m;
            last = temp;
        }
    }
    return num;
}


int FibonacciNumAgain(long long n, int m){
    int flag_1 = 0;
    int flag_2 = 1;

    if (n==1){
        return 1;
    }
    else{
        vector<int> period;
        period.push_back(flag_1);
        period.push_back(flag_2);
        int i=2;
        do{
            flag_1 = flag_2;
            flag_2 = FibonacciNum(i,m);
            period.push_back(flag_2);
            i++;
        }while( !(flag_1 == 0 && flag_2 == 1));

    int index = n%(period.size()-2);

    int sum = 0;
    for (int i=0; i<period.size()-2; i++){
        sum += period[i];
    }
    cout << sum << endl;

    return period[index];
    }
}


int main(){

    long long n;
    int m; 
    cin >> n;
    cin >> m;
    cout << FibonacciNumAgain(n, m) << endl;

    return 0;
}