#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<long long>& output) {
    for (long long i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

ull PolyHash(string s, long long p, long long x){
    ull hash = 0;
    for (long long i=s.size()-1; i>=0; i--){
        hash = ((hash*x + s[i])%p + p) % p;
    }
    return hash;
}

std::vector<long long> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<long long> ans;

    // pre calculate hash
    long long prime = 1000000007;
    long long multiplier = 10000;

    ull phash = PolyHash(s, prime, multiplier);
    //cout << phash << endl;

    long long length = t.size() - s.size() +1;
    vector<ull> preHash(length);

    string s0;
    if (t.size() != s.size()){
        s0 = t.substr(t.size() - s.size(),t.size() - 1);
    }
    else{
        s0 = t;
    }
    
    //cout << "substr " <<  s0 << endl;
    preHash[t.size() - s.size()] = PolyHash(s0, prime, multiplier);
    //cout << "prehash1 " <<  preHash[t.size() - s.size()] << endl;
    ull y = 1;
    for (long long i=1; i<=s.size(); i++){
        y = ((y*multiplier)%prime + prime) % prime;
    }
    //cout << "y " <<  y << endl;
    long long start = t.size() - s.size()-1;
    //cout << "start " <<  start << endl;
    for (long long i=start; i>=0; i--){
        preHash[i] = ((multiplier*preHash[i+1])%prime + t[i] - y*t[i+s.size()]%prime + prime) % prime;
        //cout << "prehash " <<  preHash[i] << endl;
    }
    
    for (long long i = 0; i + s.size() <= t.size(); i++){
        if (phash == preHash[i]){
            int flag = 1;
            for (long long j=i; j<i+s.size(); j++){
                if (t[j] != s[j-i]){
                    flag = 0;
                    break;
                }
            }

            if (flag == 1){
                ans.push_back(i);
            }
        }
    }


    /* 
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    */
    return ans;
}




int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}