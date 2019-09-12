#include <iostream>
#include <vector>

using namespace std;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
    //write your code here
    int inf = 0;
    for (int i=0; i<cost.size(); i++){
        for(int j=0; j<cost[i].size(); j++){
            if (cost[i][j] >0){
                inf += cost[i][j];
            }
        }
    }
    inf ++;
   
    vector<int> dist(adj.size(), inf);
    int s = 0;
    dist[s] = 0;

    for (int i=0; i<adj.size()-1; i++){

        for (int j=0; j<adj.size(); j++){
            for (int k=0; k<adj[j].size(); k++){
                if (dist[adj[j][k]] > (dist[j] + cost[j][k])){
                    dist[adj[j][k]] = (dist[j] + cost[j][k]);
                }
            }
        }
    }

    //v th iteration
    //vector<int> mark(adj.size(), 0);
    for (int j=0; j<adj.size(); j++){
        for (int k=0; k<adj[j].size(); k++){
            if (dist[adj[j][k]] > (dist[j] + cost[j][k])){
                dist[adj[j][k]] = dist[j] + cost[j][k];
                return 1;
            }
        }
    }

    return 0;
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
    cout << negative_cycle(adj, cost) << endl;
}
