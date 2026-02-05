/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val; // makes it a min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;

        // 1) Put the head of each non-empty list into the heap
        for (ListNode* head : lists) {
            if (head) pq.push(head);
        }

        // 2) Build the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            // 3) Push the next node from the list we just took from
            if (node->next) pq.push(node->next);
        }

        tail->next = nullptr;
        return dummy.next;
    }
};
