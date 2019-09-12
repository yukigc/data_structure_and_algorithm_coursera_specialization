#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;
using std::priority_queue;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
    //write your code her
    int inf = 0;
    for (int i=0; i<cost.size(); i++){
        for(int j=0; j<cost[i].size(); j++){
            inf += cost[i][j];
        }
    }
    inf ++;
   
    vector<int> dist(adj.size(), inf);
    dist[s] = 0;
    vector<int> known(adj.size(), 0);
    //known[s] = 1;

    for (int i=0; i<adj.size(); i++){
        int min = inf;
        int u = 0;
        for (int j=0; j<adj.size(); j++){
            if (known[j]==0 && dist[j]<= min){
                min = dist[j];
                u = j;
            }
        }
        known[u] = 1;

        for (int j=0; j<adj[u].size(); j++){
            if (dist[adj[u][j]] > (dist[u] + cost[u][j])){
                dist[adj[u][j]] = dist[u] + cost[u][j];
            }
        }
    }

    if (dist[t] != inf){
        return dist[t];
    }
    return -1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, s, t) << std::endl;
}
