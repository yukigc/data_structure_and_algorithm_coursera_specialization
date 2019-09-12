#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int maxCompare(int a, int b){
    string a_str = to_string(a);
    string b_str = to_string(b);

    string ab = a_str + b_str;
    string ba = b_str + a_str;

    int a_b = stoi(ab);
    int b_a = stoi(ba);

    if (a_b >= b_a){
        return a;
    }
    return b;
}

int LargestNum(int n, vector<int>& numbers){

    while(!numbers.empty()){
        int maxNum = numbers[0];
        int maxIndex = 0;
        for (int i=1; i<numbers.size(); i++){
            if (maxCompare(numbers[i],maxNum)==numbers[i]){
                maxNum = numbers[i];
                maxIndex = i;
            }
        }
        cout << maxNum;
        numbers.erase(numbers.begin()+maxIndex);
    }
    cout << endl;
    return 0;
}


int main(){

    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i=0; i<n; i++){
        cin >> numbers[i];
    }

    LargestNum(n, numbers);

    return 0;
}