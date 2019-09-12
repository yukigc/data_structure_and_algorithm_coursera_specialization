#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std;

void inverseBWT(char* bwt, int len){

    int i,len_bwt = len;
    char* sorted_bwt = (char*)malloc(len * sizeof(char)); 
    vector<int> l_shift(len);

    //counting sort
    vector<int> count(4);
    int cnt;
    char* p = bwt;
    for (int i=0; i<len; i++){
        switch (*p)
        {
        case 'A':
            count[0]++;
            break;
        case 'C':
            count[1]++;
            break;
        case 'G':
            count[2]++;
            break;
        case 'T':
            count[3]++;
            break;
        case '$':
            cnt = i;
            break;
        }
        p++;
    }
    char* symbol = sorted_bwt;
    *symbol = '$';
    symbol++;
    for (int i=0; i<count[0]; i++){
        *symbol = 'A';
        symbol++;
    }
    for (int i=0; i<count[1]; i++){
        *symbol = 'C';
        symbol++;
    }
    for (int i=0; i<count[2]; i++){
        *symbol = 'G';
        symbol++;
    }
    for (int i=0; i<count[3]; i++){
        *symbol = 'T';
        symbol++;
    }

    vector<int> sub_count(4);
    char* q = bwt;
    for (int i=0; i<len; i++){
        int first=0;
        switch (*q)
        {
        case 'A':
            first = 1 + sub_count[0];
            sub_count[0]++;
            break;
        case 'C':
            first = 1 + count[0]+ sub_count[1];
            sub_count[1]++;
            break;
        case 'G':
            first = 1 + count[0] + count[1]+ sub_count[2];
            sub_count[2]++;
            break;
        case 'T':
            first = 1 + count[0] + count[1]+ count[2]+ sub_count[3];
            sub_count[3]++;
            break;
        case '$':
            first = 0;
            break;
        }
        l_shift[first] = i;
        q++;
    }

    for (int i=0; i<len; i++){
        cnt = l_shift[cnt];
        cout << bwt[cnt];
    }
}

int main() {
    string text;
    cin >> text;
    char * t=(char*)text.data();
    int l = text.size();
    inverseBWT(t, l);
    cout << endl;
    return 0;
}