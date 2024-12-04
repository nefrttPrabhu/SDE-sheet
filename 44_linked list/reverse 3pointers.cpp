
void reverseLinkedList(Node* &head) {
    Node* prev = NULL; // Initially, there is no previous node
    Node* curr = head; // Start with the head of the list
    Node* next = NULL; // Temporary pointer to store the next node

    while (curr != NULL) {
        // Store the next node
        next = curr->next;

        // Reverse the current node's pointer
        curr->next = prev;

        // Move pointers forward
        prev = curr;     // Move prev to the current node
        curr = next;     // Move curr to the next node
    }

    // Update head to the new first node
    head = prev;
}
