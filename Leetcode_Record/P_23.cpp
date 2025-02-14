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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return MergeHelper(lists, 0, lists.size() - 1);
    }

    ListNode* MergeHelper(std::vector<ListNode*> lists, int start, int end)
    {
        if(start == end) return lists[start];

        if(start + 1 == end) return merge(lists[start], lists[end]);

        int mid = (start + end) / 2;

        ListNode* first = MergeHelper(lists, start, mid);
        ListNode* second = MergeHelper(lists, mid + 1, end);

        return merge(first, second);
    }

    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2;

        ListNode* nextDummy = dummy->next;
        delete dummy;
        return nextDummy;
    }
};