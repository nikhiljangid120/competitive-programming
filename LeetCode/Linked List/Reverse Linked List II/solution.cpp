class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // STEP 1: Walk to position before 'left'
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        // STEP 2: Reverse by moving nodes to front
        ListNode* curr = prev->next;
        
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;      // node to move
            curr->next = temp->next;          // skip it
            temp->next = prev->next;          // move to front
            prev->next = temp;                // connect it
        }      
        return dummy->next;
    }
};