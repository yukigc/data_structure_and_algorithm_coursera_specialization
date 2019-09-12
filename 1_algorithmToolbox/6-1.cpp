#include <iostream>
#include <vector>

using namespace std;

int MaxAmt(int w, int n, const vector<int>& bars){
    vector<vector<int> > result(w+1);
    for (int i = 0; i < result.size(); i++){
        result[i].resize(n+1);
    }
    
    for (int j=1; j<=n; j++){
        for (int i=1; i<=w; i++){
            result[i][j] = result[i][j-1];
            if (i >= bars[j-1]){
                if (result[i][j] < (result[i-bars[j-1]][j-1]+bars[j-1])){
                    result[i][j] = result[i-bars[j-1]][j-1]+bars[j-1];
                }
            }

        }
    }

    return result[w][n];
}

int main(){

    int w;
    int n;
    cin >> w;
    cin >> n;
    vector<int> bars(n);
    for (int i=0; i<n; i++){
        cin >> bars[i];
    }
    cout << MaxAmt(w, n, bars) << endl;
    return 0;
}