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

// Function to find the middle of a linked list
Node* findMiddle(Node* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Initializing slow and fast pointers
    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to perform merge sort on a linked list
Node* sortLL(Node* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* middle = findMiddle(head);
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;
    
    left = sortLL(left);
    right = sortLL(right);
    
    return mergeTwoSortedLinkedLists(left, right);
}
