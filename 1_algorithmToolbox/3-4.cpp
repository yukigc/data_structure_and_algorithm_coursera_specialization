#include <iostream>
#include <vector>
#include <functional> 

using namespace std;

int sortA(vector<int>& a){
    int n = a.size();
    vector<int> sortInc(n);
    for (int i=0; i<n; i++){
        sortInc[i] = a[i];
        for (int j=0; j<i; j++){
            if ( a[i] < sortInc[j] ){
                // update index
                for (int k=i; k>j; k--){
                    sortInc[k] = sortInc[k-1];
                }
                sortInc[j] = a[i];
                break;
            }
        }
    }  

    for (int i=0; i<n; i++){
        a[i] = sortInc[i];
    }  
    return 0;
}


long long MaxValue(int n, vector<int>& a, vector<int>& b){
    long long maxV = 0;
    if (n==1){
        maxV = a[0]*b[0];
    }
    else{
        sortA(a);
        sortA(b);

        for (int i=0; i<n; i++){
            maxV += (long long)a[i]*b[i];
        }
    }
    return maxV;
}

int main(){

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (int i=0; i<n; i++){
        cin >> b[i];
    }

    cout << MaxValue(n,a,b) << endl;

    return 0;
}