#include <iostream>
#include <vector>

using namespace std;

struct sequence{
    int inversions;
    vector<int> numbers;
};

sequence Merge(sequence S, int start, int mid, int end){

    S.inversions = 0;
    S.inversions += Merge(sequence S, start, (start+mid)/2, mid);
    S.inversions += Merge(sequence S, mid, (mid+end)/2, end);
    int left = mid - start;
    int right = end - mid + 1;

    vector<int> sorted(end-start+1);
    int i = start;
    int j = mid;
    int count = 0;
    int times = 0;
    while( times < end-start+1 ){
        if (S.numbers[i] <= S.numbers[j]){
            sorted.push_back(S.numbers[i]);
            i++;
        }
        else{
            sorted.push_back(S.numbers[j]);
            j++;
            count += mid-i;
        }
        times++;
    }


    return S;
}


int main(){

    int n;
    cin >> n;
    sequence S;
    S.inversions = 0;
    for (int i=0; i<n; i++){
        int temp;
        cin >> temp;
        S.numbers.push_back(temp);
    }

    Merge(S, 0, n/2, n-1);

    return 0;
}