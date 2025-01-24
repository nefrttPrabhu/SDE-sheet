struct Node {
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to create a linked list from an array
Node* createLinkedList(int a[], int n) {
    Node* head = NULL; // Initialize head to NULL
    Node* temp = NULL; // Temporary pointer for traversing the list

    for (int i = 0; i < n; i++) {
        Node* x = new Node(a[i]); // Create a new node with the current array element
        if (i == 0) {
            head = x;    // Set head to the first node
            temp = head; // Initialize temp to point to head
        } else {
            temp->next = x; // Link the current node to the previous node
            temp = temp->next; // Move temp to the current node
        }
    }
    return head; // Return the head of the linked list
}
