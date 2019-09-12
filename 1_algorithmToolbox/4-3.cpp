#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> partition3(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
        j++;
        swap(a[i], a[j]);
        }
    }

    swap(a[l], a[j]);
    
    int count = 0;
    for (int i=l; i<j-count; i++){
        if (a[i] == x){
            for (int k=i; k<j-count; k++){
                a[k] = a[k+1];
            }
            count++;
        }
    }


    vector<int> result;
    result.push_back(j-count);
    result.push_back(j);
    return result;
}


void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    vector<int> result = partition3(a, l, r);

    randomized_quick_sort(a, l, result[0] - 1);
    randomized_quick_sort(a, result[1] + 1, r);
}


int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }

    return 0;
}