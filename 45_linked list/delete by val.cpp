void deleteByValue(Node* &head, int val) {
    // Handle edge case: Empty list
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Handle the case where the value is in the head node
    if (head->data == val) { //idhar temp->data se bhi check kar sakte the but aise kiya coz mature move hi thats all 
        head = head->next; // Update the head
        delete temp;       // Free pointer as temp faltu mai he ignored value ko point karta rhega idhar bhi value kabhi nhi delete hoti hi bus uska acess hamesha ke liye kho jata hi to vo by default he delete maan li jati hi coz value delete jaisa koi concept nhi hota hi
        return;
    }

    // Traverse the list to find the node with the target value
    while (temp != NULL && temp->data != val) {
        prev = temp;        // Track the previous node
        temp = temp->next;  // Move to the next node
    }

    // If the value is not found
    if (temp == NULL) {
        cout << "Value not found in the list." << endl;
        return;
    }

    // Update the links and delete the node, ye neeche wali lines only tabhi execute hongi jab pata hoga ki temp pura exhauste nhi hua ya fir value jo delete karni hi vo 1st nhi
    prev->next = temp->next;
    delete temp;
}
