#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp=new ListNode(0);
        ListNode *cur=temp;
        int carry=0;
        while(l1!=NULL or l2!=NULL) {
            ListNode *node=new ListNode(0);
            if(l1!=NULL) {
                node->val+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL) {
                node->val+=l2->val;
                l2=l2->next;
            }
            node->val+=carry;
            if(node->val>9) {
                node->val=(node->val)%10;
                carry=1;
            }
            else carry=0;
            temp->next=node;
            temp=node;
        }
        if(carry==1) {
            ListNode *n=new ListNode(1);
            temp->next=n;
        }
        return cur->next;
    }
};