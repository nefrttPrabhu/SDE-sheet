void deleteByValue(Node* &head, int val) {
    // Handle edge case: Empty list
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Handle the case where the value is in the head node
    if (head->data == val) {
        head = head->next; // Update the head
        delete temp;       // Free memory
        return;
    }

    // Traverse the list to find the node with the target value
    while (temp != NULL && temp->data != val) {
        prev = temp;        // Track the previous node
        temp = temp->next;  // Move to the next node
    }

    // If the value is not found
    if (temp == NULL) {
        cout << "Value not found in the list." << endl;
        return;
    }

    // Update the links and delete the node
    prev->next = temp->next;
    delete temp;
}
