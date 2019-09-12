#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Majority(int n, vector<int>& an){

    if (n==1){
        return 1;
    }
    else{
        // firstly sort the array
        sort(begin(an), end(an));

        int mid = an[n/2];
        int count = 0;
        for (int i=0; i<n; i++){
            if (an[i] == mid){
                count++;
            }
        }

        if (count>n/2){
            return 1;
        }
        else{
            return 0;
        }
        
    }
}

int main(){

    int n;
    cin >> n;
    vector<int> an(n);
    for (int i=0; i<n; i++){
        cin >> an[i];
    }

    cout << Majority(n, an);

    return 0;
}
