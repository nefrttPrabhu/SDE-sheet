/*
  M1: brute force 
  S1: get all the node values stored in array
  S2: sort the array 
  S3: overwrite the elements of the LL
*/
Node* sortLL(Node* head){
    vector<int> arr;
    Node* temp = head;    // Temporary pointer to & traverse the linked list
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end()); // Sort the array & containing node values
    temp = head;     // Reassign sorted values to & the linked list nodes
    for(int i = 0; i < arr.size(); i++){
        temp->data = arr[i];  // Update the node's data & with the sorted values
        temp = temp->next;  // Move to the next node
    }
    return head;     // Return the head of the & sorted linked list
}



//M2: optimal extensive use of pointers only using a dummy node
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next; 
    }
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    return dummyNode->next;
}



//M3:
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
Node* head, *h1, *h2; // Corrected pointer declarations with proper initialization
if (t1->data < t2->data) {
    head = t1;
    h1 = t1; // Corrected: Assign h1 to t1 to keep track of list1
    t1 = t1->next;
    h1->next = t2; // Corrected: Use -> instead of . for accessing members of a pointer
} else {
    head = t2;
    h2 = t2; // Corrected: Assign h2 to t2 to keep track of list2
    t2 = t2->next;
    h2->next = t1; // Corrected: Use -> instead of . for accessing members of a pointer
}

// Remaining list
while (t1 != nullptr && t2 != nullptr) { // Corrected: Use nullptr instead of null
    if (t1->data < t2->data) {
        Node* temp = t1->next; // Declared temp as Node* for type safety
        t1->next = t2;         // Corrected: Use -> instead of .
        t1 = temp;
    } else {
        Node* temp = t2->next; // Declared temp as Node* for type safety
        t2->next = t1;         // Corrected: Use -> instead of .
        t2 = temp;
    }
}

// dono lists mai se koi bhi ek bach gyi even if anyone get exhausted
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }

  return head;
}


