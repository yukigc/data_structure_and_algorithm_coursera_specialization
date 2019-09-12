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

struct node{
    int index;
    char* suffix;
};

int cmpfunc(const void* x, const void* y){
    struct node* rx = (struct node*)x; 
    struct node* ry = (struct node*)y; 
    return strcmp(rx->suffix, ry->suffix);
}

int* suffixArray(char* text, int len){
    struct node suffix[len];

    for (int i=0; i<len; i++){
        suffix[i].index = i;
        suffix[i].suffix = (text+i);
    }

    qsort(suffix, len, sizeof(struct node), cmpfunc);

    int* suffix_arr = (int*)malloc(len*sizeof(int));
    for (int i=0; i<len; i++){
        suffix_arr[i] = suffix[i].index;
    }

    return suffix_arr;
} 

string BWT(char* text, int len){
    int* suffix_arr = suffixArray(text, len); 
    string result = "";

    for (int i=0; i<len; i++){
        int j = suffix_arr[i]-1;
        if (j<0){
            j += len;
        }
        result += text[j];
    }
    return result;
}

int main() {
    string text;
    cin >> text;
    char * t=(char*)text.data();
    int l = text.size();
    cout << BWT(t, l) << endl;
    return 0;
}