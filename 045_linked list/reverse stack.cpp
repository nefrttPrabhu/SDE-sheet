/*
S1: phele ek baar puri list traverse karo stack mai data store karo 
S2: then usse stack ke top ko store karo pop karo and top ke element se list ke element ko overwrite karo
head->[5]->[4]->[3]->[2]->[1]->NULL
                                | 1 | 1st pop and overwrite node 1 data
                                | 2 | 2nd pop and overwrite node 2 data
                                | 3 | 3rd pop and overwrite node 3 data
                                | 4 | 4th pop and overwrite node 4 data
                                | 5 | 5th pop and overwrite node 5 data
*/

Node* reverseLinkedList(Node* head) {
    // Create a temporary pointer
    // to traverse the linked list
    Node* temp = head;  
    
    // Create a stack to temporarily
    // store the data values
    stack<int> st;     

    // Step 1: Push the values of the
    // linked list onto the stack
    while (temp != nullptr) {
        // Push the current node's
        // data onto the stack
        st.push(temp->data); 
        
        // Move to the next node
        // in the linked list
        temp = temp->next;    
    }
    
    // Reset the temporary pointer to
    // the head of the linked list
    temp = head; 
    
    // Step 2: Pop values from the stack
    // and update the linked list
    while (temp != nullptr) {
        // Set the current node's data to
        // the value at the top of the stack
        temp->data = st.top();  //overwrite value from the top value of stack
        
        // Pop the top element from the stack
        st.pop();              
        
        // Move to the next node
        // in the linked list
        temp = temp->next;     
    }
    
    // Return the new head of
    // the reversed linked list
    return head;  
}
