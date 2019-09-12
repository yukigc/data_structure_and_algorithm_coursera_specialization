#include <iostream>
#include <vector>

using namespace std;

int MaxPrize(int n){

    vector<int> prize;
    int i = 1;
    int sum = 0;
    do{
        prize.push_back(i-1);
        sum += i;
        i++;
    }while(sum<=n);

    prize[prize.size()-1] = prize[prize.size()-1]+ (n - sum + i-1);

    cout << prize.size()-1 << endl;
    for (int i=1; i<prize.size(); i++){
        cout << prize[i] << " ";
    }
    cout << endl;

    return 0;
}

int main(){

    int n;
    cin >> n;
    MaxPrize(n);
    return 0;
}