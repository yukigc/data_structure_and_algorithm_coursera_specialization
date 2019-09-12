#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(const vector<int>& an, int bi){
    
    int down = 0;
    int up = an.size()-1;

    while(up > down){
        int mid = (up + down)/2;
        if (bi == an[mid]){
            return mid;
        }
        else if (bi < an[mid]){
            up = mid;
        }
        else{
            down = mid+1;
        }
    }
    if (an[up] == bi){
        return up;
    }
    else{
        return -1;
    }
}

int main(){

    int n;
    cin >> n;
    vector<int> an(n); // an is sorted
    for (int i=0; i<n; i++){
        cin >> an[i];
    }

    int k;
    cin >> k;
    vector<int> bk(k);
    for (int i=0; i<k; i++){
        cin >> bk[i];
    }

    for (int i=0; i<k; i++){
        cout << BinarySearch(an, bk[i]) << " ";
    }

    return 0;
}
