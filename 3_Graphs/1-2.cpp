#include <iostream>
#include <vector>

using namespace std;


void explore(int x, vector<vector<int> > &adj, vector<int> &visited){
    visited[x] = 1;
    for (int i=0; i<adj[x].size(); i++){
        if (visited[adj[x][i]] == 0){
            explore(adj[x][i], adj, visited);
        }
    }
}

int DFS(vector<vector<int> > &adj){
    vector<int> visited;
    for (int i=0; i<adj.size(); i++){
        visited.push_back(0);
    }

    int cnt = 0;
    for (int i=0; i<adj.size(); i++){
        if (visited[i] == 0){
            for (int j=0; j<adj[i].size(); j++){
                if (visited[adj[i][j]] == 0){
                    explore(adj[i][j], adj, visited);
                }
            }
            cnt += 1;
        }
    }

    return cnt;
}


int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    std::cout << DFS(adj) << std::endl;
}