class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // Dummy node for the result linked list
        ListNode* current = dummy; // Pointer to traverse the result list
        int carry = 0; // Initialize carry to 0

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10; // Calculate carry for the next iteration

            current->next = new ListNode(sum % 10); // Add the digit to the result list
            current = current->next; // Move to the next node in the result list

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next; // Skip the dummy node and return the result list
    }
};
