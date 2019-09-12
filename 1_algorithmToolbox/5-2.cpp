#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b){
    if (a<=b){
        return a;
    }
    return b;
}

int PrimCal(int n){
    vector<int> L(n+1,1e6);
    vector<int> last(n+1);
    L[0] = 0;
    L[1] = 0;
    for (int i=2; i<=n; i++){
        L[i] = 1 + L[i-1];
        last[i] = i-1;
        if (i%2==0){
            if (L[i] > 1+L[i/2]){
                L[i] = 1+L[i/2];
                last[i] = i/2;
            }
        }
        if (i%3==0){
            if (L[i] > 1+L[i/3]){
                L[i] = 1+L[i/3];
                last[i] = i/3;
            }
        }
    }
    cout << L[n] << endl;
    
    vector<int> trace;
    int p = n;
    while(p>1){
        trace.push_back(p);
        //cout << p << " ";
        p = last[p];
    }
    trace.push_back(1);

    for (int i=trace.size()-1; i>=0; i--){
        cout << trace[i] << " ";
    }
    cout << endl;
    return 0;
}

int main(){
    
    int n;
    cin >> n;
    PrimCal(n);
    return 0;
}