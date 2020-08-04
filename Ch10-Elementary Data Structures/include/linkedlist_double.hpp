#include <iostream>
using namespace std;

template <typename Dtype>
struct doubleListNode {
    Dtype key;
    doubleListNode *prev;
    doubleListNode *next;
    doubleListNode(Dtype x) {data=x; prev=NULL; next=NULL;};
};


