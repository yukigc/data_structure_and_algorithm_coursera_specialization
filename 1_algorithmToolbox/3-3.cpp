#include <iostream>
#include <vector>

using namespace std;

int carFuel(int d, int m, int n, const vector<int>& stops){
    int minFuel = 0;
    int current=0;

    while ( (stops[current] + m) < d ){
        for (int i=(current+1); i<=stops.size(); i++){
            if (stops[i] > (stops[current] + m)){
                if (i == (current+1)){
                    return -1;
                }
                else{
                    current = i-1;
                    minFuel++;
                    break;
                }
            }
        }
    }
    return minFuel;
}


int main(){

    int d;
    int m;
    int n;
    cin >> d;
    cin >> m;
    cin >> n;

    vector<int> stops(n+2);
    stops[0] = 0;
    for (int i=1; i<=n; i++){
        cin >> stops[i];
    }
    stops[n+1] = d;

    cout << carFuel(d, m, n, stops) << endl;
    return 0;
}