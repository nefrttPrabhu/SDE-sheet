t1 = head;   // Initialize t1 to point to the head
t3 = NULL;   // Initialize t3 as NULL (previous pointer)
t4 = t1->next; // Initialize t4 to the second node in the list
t2 = NULL;   // Initialize t2 as NULL
int c = 1;   // Start with c = 1

while (t4 != NULL) {
    if (c == 1) {
        c--;                // Decrement c
        t2 = t1;            // Set t2 to point to t1
        t4 = t2->next;      // Move t4 to the next node
        t1->next = t3;      // Reverse the link for t1
        t3 = t2;            // Move t3 forward to t2
    } else {
        c++;                // Increment c
        t3 = t4->next;      // Store the next node of t4 in t3
        t1 = t4;            // Move t1 forward to t4
        t4->next = t2;      // Reverse the link for t4
        t2 = t1;            // Move t2 forward to t1
        t4 = t3;            // Move t4 forward to the next node
    }
}

head = t1; // Update head to the new first node after reversal
