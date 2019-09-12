#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tree {
    
    int n;
    vector<int> keys;
    vector<int> lefts;
    vector<int> rights;

public:

    void read(){
        cin >> n;
        keys.resize(n);
        lefts.resize(n);
        rights.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> keys[i] >> lefts[i] >> rights[i];
        }
    }

    void in_order_recursive(int i){
        if (lefts[i] != -1){
            in_order_recursive(lefts[i]);
        }
        cout << keys[i] << " ";
        if (rights[i] != -1){
            in_order_recursive(rights[i]);
        }
    }


    void pre_order_recursive(int i){
        cout << keys[i] << " ";
        if (lefts[i] != -1){
            pre_order_recursive(lefts[i]);
        }
        if (rights[i] != -1){
            pre_order_recursive(rights[i]);
        }
    }

    void post_order_recursive(int i){
        if (lefts[i] != -1){
            post_order_recursive(lefts[i]);
        }
        if (rights[i] != -1){
            post_order_recursive(rights[i]);
        }
        cout << keys[i] << " ";
    }



};

int main(){

    Tree t;
    t.read();
    t.in_order_recursive(0);
    cout << endl;
    t.pre_order_recursive(0);
    cout << endl;
    t.post_order_recursive(0);
    cout << endl;


    return 0;
}