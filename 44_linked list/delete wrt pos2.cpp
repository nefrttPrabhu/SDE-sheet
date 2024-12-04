void deleteNode(Node* &head, int pos) {
    // Handle edge case where the list is empty
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;

    // Handle deletion of the first node
    if (pos == 1) 
    {
        head = head->next; // Move the head to the next node
        delete temp;       // Free the memory of the old head
        return;
    }

    // Traverse to the node just before the one to be deleted
    Node* prev = NULL;
    int cnt = 1;
    while (temp != NULL && cnt < pos) //bus apna cnt<pos ye dekh rha ki agar length bhot lambi hi list ki but hume delete 2nd ya 3rd karna hi toh faltu temp null toh kyu chalaye 
    {                                 
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    // Check if the position is valid
    if (temp == NULL) //agar ye nhi likhte toh manlo pos de diya 10 but length humari 2nodes ki hai and cnt ka kya hi vo toh then always he less than pos hota uper ke hisab se
    {                 //toh ye neeche jata or null pointer exception ka error aata jab prev->next=temp->next hota coz sab toh null null hi    
        cout << "Invalid position. No node to delete." << endl;
        return;
    }

    // Update the links and delete the node
    prev->next = temp->next;
    delete temp;
}
