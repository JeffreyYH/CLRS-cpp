#include <iostream>
using namespace std;

template <typename Dtype>
struct ListNode {
    Dtype key;
    ListNode *prev;
    ListNode *next;
    ListNode(Dtype x) {data=x; prev=NULL; next=NULL;};
};


