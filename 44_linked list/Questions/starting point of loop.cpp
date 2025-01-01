//M1: brute force

// Function to detect a loop in a linked list
// and return the starting node of the loop
Node* detectLoop(Node* head) {
    
    // Use temp to traverse the linked list
    Node* temp = head;
    
    // hashmap to store all visited nodes
    unordered_map<Node*, int> mp;
    
    // Traverse the list using temp
    while(temp!=NULL){
        // check if temp has been encountered again
        if(mp.count(temp)!=0){
            // A loop is detected hence return temp
            return temp;
        }
        // store temp as visited
        mp[temp] = 1;
        // iterate through the list
        temp = temp->next;
    }

    // If no loop is detected, return nullptr
    return nullptr; 
}



//M2: optimal
// Function to find the first node
// of the loop in a linked list
Node* firstNode(Node* head) {
    
    // Initialize a slow and fast 
    // pointers to the head of the list
    Node* slow = head;  
    Node* fast = head;  

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL) {
        
        // Move slow one step
        slow = slow->next;        
        
        // Move fast two steps
        fast = fast->next->next;  

        // If slow and fast meet,
        // a loop is detected
        if (slow == fast) {
            
             // Reset the slow pointer
             // to the head of the list
            slow = head; 

            // Phase 2: Find the first node of the loop
            while (slow != fast) {
                
                // Move slow and fast one step
                // at a time
                slow = slow->next;  
                fast = fast->next;  

                // When slow and fast meet again,
                // it's the first node of the loop
            }
            
            // Return the first node of the loop
            return slow;  
        }
    }
    
     // If no loop is found, return NULL
    return NULL; 
}
