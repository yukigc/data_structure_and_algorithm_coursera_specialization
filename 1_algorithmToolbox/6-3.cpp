#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long max(long long a, long long b){
    if (a>=b){
        return a;
    }
    return b;
}

long long min(long long a, long long b){
    if (a>=b){
        return b;
    }
    return a;
}

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } 
    else if (op == '+') {
        return a + b;
    } 
    else if (op == '-') {
        return a - b;
    } 
    return -1;
}

long long maxValue(const string& exp){

    int n = (exp.size()+1)/2;

    vector<vector<long long> > result(n);
    for (int i = 0; i < result.size(); i++){
        result[i].resize(n);
    }

    for (int i=0; i<n; i++){
        result[i][i] = (int)(exp[2*i]-'0');
    }
    for (int i=0; i<n-1; i++){
        result[i][i+1] = eval((int)(exp[2*i]-'0'), (int)(exp[2*(i+1)]-'0'),exp[2*i+1]);
        result[i+1][i] = eval((int)(exp[2*i]-'0'), (int)(exp[2*(i+1)]-'0'),exp[2*i+1]);
    }
    /* 
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    */

    if (n>2){
        for (int r=2; r<n; r++){
            for (int i=0; i<n-r; i++){
                result[i][i+r] = 9223372036854775807; //LONG_LONG_MAX
                result[i+r][i] = -9223372036854775807;
                for (int s=0; s<r; s++){
                    vector<long long> temp;
                    temp.push_back(eval(result[i][i+s], result[i+s+1][i+r],exp[2*(i+s)+1]));
                    temp.push_back(eval(result[i][i+s], result[i+r][i+s+1],exp[2*(i+s)+1]));
                    temp.push_back(eval(result[i+s][i], result[i+s+1][i+r],exp[2*(i+s)+1]));
                    temp.push_back(eval(result[i+s][i], result[i+r][i+s+1],exp[2*(i+s)+1]));

                    result[i][i+r] = min(*min_element(temp.begin(),temp.end()),result[i][i+r]);
                    result[i+r][i] = max(*max_element(temp.begin(),temp.end()),result[i+r][i]);
                }
            }
        }
    }
    return result[n-1][0];
}


int main(){
    string s;
    cin >> s;
    cout << maxValue(s) << endl;
    return 0;
}