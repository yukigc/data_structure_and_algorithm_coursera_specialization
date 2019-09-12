#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void siftDown(vector< pair<int, long long> >& workers, int i){
    
    int minIndex = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l<workers.size() && workers[l].second < workers[minIndex].second){
        minIndex = l;
    }
    if (r<workers.size() && workers[r].second < workers[minIndex].second){
        minIndex = r;
    }
    if (l<workers.size() && workers[l].second == workers[minIndex].second){
        if (workers[l].first < workers[minIndex].first){
            minIndex = l;
        }
    }
    if (r<workers.size() && workers[r].second == workers[minIndex].second){
        if (workers[r].first < workers[minIndex].first){
            minIndex = r;
        }
    }

    if (i != minIndex){
        swap(workers[i], workers[minIndex]);
        siftDown(workers,minIndex);
    }
      
}


int main(){

    int n,m;
    cin >> n >> m;

    vector< pair<int, long long> > workers(n); // first=index second=time
    for (int i=0; i<n; i++){
        workers[i].first = i;
        workers[i].second = 0;
    }

    vector<int> times(m);
    for (int i=0; i<m; i++){
        cin >> times[i];
    }

    // 

    for (int i=0; i<m; i++){
        cout << workers[0].first << " " << workers[0].second << endl;

        // extract max (assign time and sift down)
        workers[0].second += (long long)times[i];
        siftDown(workers, 0);
    }
    return 0;
}