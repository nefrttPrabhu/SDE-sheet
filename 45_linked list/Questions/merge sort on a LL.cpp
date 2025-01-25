// Definition for singly-linked list node.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    // If either of the lists is empty, return the other
    if (!left) return right;
    if (!right) return left;

    // Recursively merge the two sorted lists
    if (left->data < right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

// Function to split the linked list into two halves
Node* findMiddle(Node* head) {
    if (!head) return nullptr;
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to sort the linked list using Merge Sort
Node* mergeSort(Node* head) {
    // Base case: if the list is empty or has one element, it's already sorted
    if (!head || !head->next) return head;

    // Split the list into two halves
    Node* mid = findMiddle(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;

    // Recursively sort the two halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    return merge(left, right);
}

// Wrapper function to call mergeSort
Node* sortLL(Node* head) {
    return mergeSort(head);
}
