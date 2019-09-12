#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}


vector<string> process_queries(const vector<Query>& queries){
    unordered_map<int,string> contacts;
    vector<string> result;
    for (int i=0; i<queries.size(); i++){
        if (queries[i].type == "add"){
            if (contacts.find(queries[i].number)==contacts.end()){
                // new number
                contacts.insert(make_pair(queries[i].number,queries[i].name));
            }
            else{
                contacts[queries[i].number] = queries[i].name;
            }  
        }
        else if (queries[i].type == "del"){
            if (contacts.find(queries[i].number) != contacts.end()){
                contacts.erase(queries[i].number);
            }
        }
        else{
            if (contacts.find(queries[i].number)==contacts.end()){
                result.push_back("not found");
            }
            else{
                result.push_back(contacts[queries[i].number]);
            }
        }
    }
    return result;
}


int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}


