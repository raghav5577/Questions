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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head node to simplify list construction
        ListNode dummyHead;
      
        // Initialize carry for handling digit overflow
        int carry = 0;
      
        // Pointer to track the current position in the result list
        ListNode* current = &dummyHead;
      
        // Continue while there are digits in either list or a carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get current digit values (0 if a list is exhausted)
            int digit1 = (l1 == nullptr) ? 0 : l1->val;
            int digit2 = (l2 == nullptr) ? 0 : l2->val;
          
            // Calculate sum of current digits plus any carry from previous addition
            int sum = digit1 + digit2 + carry;
          
            // Update carry for next iteration (sum / 10)
            carry = sum / 10;
          
            // Create new node with the digit (sum % 10) and append to result
            current->next = new ListNode(sum % 10);
          
            // Move current pointer to the newly created node
            current = current->next;

            // Move to next nodes in input lists if they exist
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
      
        // Return the actual head of the result list (skip dummy head)
        return dummyHead.next;
    }
};
