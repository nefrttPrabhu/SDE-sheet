//M1: Using stack and overwriting values



//M2: changing links
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; // Return the list as is if it's empty or has a single node
        }

        ListNode* odd = head; // Pointer for odd-indexed nodes
        ListNode* even = head->next; // Pointer for even-indexed nodes
        ListNode* evenHead = head->next; // Save the head of the even list for later connection

        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next; // Link current odd node to the next odd node
            even->next = even->next->next; // Link current even node to the next even node

            odd = odd->next; // Move odd pointer to the next odd node
            even = even->next; // Move even pointer to the next even node
        }

        odd->next = evenHead; // Connect the end of the odd list to the head of the even list
        return head; // Return the modified list
    }
};

