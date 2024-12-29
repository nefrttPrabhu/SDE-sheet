Node* segregate(Node *head) {
    // Create dummy nodes for 0, 1, and 2
    Node* zeros = new Node(-1);  
    Node* ones = new Node(-1);   
    Node* twos = new Node(-1);   
    
    // Temporary pointers to track the last node in each list
    Node *z = zeros, *o = ones, *t = twos;
    Node* temp = head;
    
    // Traverse the original linked list
    while(temp != NULL) {
        int val = temp->data;
        
        // Add the current node to the appropriate list based on its value
        if(val == 0) {
            z->next = temp;
            z = z->next;
        }
        else if(val == 1) {
            o->next = temp;
            o = o->next;
        }
        else {
            t->next = temp;
            t = t->next;
        }
        temp = temp->next;
    }
    
    // Terminate the list of twos to avoid a cycle
    t->next = NULL;
    
    // Link the three lists together: 0's -> 1's -> 2's
    o->next = twos->next;  // Link 1's list to 2's list
    z->next = ones->next;  // Link 0's list to 1's list
    
    // Return the new list starting from the first node after the dummy node
    return zeros->next;
}
