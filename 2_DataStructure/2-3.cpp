#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(vector< pair<int, int> > Tables, int i){
    if (i != Tables[i].first){
        Tables[i].first = getParent(Tables,Tables[i].first);
    }
    return Tables[i].first;    
}


int main(){

    int n;
    int m;
    int maxSize=0;
    cin >> n >> m;

    vector< pair<int, int> > Tables(n+1); // first=parent, second=size
    vector<int> Rank(n+1);
    for (int i=1; i<n+1; i++){
        Tables[i].first = i;
        cin >> Tables[i].second;
        if (Tables[i].second > maxSize){
            maxSize = Tables[i].second;
        }
        Rank[i] = 0;
    }
    
    // merge tables
    for (int i=0; i<m; i++){
        int dest;
        int src;
        cin >> dest >> src;

        int pd = getParent(Tables,dest);
        int ps = getParent(Tables,src);

        if (pd != ps){
            if (Rank[pd] > Rank[ps]){
                Tables[ps].first = pd;
            }
            else{
                Tables[ps].first = pd;
                if (Rank[ps] == Rank[pd]){
                    Rank[pd] +=1;
                }
            }
            Tables[pd].second += Tables[ps].second;
            Tables[ps].second = 0;

            if (Tables[pd].second > maxSize){
                maxSize = Tables[pd].second;
            }
        }
        cout << maxSize << endl;  
    }
}
