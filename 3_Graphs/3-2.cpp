#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
    //write your code here
    int s = 0;
    vector<int> color(adj.size(), -1);
    color[s] = 0;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty()){
        int u;
        u = Q.front();
        Q.pop();
        for (int i=0; i<adj[u].size(); i++){
            if (color[adj[u][i]] == -1){
                Q.push(adj[u][i]);
                if (color[u] == 0){
                    color[adj[u][i]] = 1;
                }
                else if (color[u] == 1){
                    color[adj[u][i]] = 0;
                }
            }
            else if(color[adj[u][i]] == color[u]){
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    std::cout << bipartite(adj) << std::endl;
}