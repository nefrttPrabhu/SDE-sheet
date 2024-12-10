#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 100; // Define maximum size for the queue
int arr[MAX_SIZE];        // Array to store the queue elements
int start = -1;           // Front pointer
int end = -1;             // Rear pointer
int curr = 0;             // Current size of the queue

// Push function to insert an element into the queue
void push(int val) {
    if (curr == MAX_SIZE) {
        cout << "Queue is full" << endl;
        return;
    }

    if (curr == 0) {
        start = 0; // Initialize start when the first element is added
        end = 0;
    } else {
        end = (end + 1) % MAX_SIZE; // Update end in circular manner
    }

    arr[end] = val; // Insert the new value
    curr++;         // Increment the size
}

// Pop function to remove and return an element from the front of the queue
int pop() {
    if (curr == 0) {
        cout << "Queue is empty" << endl;
        return -1; // Return an error value
    }

    int element = arr[start]; // Store the element to return

    if (curr == 1) { // Reset pointers if the queue becomes empty
        start = -1;
        end = -1;
    } else {
        start = (start + 1) % MAX_SIZE; // Move start in a circular manner
    }

    curr--; // Decrement the size
    return element;
}

// Utility function to display the queue
void displayQueue() {
    if (curr == 0) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = 0; i < curr; i++) {
        cout << arr[(start + i) % MAX_SIZE] << " ";
    }
    cout << endl;
}

// Main function to test the queue implementation
int main() {
    push(10);
    push(20);
    push(30);
    displayQueue(); // Output: Queue elements: 10 20 30

    cout << "Popped element: " << pop() << endl; // Output: Popped element: 10
    displayQueue(); // Output: Queue elements: 20 30

    push(40);
    displayQueue(); // Output: Queue elements: 20 30 40

    return 0;
}
