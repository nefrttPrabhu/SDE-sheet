
// Utility function to insert node at the end of the list
void insertNode(node* &head, int val) {
    node* newNode = new node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// Utility function to rotate list by k times
node* rotateRight(node* head, int k) {
    if (head == NULL || head->next == NULL) return head;
    for (int i = 0; i < k; i++) {
        node* temp = head;
        while (temp->next->next != NULL) 
          temp = temp->next;
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}

// Utility function to print list
void printList(node* head) {
    while (head->next != NULL) {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}
