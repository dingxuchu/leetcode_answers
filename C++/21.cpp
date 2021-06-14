// 合并两个有序列表

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode* result = nullptr;
        ListNode* beginResult = nullptr;
        if (l1->val <= l2->val) {
            beginResult = l1;
            l1 = l1->next;
        } else {
            beginResult = l2;
            l2 = l2->next;
        }
        result = beginResult;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                result->next = l2;
                result = result->next;
                l2 = l2->next;
                continue;
            }
            if (l2 == nullptr) {
                result->next = l1;
                result = result->next;
                l1 = l1->next;
                continue;
            }
            if (l1->val <= l2->val) {
                result->next = l1;
                result = result->next;
                l1 = l1->next;
            } else {
                result->next = l2;
                result = result->next;
                l2 = l2->next;
            }
        }
        return beginResult;
    }
};