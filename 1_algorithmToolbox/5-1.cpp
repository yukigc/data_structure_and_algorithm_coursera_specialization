#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b){
    if (a<=b){
        return a;
    }
    return b;
}

int MoneyChange(int n){
    vector<int> Denominations(3);
    Denominations[0] = 1; 
    Denominations[1] = 3; 
    Denominations[2] = 4;
    vector<int> L(n+1,1000);
    L[0] = 0;
    L[1] = 1;
    for (int i=2; i<=n; i++){
        for (int j=0; j<3; j++){
            int last = i-Denominations[j];
            if (last>=0){
                L[i] = min(L[i],L[last]+1);
            }
        }
    }
    return L[n];
}

int main(){

    int money;
    cin >> money;

    cout << MoneyChange(money) << endl;
    return 0;
}