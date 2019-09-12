#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using namespace std;

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.

vector<int> sortChar(const string& S){
    vector<int> order(S.size());
    vector<int> count(128,0);

    for (int i=0; i<S.size(); i++){
        count[S[i]]+=1;
    }

    for(int i=1; i<count.size(); i++){
        count[i] = count[i] + count[i-1];
    }

    for (int i=S.size()-1; i>=0; i--){
        count[S[i]] -=1;
        order[count[S[i]]] = i;
    }

    return order;
}

vector<int> charClass(const string& S, vector<int>& order){
    vector<int> cls(S.size());

    cls[order[0]] = 0;
    for (int i=1; i<S.size(); i++){
        if (S[order[i]] != S[order[i-1]]){
            cls[order[i]] = cls[order[i-1]] +1;
        }
        else{
            cls[order[i]] = cls[order[i-1]];
        }
    }
    return cls;
}

vector<int> sortDoubled(const string& S, int L, vector<int>& order, vector<int>& cls){
    vector<int> count(S.size(),0);
    vector<int> newOrder(S.size());

    for (int i=0; i<S.size(); i++){
        count[cls[i]] = count[cls[i]] + 1;
    }

    for (int i=1; i<S.size(); i++){
        count[i] = count[i] + count[i-1];
    }

    for (int i=S.size()-1; i>=0; i--){
        int start = (order[i] - L + S.size()) % S.size();
        int c = cls[start];
        count[c] = count[c]-1;
        newOrder[count[c]] = start;
    }
    return newOrder;
}

vector<int> updateClass(vector<int>& newOrder, vector<int>& cls, int L){
    vector<int> newClass(newOrder.size());
    newClass[newOrder[0]] = 0;

    for (int i=1; i<newOrder.size(); i++){
        int cur = newOrder[i];
        int prev = newOrder[i-1];
        int mid = (cur + L) % newOrder.size();
        int midPrev = (prev + L) % newOrder.size();
        if (cls[cur] != cls[prev] || cls[mid] != cls[midPrev]){
            newClass[cur] = newClass[prev] + 1;
        }
        else{
            newClass[cur] = newClass[prev];
        }
    }
    return newClass;
}

vector<int> BuildSuffixArray(const string& S){
    vector<int> order = sortChar(S);
    vector<int> cls = charClass(S, order);
    int L=1;

    while (L<S.size()){
        order = sortDoubled(S, L, order, cls);
        cls = updateClass(order, cls, L);
        L = 2*L;
    }
    return order;
}

int main() {
    string text;
    cin >> text;
    vector<int> suffix_array = BuildSuffixArray(text);
    for (int i = 0; i < suffix_array.size(); ++i) {
        cout << suffix_array[i] << ' ';
    }
    cout << endl;
    return 0;
}
