class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;
        
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // Step 3: Merge the two halves
        ListNode* first = head;
        ListNode* second = prev; // 'prev' is now the head of the reversed second half
        
        while (second) {
            // Temporarily store the next nodes
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            // Link the current nodes
            first->next = second;
            second->next = temp1;

            // Move the pointers forward for the next iteration
            first = temp1;
            second = temp2;
        }
    }
};