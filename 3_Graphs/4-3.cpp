#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest, long long inf) {
    //write your code here
    distance[s] = 0;

    for (int i=0; i<adj.size()-1; i++){
        for (int j=0; j<adj.size(); j++){
            for (int k=0; k<adj[j].size(); k++){
                if (distance[j] < inf){
                    if (distance[adj[j][k]] > (distance[j] + cost[j][k])){
                        distance[adj[j][k]] = (distance[j] + cost[j][k]);
                    }
                }
            }
        }
    }

    for (int i=0; i<adj.size(); i++){
        if (distance[i] < inf){
            reachable[i] = 1;
        }
    }

    //v th iteration
    queue<int> Q;
    vector<int> visited(adj.size(), 0);
    for (int j=0; j<adj.size(); j++){
        for (int k=0; k<adj[j].size(); k++){
            if (distance[j] < inf){
                if (distance[adj[j][k]] > (distance[j] + cost[j][k])){
                    distance[adj[j][k]] = distance[j] + cost[j][k];
                    Q.push(adj[j][k]);
                    visited[adj[j][k]] = 1;
                }
            }
        }
    }


    // find all reachable by BFS
    while(!Q.empty()){
        int u = Q.front();
        shortest[u] = 0;
        Q.pop();
        for (int i=0; i<adj[u].size(); i++){
            if (!visited[adj[u][i]]){
                Q.push(adj[u][i]);
                visited[adj[u][i]] = 1;
            }
        }
    }
    


}

int main() {
    int n, m, s;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    std::cin >> s;
    s--;

    long long inf = 0;
    for (int i=0; i<cost.size(); i++){
        for(int j=0; j<cost[i].size(); j++){
            if (cost[i][j] >0){
                inf += (long long)(cost[i][j]);
            }
        }
    }
    inf ++;
    vector<long long> distance(n, inf);
    vector<int> reachable(n, 0);
    vector<int> shortest(n, 1);
    shortest_paths(adj, cost, s, distance, reachable, shortest, inf);
    for (int i = 0; i < n; i++) {
        if (!reachable[i]) {
        std::cout << "*\n";
        } else if (!shortest[i]) {
        std::cout << "-\n";
        } else {
        std::cout << distance[i] << "\n";
        }
    }
}
