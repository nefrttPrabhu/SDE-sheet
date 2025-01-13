// Function to reverse the linked list
void reverseLinkedList(Node* &head) {
    Node* prev = NULL;  // Initially, there is no previous node
    Node* front = head; // Start with the head of the list
    Node* curr = NULL;  // Temporary pointer to store the current node

    while (front != NULL) {
        curr = front;       // Store the current node
        front = front->next; // Move to the next node
        curr->next = prev;   // Reverse the current node's pointer
        prev = curr;         // Move the `prev` pointer to the current node
    }

    // Update head to the new first node
    head = prev;
}
