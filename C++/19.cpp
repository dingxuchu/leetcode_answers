// 删除链表的倒数第 N 个结点

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr && n == 1) {
            return nullptr;
        }
        ListNode* beginHead = head;
        ListNode* removeResult = head;
        size_t beginNum = 0;
        bool beginCount = false;
        while (head->next != nullptr) {
            if (beginNum >= n) {
                beginCount = true;
            }
            if (beginCount) {
                removeResult = removeResult->next;
            }
            beginNum++;
            head = head->next;
        }
        if (beginNum == n - 1) {
            beginHead = beginHead->next;
        } else {
            removeResult->next = removeResult->next->next;
        }
        return beginHead;
    }
};