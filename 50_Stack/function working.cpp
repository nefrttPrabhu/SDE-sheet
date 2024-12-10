#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack
int arr[MAX_SIZE];        // Array to store stack elements
int top = -1;             // Top pointer to track the stack

// Push operation to add an element to the stack
void push(int val) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack is full" << endl;
        return;
    }
    top++;           // Increment the top pointer
    arr[top] = val;  // Add the element to the stack
}

// Pop operation to remove the top element from the stack
int pop() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return -1; // Return an error value
    }
    int val = arr[top]; // Get the top element
    top--;              // Decrement the top pointer
    return val;
}

// Peek operation to get the top element without removing it
int peek() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return -1; // Return an error value
    }
    return arr[top]; // Return the top element
}

// Utility function to display the stack
void displayStack() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function to test the stack implementation
int main() {
    push(10);
    push(20);
    push(30);
    displayStack(); // Output: Stack elements: 10 20 30

    cout << "Top element: " << peek() << endl; // Output: Top element: 30

    cout << "Popped element: " << pop() << endl; // Output: Popped element: 30
    displayStack(); // Output: Stack elements: 10 20

    cout << "Popped element: " << pop() << endl; // Output: Popped element: 20
    cout << "Popped element: " << pop() << endl; // Output: Popped element: 10
    cout << "Popped element: " << pop() << endl; // Output: Stack is empty

    return 0;
}


/*
Push Operation: O(1)
Before pushing an element, check if the stack is full (top >= MAX_SIZE - 1).
Increment top and add the element to arr[top].

Pop Operation: O(1)
Before popping, check if the stack is empty (top == -1).
Retrieve the element at arr[top], decrement top, and return the popped element.

Peek Operation: O(1)
Allows you to look at the top element without removing it.
Check if the stack is empty before accessing the top element.

Display Stack: O(n)
Iterate through the stack from the bottom (arr[0]) to the top (arr[top]) and print each element.

Edge Cases:
Handle stack overflow in push by printing "Stack is full."
Handle stack underflow in pop by printing "Stack is empty."

*/
