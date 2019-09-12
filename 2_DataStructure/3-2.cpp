#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

struct Query {
    string type, s;
    size_t ind; // check index
};

class QueryProcessor {
    int bucket_count;
    vector < list <string> > table; // 为什么一开始vector嵌套vector不行呢？？？

    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i) 
            hash = (hash * multiplier + s[i]) % prime; // sequence! 
            // Hash function: in case negative, and keep value less than prime at every step
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
    } // initialize 

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check"){
            if (table[query.ind].empty()==true){
                cout << endl;
            }
            else{
                for (list<string>::iterator it = table[query.ind].begin(); it != table[query.ind].end(); it++){
                    cout << *it << " ";
                }
                cout << endl;
            }
            
        }
        else{
            int h = hash_func(query.s);
            int flag = 0; 
            list<string>::iterator it = table[h].begin();
            while (it != table[h].end()){
                if (*it == query.s){
                    flag = 1;
                    break;
                }
                it++;
            }

            if (query.type == "find"){
                writeSearchResult(it != table[h].end());
            }
            else if (query.type == "add"){
                if (it == table[h].end()){
                    table[h].push_front(query.s);
                }
            }
            else if (query.type == "del"){
                if (it != table[h].end()){
                    table[h].erase(it);
                }
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        table.resize(bucket_count); // initialize table!!!
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}

