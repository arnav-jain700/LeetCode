class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int count = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prevGroup = &dummy;
        curr = head;

        while (count >= k) {
            ListNode* prev = nullptr;
            ListNode* next_node = nullptr;
            
            ListNode* groupFirst = curr; 

            for (int i = 0; i < k; ++i) {
                next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
            }

            prevGroup->next = prev;
            groupFirst->next = curr;

            prevGroup = groupFirst;
            
            count -= k;
        }

        return dummy.next;
    }
};