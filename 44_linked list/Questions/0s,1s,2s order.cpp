/* Something new 
   New 1: no need to create dummy node for storing just changing the links of the given LL
   New 2: no need to take care if 0 1 2 any of these exists

*/

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
        temp = temp->next; // ye temp agar hum ek ek if else mai bhi likhte toh bhi sahi hota coz input he 0 1 2 mai hoga but its just for good practice
    }
    
    
    // Link the three lists together: 0's -> 1's -> 2's
    z->next = (ones->next) ? ones->next : twos->next;  // Link 0's list to 1's list idhar bus ye check karne ke liye if maan lo ek bhi 1 nhi hi ya ek bhi 2 nhi hi 
    o->next = twos->next;  // Link 1's list to 2's list
    // Terminate the list of twos to avoid a cycle
    t->next = NULL;
    
    // Return the new list starting from the first node after the dummy node
    return zeros->next;
}
