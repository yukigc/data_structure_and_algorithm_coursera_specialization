#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Node {
    int key;
    int left;
    int right;

    Node() : key(0), left(-1), right(-1) {}
    Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};


void in_order_recursive(int i, const vector<Node>& tree, vector<int>& result){
    if (tree[i].left != -1){
        in_order_recursive(tree[i].left, tree, result);
    }
    result.push_back(tree[i].key);
    if (tree[i].right != -1){
        in_order_recursive(tree[i].right, tree, result);
    }
}

int main() {
    int nodes;
    cin >> nodes;
    vector<Node> tree;
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }

    if (nodes==0){
        cout << "CORRECT" << endl;
        return 0;
    }
    
    vector<int> result;
    in_order_recursive(0, tree, result);

    int flag = 0;
    for (int i=1; i<result.size(); i++){
        if (result[i] <= result[i-1] ){
            flag = 1;
            break;
        }
    }

    if (flag==0){
        cout << "CORRECT" << endl;
    }
    else{
        cout << "INCORRECT" << endl;
    }


    return 0;
}
