//M1: brute force
// function to detect loop in linked list
bool detectLoop(Node* head) {
    
    // Initialize a pointer 'temp'
    // at the head of the linked list
    Node* temp = head;  
    
    // Create a map to keep track of
    // encountered nodes
    std::unordered_map<Node*, int> nodeMap;  

    // Step 2: Traverse the linked list
    while (temp != nullptr) {
        // If the node is already in the
        // map, there is a loop
        if (nodeMap.find(temp) != nodeMap.end()) {
            return true;
        }
        // Store the current node
        // in the map
        nodeMap[temp] = 1;
        
        // Move to the next node
        temp = temp->next;  
    }

    // Step 3: If the list is successfully traversed 
    // without a loop, return false
    return false;
}




//M2: optimal 
// Function to detect a loop in a linked
// list using the Tortoise and Hare Algorithm
bool detectCycle(Node* head) {
    // Initialize two pointers, slow and fast,
    // to the head of the linked list
    Node* slow = head;
    Node* fast = head;

    // Step 2: Traverse the linked list with
    // the slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;
        // Move fast two steps
        fast = fast->next->next;

        // Check if slow and fast pointers meet
        if (slow == fast) {
            return true;  // Loop detected
        }
    }

    // If fast reaches the end of the list,
    // there is no loop
    return false;
}
