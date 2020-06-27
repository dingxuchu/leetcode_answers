// 两数相加

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int firstResultVal = l1->val + l2->val;
        bool moreThanTen = false;
        if (firstResultVal >= 10) {
            moreThanTen = true;
            firstResultVal %= 10;
        }
        ListNode* resultListNode = new ListNode(firstResultVal);
        ListNode* nextResultListNode = resultListNode;
        bool l1NotEnd = l1->next != nullptr;
        bool l2NotEnd = l2->next != nullptr;
        while (l1NotEnd || l2NotEnd) {
            firstResultVal = 0;
            if (l1NotEnd) {
                l1 = l1->next;
                firstResultVal += l1->val;
            }
            if (l2NotEnd) {
                l2 = l2->next;
                firstResultVal += l2->val;
            }
            if (moreThanTen) {
                firstResultVal += 1;
                moreThanTen = false;
            }
            if (firstResultVal >= 10) {
                moreThanTen = true;
                firstResultVal %= 10;
            }
            ListNode* singleListNode = new ListNode(firstResultVal);
            nextResultListNode->next = singleListNode;
            nextResultListNode = nextResultListNode->next;
            l1NotEnd = l1->next != nullptr;
            l2NotEnd = l2->next != nullptr;
        }
        if (moreThanTen) {
            ListNode* singleListNode = new ListNode(1);
            nextResultListNode->next = singleListNode;
        }
        return resultListNode;
    }
};
