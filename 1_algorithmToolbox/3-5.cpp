#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Segment{
    int start, end;
};

bool sortFunction(Segment i, Segment j){
    return (i.end < j.end);
}

int CoverSegments(int n, vector<Segment>& segments){
    
    sort(segments.begin(), segments.end(), sortFunction);

    vector<int> points;
    int p = segments[0].end;
    points.push_back(p);
    for (int i=1; i<n; i++){
        if (segments[i].start > p || segments[i].end < p){
            p = segments[i].end;
            points.push_back(p);
        }
    }

    cout << points.size() << endl;
    for (int i=0; i<points.size(); i++){
        cout << points[i] << " ";
    }
    cout << endl;

    return 0;
}


int main(){

    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (int i=0; i<n; i++){
        cin >> segments[i].start;
        cin >> segments[i].end;
    }

    CoverSegments(n, segments);

    return 0;
}