
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
    ListNode* addTwoNumbers(ListNode* List1, ListNode* List2) {
        ListNode* dummy = new ListNode(-1); // Dummy node to start the result list
        ListNode* temp = dummy; // Pointer to track the current node
        int carry = 0; // To handle carry during addition

        // Loop until both lists are fully traversed 
        while (List1 != NULL || List2 != NULL) {
            int sum = 0; // Initialize sum for this iteration

            if (List1 != NULL) {
                sum = sum + List1->val; // Add value from List1
                List1 = List1->next; // Move to the next node in List1
            }

            if (List2 != NULL) {
                sum = sum + List2->val; // Add value from List2
                List2 = List2->next; // Move to the next node in List2
            }

            sum = sum + carry; // Add carry from the previous step
            carry = sum / 10; // Update carry for the next step

            ListNode* node = new ListNode(sum % 10); // Create a new node for the result
            temp->next = node; // Attach the new node to the result list
            temp = temp->next; // Move the pointer to the new node
            
            // If there is a remaining carry after the loop, create a new node with the carry
            if (carry) {
                ListNode* newNode = new ListNode(carry);
                curr->next = newNode;
            }

        // Return the head of the result linked list (next of the dummy node)
        return dummy->next;
    }
};


/*
Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.
Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.
*/
