#include <iostream>
using namespace std;

// Define a node for the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) { // Constructor to initialize a new node
        data = val;
        next = nullptr;
    }
};

// Define the stack class
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;
    }

    // Push operation to add an element to the stack
    void push(int val) {
        Node* newNode = new Node(val); // Create a new node
        newNode->next = top;          // Link the new node to the current top
        top = newNode;                // Update the top pointer
    }

    // Pop operation to remove and return the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return an error value
        }

        int val = top->data;  // Get the data from the top node
        Node* temp = top;     // Save the top node
        top = top->next;      // Update the top pointer
        delete temp;          // Free the memory of the removed node
        return val;
    }

    // Peek operation to get the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return an error value
        }
        return top->data; // Return the data at the top node
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display the elements of the stack
    void displayStack() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Main function to test the stack implementation
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.displayStack(); // Output: Stack elements: 30 20 10

    cout << "Top element: " << s.peek() << endl; // Output: Top element: 30

    cout << "Popped element: " << s.pop() << endl; // Output: Popped element: 30
    s.displayStack(); // Output: Stack elements: 20 10

    cout << "Popped element: " << s.pop() << endl; // Output: Popped element: 20
    cout << "Popped element: " << s.pop() << endl; // Output: Popped element: 10
    cout << "Popped element: " << s.pop() << endl; // Output: Stack is empty

    return 0;
}
