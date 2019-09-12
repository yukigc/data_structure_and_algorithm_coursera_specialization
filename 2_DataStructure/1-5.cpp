#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int SlideWindow(int n, const vector<int>& numbers, int m){

    deque<int> useful(m);

    for (int i=0; i<m; i++){
        while ( (!useful.empty()) && numbers[i] >= numbers[useful.back()]){
            useful.pop_back();
        }
        useful.push_back(i);
    }
    cout << numbers[useful.front()] << " ";

    for (int i=m; i<n; i++){
        if (useful.front() <= i-m){
            useful.pop_front();
        }

        while ( (!useful.empty()) && numbers[i] >= numbers[useful.back()]){
            useful.pop_back();
        }
        useful.push_back(i);
        cout << numbers[useful.front()] << " ";
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
    int m;
    cin >> m;

    SlideWindow(n, numbers, m);

    return 0;
}