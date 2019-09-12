#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;
using namespace std;

typedef map<char, pair<int, int> > edges;
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
            map<char,pair<int, int> >::iterator it;
            it = t[currentN].find(currentS);
            if (t[currentN].size()==0 || it == t[currentN].end()){
                if (j == p.size()-1){
                    t[currentN].insert(pair<char, pair<int, int> >(currentS, pair<int, int>(cnt, 1)));
                }
                else{
                    t[currentN].insert(pair<char, pair<int, int> >(currentS, pair<int, int>(cnt, 0)));
                }
                edges e;
                t.push_back(e);
                currentN = cnt;
                cnt++;
            }
            else{
                currentN = it->second.first;
                if (j == p.size()-1){
                    it->second.second = 1;
                }
            }
        }
    }
    return t;
}

int prefixTrieMatch(string text, vector<edges> &trie, int start){
    int index = start;
    char symbol = text[index];
    int v = 0;
    while (1){
        map<char,pair<int, int> >::iterator it;
        it = trie[v].find(symbol);
        if (it != trie[v].end()){
            if(trie[it->second.first].size()==0 || it->second.second==1){
                return start;
            }
            else{
                index++;
                symbol = text[index];
                v = it->second.first;
            }
        }
        else{
            return -1;
        }
    }
}

void TrieMatch(string text, vector<edges> &trie){
    for (int i=0; i<text.size(); i++){
        if (prefixTrieMatch(text, trie, i) != -1){
            cout << i << " ";
        }
    }
}


int main() {
    string text;
    std::cin >> text;
    size_t n;
    std::cin >> n;
    vector<string> patterns;
    for (size_t i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        patterns.push_back(s);
    }

    trie t = build_trie(patterns);
    
    TrieMatch(text, t);
    cout << endl;

  return 0;
}