/**
Use a priority queue with the operator from the cmp structure so that priority queue organizes nodes in a minheap structure

First push the head of each of the lists into pq so that you have the smallest possible values from all of the lists, organized in the minheap.
Create a dummy List to return and a listnode called tail that points to the address of dummy.

In a while loop
Create a pointer called node, to the top of pq and pop pq off the heap so it doesn't need to be considered in the future and make node be tail->next.
If node->next isn't a nullptr add it to the minheap. This step makes sure that every node from each list eventually is added to pq, and by the properties of a minheap it is organized in the correct order against the other nodes already in pq. 

When you're at the end of the loop assign tail->next=nullptr and return dummy.next because that is the start of the list.

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

        for (ListNode* head : lists) {
            if (head) pq.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next) pq.push(node->next);
        }

        tail->next = nullptr;
        return dummy.next;
    }
};
