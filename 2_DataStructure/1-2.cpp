#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
public:
    int key;
    int parent;
    vector<int> children;

    Node(int k, int p) {
        this->key = k;
        this->parent = p;
        vector<int> children;
        this->children = children;
    }

};

int getHight(vector<Node>& trees) {
    // read the tree first
    int n = trees.size();
    int root;
    for (int i=0; i<n; i++){
        if (trees[i].parent == -1){
            root = i;
        }
        else{
            trees[trees[i].parent].children.push_back(i);
        }
    }

    queue <Node> search;
    int height = 0;
    int nextCnt = 1;
    int Cnt = 0;
    n = n-1;
    Node start = Node(-1,-1);

    search.push(trees[root]);

    while(n > 0 || (n==0 && search.empty()!=1)){
        start = search.front();
        search.pop();
        Cnt++;
        //cout << n << endl;
        //cout << start.key << endl;

        vector<int> chd = start.children;
        for (int i=0; i<chd.size(); i++){
            search.push(trees[chd[i]]);
            n = n-1;
        }


        /* 
        for (int i=trees.size()-1; i>=0; i--){
            if (trees[i].parent == start.key){
                search.push(trees[i]);
                trees.erase(trees.begin()+i);
            }
        }*/

        if (Cnt == nextCnt){
            Cnt = 0;
            nextCnt = search.size();
            height++;
        }
    }
    //cout << endl;
    return height;
}

int main(){

    int n;
    cin >> n;

    vector<Node> trees;
    for (int i=0; i<n; i++){
        int p;
        cin >> p;
        Node N = Node(i, p);
        trees.push_back(N);
    }

    

    cout << getHight(trees) << endl;

    return 0;
}
