#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
    //write your code here

    vector<int> dist(adj.size(), adj.size());
    dist[s] = 0;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty()){
        int u;
        u = Q.front();
        Q.pop();
        for (int i=0; i<adj[u].size(); i++){
            if (dist[adj[u][i]] == adj.size()){
                Q.push(adj[u][i]);
                dist[adj[u][i]] = dist[u] + 1;
            }
        }
    }

    if(dist[t] != adj.size()){
        return dist[t];
    }
    return -1;
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
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t) << std::endl;
}
