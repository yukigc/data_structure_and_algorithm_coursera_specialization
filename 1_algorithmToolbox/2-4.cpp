#include <iostream>

using namespace std;

int GCD(int a, int b){

    int remain;
    if (a==0){
        return b;
    }
    else if (b==0){
        return a;
    }
    else if (a>=b){
        remain = a%b;
        return GCD(remain, b);
    }
    else{
        remain = b%a;
        return GCD(remain, a);
    }
}


int main(){

    int a;
    int b;
    cin >> a;
    cin >> b;

    long long product;
    product = ((long long)a)*b/GCD(a,b);
    cout << product << endl;

    return 0;
}