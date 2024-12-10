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

// Define the queue class
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation to add an element to the rear of the queue
    void enqueue(int val) {
        Node* newNode = new Node(val); // Create a new node
        if (rear == nullptr) {        // If the queue is empty
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode; // Link the new node to the end of the queue
            rear = newNode;       // Update the rear pointer
        }
    }

    // Dequeue operation to remove and return an element from the front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // Return an error value
        }

        int val = front->data; // Get the data of the front node
        Node* temp = front;    // Save the front node
        front = front->next;   // Update the front pointer

        if (front == nullptr) { // If the queue becomes empty
            rear = nullptr;
        }

        delete temp; // Free the memory of the removed node
        return val;
    }

    // Peek operation to get the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // Return an error value
        }
        return front->data; // Return the data at the front node
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display the elements of the queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function to test the queue implementation
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.displayQueue(); // Output: Queue elements: 10 20 30

    cout << "Front element: " << q.peek() << endl; // Output: Front element: 10

    cout << "Dequeued element: " << q.dequeue() << endl; // Output: Dequeued element: 10
    q.displayQueue(); // Output: Queue elements: 20 30

    cout << "Dequeued element: " << q.dequeue() << endl; // Output: Dequeued element: 20
    cout << "Dequeued element: " << q.dequeue() << endl; // Output: Dequeued element: 30
    cout << "Dequeued element: " << q.dequeue() << endl; // Output: Queue is empty

    return 0;
}
