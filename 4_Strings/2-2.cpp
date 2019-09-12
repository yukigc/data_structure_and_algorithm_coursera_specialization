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
    int data;
    struct node* next;
};

int cmpfunc(const void* x, const void* y){
    const char* cx = (const char*)x; 
    const char* cy = (const char*)y; 
    return strcmp(cx, cy);
}

struct node* getNode(int i){
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = i;
    nn->next = NULL;
    return nn;
}

void addLast(struct node** head, struct node* nn){
    if (*head == NULL){
        *head = nn;
        return;
    }
    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = nn;
}

void leftShift(struct node** head, int index, int* lshift){
    lshift[index] = (*head)->data;
    (*head) = (*head)->next;
}

void inverseBWT(char* bwt, int len){

    int i,len_bwt = len;
    char* sorted_bwt = (char*)malloc(len * sizeof(char)); 
    //strcpy(sorted_bwt, bwt); 
    int* l_shift = (int*)malloc(len * sizeof(int)); 

    //qsort(sorted_bwt, len, sizeof(char), cmpfunc);
    //counting sort
    vector<int> count(4);
    int cnt;
    for (int i=0; i<len; i++){
        switch (bwt[i])
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


    struct node* arr[128] = {NULL};
    for (int i=0; i<len; i++){
        struct node* nn = getNode(i);
        addLast(&arr[bwt[i]], nn);
    }

    for (int i=0; i<len; i++){
        leftShift(&arr[sorted_bwt[i]],i, l_shift);
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