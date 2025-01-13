//M1: brute force use stack to get elements then match each element with from the start as stack has last in first out tmep will rum from start and stack will pop from the last element 1st
// Function to check if a linked list is a palindrome using a stack
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true; // A single-node or empty list is a palindrome

    stack<int> s;
    ListNode* temp = head;

    // Step 1: Push all elements of the linked list onto the stack
    while (temp) {
        s.push(temp->val);
        temp = temp->next;
    }

    // Step 2: Traverse the list again and compare each node's value with the stack's top
    temp = head;
    while (temp) {
        if (temp->val != s.top()) {
            return false; // Mismatch found
        }
        s.pop();
        temp = temp->next;
    }

    return true; // All values matched
}


/*
M2: optimal 
S1: slow fast ka use karke list ke mid tak jao and list ko half mai todo 
S2: next half ko reverse karo 
S3: firse new pointers banao dono lists ko 1st ie for 1st half with the original head and 2nd ie for the 2nd half with the newhead pointers se check karo ek ek node ko
*/
// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Step 1: Find the middle of the linked list
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the linked list
    ListNode* secondHalf = reverseList(slow);
    ListNode* firstHalf = head;

    // Step 3: Compare the two halves
    ListNode* temp = secondHalf;
    bool isPalin = true;
    while (temp) {
        if (firstHalf->val != temp->val) {
            isPalin = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    // Step 4: Restore the original linked list (optional)
    reverseList(secondHalf);

    return isPalin;
}

// Utility function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy->next;
}

