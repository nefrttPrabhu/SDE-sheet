#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertAtFront(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

Node* insertAtIndex(Node* head, int val, int idx) {
    if (idx == 0) return insertAtFront(head, val);

    Node* temp = head;
    for (int i = 0; temp && i < idx - 1; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Index out of range.\n";
        return head;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node* deleteFromEnd(Node* head) {
    if (!head) return NULL;
    if (!head->next) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    return head;
}

Node* deleteFromFront(Node* head) {
    if (!head) return NULL;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteAtIndex(Node* head, int idx) {
    if (!head) return NULL;
    if (idx == 0) return deleteFromFront(head);

    Node* temp = head;
    for (int i = 0; temp->next && i < idx - 1; i++) {
        temp = temp->next;
    }

    if (!temp->next) {
        cout << "Index out of range.\n";
        return head;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    return head;
}

Node* reverseList(Node* head) {
    if (!head || !head->next) return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    Node* head = NULL;
    int choice, val, idx;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Create/Add Node at End\n";
        cout << "2. Insert at Front\n";
        cout << "3. Insert at Index\n";
        cout << "4. Delete from End\n";
        cout << "5. Delete from Front\n";
        cout << "6. Delete at Index\n";
        cout << "7. Reverse the List\n";
        cout << "8. Print the List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add: ";
            cin >> val;
            head = insertAtEnd(head, val);
            break;

        case 2:
            cout << "Enter value to insert at front: ";
            cin >> val;
            head = insertAtFront(head, val);
            break;

        case 3:
            cout << "Enter index and value: ";
            cin >> idx >> val;
            head = insertAtIndex(head, val, idx);
            break;

        case 4:
            head = deleteFromEnd(head);
            break;

        case 5:
            head = deleteFromFront(head);
            break;

        case 6:
            cout << "Enter index to delete: ";
            cin >> idx;
            head = deleteAtIndex(head, idx);
            break;

        case 7:
            head = reverseList(head);
            break;

        case 8:
            cout << "Current List: ";
            print(head);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
