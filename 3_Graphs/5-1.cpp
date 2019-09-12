#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

struct edge {
    int x;
    int y;
    double weight;
};

bool sortFun(const edge &e1, const edge &e2)
{
    const double eps = 1e-10;
	return e1.weight - e2.weight < eps;
}

int ffind(int x, vector<int> &parents){
    if( x != parents[x]){
        parents[x] = ffind(parents[x], parents);
    }
    return parents[x];
}


double minimum_distance(vector<int> &x, vector<int> &y) {
    double result = 0.;
    // calculate edges weight and sort
    int n = x.size();
    int m = (int)(n*(n-1)/2);
    vector<edge> E(m);
    
    int c = 0;
    for(int i=0; i<n; i++){
        for (int j=0; j<i; j++){ 
            double temp = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
            edge e;
            e.x = i;
            e.y = j;
            e.weight = temp;
            E[c] = e;
            c++;
        }
    }
    sort(E.begin(), E.end(), sortFun);
    
    vector<int> parents(n);
    for (int i=0; i<parents.size(); i++){
        parents[i] = i;
    }
    vector<int> rank(n, 0);
    for (int i=0; i<E.size(); i++){
        int a = ffind(E[i].x, parents);
        int b = ffind(E[i].y, parents);
        if (a!= b){
            result += E[i].weight;
            //merge
            if (rank[a] > rank[b] ){
                parents[b] = a;
            }
            else{
                parents[a] = b;
                if (rank[a] == rank[b]){
                    rank[b] +=1;
                }
            }
        }
    }
    return result;
} 


int main() {
    size_t n;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
