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

vector<int> sortCharInverse(const string& S){
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
        //order[count[S[i]]] = i;
        order[i] = count[S[i]];
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

void bwtMatch(const string& text, vector<string>& patterns){
    //first
    vector<int> suffix_array = BuildSuffixArray(text);
    
    //last
    vector<int> last_array(text.size());
    string last_str = "";
    for (int i=0; i<text.size(); i++){
        last_array[i] = suffix_array[i]-1;
        if (last_array[i] < 0){
            last_array[i] += text.size();
        }
        last_str += text[last_array[i]];
    }

    vector<int> order(text.size());
    order = sortCharInverse(last_str);

    //debug
    // for (int i=0; i<text.size(); i++){
    //     cout << text[suffix_array[i]] << " ";
    // }
    // cout << endl;
    // cout << last_str << endl;
    // for (int i=0; i<text.size(); i++){
    //     cout << last_str[order[i]] << " ";
    // }
    // cout << endl;
    // for (int i=0; i<text.size(); i++){
    //     cout << order[i] << " ";
    // }
    // cout << endl;

    vector<int> result(text.size(),0);
    for (int q=0; q<patterns.size(); q++){
        string p = patterns[q];
        int top = 0;
        int bottom = text.size()-1;
        for (int k=p.size()-1; k>=0; k--){
            for (int i=top; i<text.size(); i++){
                //cout << "for:" << top << endl;
                if (p[k] == text[last_array[i]]){
                    //top = i;
                    break;
                }
                top++;
            }
            for (int i=bottom; i>=0; i--){
                if (p[k] == text[last_array[i]]){
                    //bottom = i;
                    break;
                }
                bottom--;
            }
            //cout << top << endl;
            //cout << bottom << endl;
            if (top > bottom){
                break;
            }
            else{
                top = order[top];
                bottom = order[bottom];
            }
        }
        
        for (int i=top; i<=bottom; i++){
            //cout << suffix_array[i] << " ";
            result[suffix_array[i]] = 1;
        }
    }    

    //output
    for (int i=0; i<result.size(); i++){
        if (result[i]==1){
            cout << i << " ";
        }
    }
}


int main() {
    string text;
    cin >> text;
    text = text + '$';
    int n;
    cin >> n;
    vector<string> patterns(n);
    for (int i=0; i<n; i++){
        cin >> patterns[i];
    }
    bwtMatch(text, patterns);
    cout << endl;
    return 0;
}
