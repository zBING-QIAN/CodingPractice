#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * 
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        ListNode *prev = 0,*cur = head,*kth=0,*kth_prev = 0,*ans_head=head;
        int len=0;
        for(ListNode *tmp=head;tmp;tmp=tmp->next){if(len==k-1){ans_head = tmp;}len++;}
        int n = len-len%k+1;
        for(int i=0;i<n;i++){
            
            ListNode *tmp =(cur) ?cur->next:0;
            if(i%k==0){
                
                if(kth_prev){kth_prev->next = prev;}
                if(kth)kth->next = cur;
                kth_prev = kth;
                kth = cur;
                
            }
            else {
                cur->next = prev;
            }
            prev = cur;
            cur = tmp;
        }
        return ans_head;
    }
};