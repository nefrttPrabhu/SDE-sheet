ListNode* removeElements(ListNode* head, int val) {
        // Handle cases where the head nodes match the value
        // ListNode* temp = head; isko yahan likhne ye ho ye rha hi ki ist while mai jab ja rha toh delete ho ja rha toh only temp neeche fir se head nhi dal pa rhe uske liye toh vo delete ho chuka hi 
        // isiliye while ke andar ek hi then delete hua then firse ek new same naam ka bana liya same concept variable scope se bhi relate ho rha do independent for loops mai ek he 'i' se hota hi  

        while (head != NULL && head->val == val) // idhar ek he baar toh check karna hi na toh if se kaam kyu nhi chala rhe ek he baar value same nhi do baar bhi ho saki if ek ke baad ek node hi same value ke but ye jo given wala case hi uske liye toh true honi chhiy thi na fir bhi RTE aa rha y???
        {
            ListNode* temp = head;  // Save the current head
            head = head->next;      // Move to the next node
            delete temp;            // Delete the current node
        }

        // Traverse the rest of the list
        ListNode* temp = head; //L2 related not valid to write only temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            if (temp->val == val) {
                prev->next = temp->next;  // Bypass the current node
                delete temp;              // Delete the current node
                temp = prev->next;        // Move to the next node
            } else {
                prev = temp;              // Update `prev` to the current node
                temp = temp->next;        // Move to the next node
            }
        }

        return head;
    }


/*
Edge Cases
Empty List:

If the list is empty (head == NULL), the function simply returns NULL.
All Nodes Have the Target Value:

The initial while loop will remove all nodes, and the final head will be NULL.
No Nodes Have the Target Value:

The function will traverse the list without making any changes.
Consecutive Nodes with the Target Value:

Handled effectively by the logic in both loops.

Time Complexity
O(n): Each node is visited once during traversal.
Space Complexity
O(1): The solution uses constant extra space.

*/
