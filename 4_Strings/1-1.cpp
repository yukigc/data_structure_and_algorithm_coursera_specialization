#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;
using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
    trie t;
    // write your code here
    edges e0;
    t.push_back(e0);
    int cnt = 1;
    for (int i=0; i<patterns.size(); i++){
        string p = patterns[i];
        int currentN = 0;
        for (int j=0; j<p.size(); j++){
            char currentS = p[j];
            map<char,int>::iterator it;
            it = t[currentN].find(currentS);
            if (t[currentN].size()==0 || it == t[currentN].end()){
                t[currentN].insert(pair<char, int>(currentS, cnt));
                edges e;
                t.push_back(e);
                currentN = cnt;
                cnt++;
            }
            else{
                currentN = it->second;
            }
        }
    }
    return t;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<string> patterns;
    for (size_t i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        patterns.push_back(s);
    }

    trie t = build_trie(patterns);
    for (size_t i = 0; i < t.size(); ++i) {
        map<char,int>::iterator iter;
        for (iter = t[i].begin(); iter!=t[i].end(); ++iter) {
        std::cout << i << "->" << iter->second << ":" << iter->first << "\n";
        }
    }

  return 0;
}