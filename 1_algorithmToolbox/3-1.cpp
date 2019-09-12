#include <iostream>

using namespace std;

//Money change

int MoneyChange(int amount){

    int minNum=0;
    if (amount>0 && amount/10 != 0){
        minNum += amount/10;
        amount = amount%10;
    }
    if (amount>0 && amount/5 != 0){
        minNum += amount/5;
        amount = amount%5;
    }
    if (amount>0){
        minNum += amount;
    }

    return minNum;
}

int main(){

    int amount;
    cin >> amount;
    cout << MoneyChange(amount) << endl;
    return 0;
}
