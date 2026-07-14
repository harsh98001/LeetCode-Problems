class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base cases: if one list is empty, return the other
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        // Recursive case: choose the smaller node and merge the rest
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};