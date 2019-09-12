#include <iostream>
#include <vector>

using namespace std;

double maxValue(int W, const vector<int>& values, const vector<int>& weights){
    double maxValue = 0;
    int n = values.size();
    
    //sort
    vector<int> sortIndex(n);
    for (int i=0; i<n; i++){
        sortIndex[i] = i;
        for (int j=0; j<i; j++){
            if ( ((double)(values[i]))/weights[i] > ((double)(values[sortIndex[j]]))/weights[sortIndex[j]]){
                // update index
                for (int k=i; k>j; k--){
                    sortIndex[k] = sortIndex[k-1];
                }
                sortIndex[j] = i;
                break;
            }
        }
    }    

    // greedy
    int i=0;
    while (W>0 && i<n){
        int index = sortIndex[i];
        if (weights[index]<=W){
            W -= weights[index];
            maxValue += values[index];
            i++;
        }
        else{
            maxValue += ((double)(values[index]))*W/weights[index];
            W = 0;
        }
    }
    return maxValue;
}


int main(){

    int n; //items number
    int W; //capacity
    cin >> n;
    cin >> W;

    vector<int> values(n);
    vector<int> weights(n);
    for (int i=0; i<n; i++){
        cin >> values[i];
        cin >> weights[i];
    }
    cout.precision(4);
    cout << fixed << maxValue(W, values, weights) << endl;

    return 0;
}