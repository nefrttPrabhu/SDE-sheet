// Function to delete the tail node from the linked list
void deleteFromTail(Node*& head) {
    // Check if the list is empty
    if (head == NULL) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // If there's only one node in the list
    if (head->next == NULL) {
        delete head; // Free the memory of the node
        head = NULL; // Update head to NULL
        cout << "The last node was deleted. The list is now empty." << endl;
        return;
    }

    // General case: Traverse to the second-last node
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // 'temp' now points to the second-last node
    Node* tail = temp->next; // Save the last node
    temp->next = NULL;       // Disconnect the last node
    delete tail;             // Free memory of the last node
}
