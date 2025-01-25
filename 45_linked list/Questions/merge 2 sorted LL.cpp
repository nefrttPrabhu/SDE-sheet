//M1: optimal extensive use of pointers only using a dummy node
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



//M2:
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    Node* head = nullptr, *h1 = nullptr, *h2 = nullptr; 
    Node *t1 = list1, *t2 = list2;  // Define t1 and t2 for traversal
    
    if (t1 && t2) { // Check if both lists are non-empty
        if (t1->data < t2->data) {
            head = t1;
            h1 = t1; // Assign h1 to t1 to keep track of list1
            t1 = t1->next;
            h1->next = t2; // Link h1 to t2 to continue merging
        } else {
            head = t2;
            h2 = t2; // Assign h2 to t2 to keep track of list2
            t2 = t2->next;
            h2->next = t1; // Link h2 to t1 to continue merging
        }
    } else {
        // Handle the case where one of the lists is initially empty
        return (t1 != nullptr) ? t1 : t2;
    }

    // Merge remaining nodes
    Node* temp = nullptr;
    while (t1 != nullptr && t2 != nullptr) {
        if (t1->data < t2->data) {
            temp = t1->next; // Store the next node
            t1->next = t2;   // Link t1 to t2
            t1 = temp;       // Move t1 to the next node
        } else {
            temp = t2->next; // Store the next node
            t2->next = t1;   // Link t2 to t1
            t2 = temp;       // Move t2 to the next node
        }
    }

    // If one list is exhausted, attach the remaining part of the other list
    if (t1 != nullptr) {
        temp->next = t1; // Link the last node to the remaining list
    } else {
        temp->next = t2; // Link the last node to the remaining list
    }

    return head;
}


