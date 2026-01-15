class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Fix the current node
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
