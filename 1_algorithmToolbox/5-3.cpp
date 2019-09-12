#include <iostream>
#include <string>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2){

    int a= str1.size()+1;
    int b= str2.size()+1;
    vector<vector<int> > result(a);
    for (int i = 0; i < result.size(); i++){
        result[i].resize(b);
    }
    for(int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[0].size();j++){
            if (i==0){
                result[i][j] = j;
            }
            else if (j==0){
                result[i][j] = i;
            }
            else{
                result[i][j] = 0;
            }
            
        }
    }

    for (int i=1; i<a; i++){
        for (int j=1; j<b; j++){
            int diff = 1;
            if (str1[i-1]==str2[j-1]){
                diff = 0;
            }

            result[i][j] = result[i-1][j-1] + diff;
            if (result[i][j-1]+1 < result[i][j] ){
                result[i][j] = result[i][j-1]+1;
            }
            if (result[i-1][j]+1 < result[i][j] ){
                result[i][j] = result[i-1][j]+1;
            }
        }
    }

        return result[a-1][b-1];
    }

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << edit_distance(str1, str2) << endl;
    return 0;
}