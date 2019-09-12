#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &dfs_num, int x, int &cnt) {
    //write your code here
    used[x] = 1;
    for (int i=0; i<adj[x].size(); i++){
        if (!used[adj[x][i]]){
            dfs(adj, used, dfs_num, adj[x][i], cnt);
        }
    }
    //used[x] = 1;
    dfs_num[cnt] = x;
    cnt++;
}    

void explore(vector<vector<int> > &adj, vector<int> &visited, int x){
    visited[x] = 1;
    for (int i=0; i<adj[x].size(); i++){
        if (!visited[adj[x][i]]){
            explore(adj, visited, adj[x][i]);
        }
    }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
    int result = 0;
    //write your code here

    // reverse graph
    vector<vector<int> > adj_reverse(adj.size(), vector<int>());
    for (int i=0; i<adj.size(); i++){
        for (int j=0; j<adj[i].size(); j++){
            adj_reverse[adj[i][j]].push_back(i);
        }
    }

    int cnt = 0;
    vector<int> dfs_num(adj.size(), 0);
    vector<int> used(adj.size(), 0);
    for(int i=0; i<adj_reverse.size(); i++){
        if (used[i] == 0){
            dfs(adj_reverse, used, dfs_num, i, cnt);
        }
    }
    
    vector<int> visited(adj.size(), 0);
    for (int i=adj.size()-1; i>=0; i--){
        if (visited[dfs_num[i]] == 0){
            result++;
            explore(adj, visited, dfs_num[i]);
        }
    }
    return result;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
      int x, y;
      std::cin >> x >> y;
      adj[x - 1].push_back(y - 1);
    }
    cout << number_of_strongly_connected_components(adj) << endl;
}
