#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    node* left;
    node* right;
    int data;

    // Constructor to initialize the node
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to create a binary tree
void create() {
    queue<node*> q; // Queue to store pointers to nodes
    int x;
    cin >> x;

    if (x == -1) return; // If input is -1, tree does not exist

    node* root = new node(x); // Create the root node
    q.push(root); // Push the root into the queue

    while (!q.empty()) {
        node* temp = q.front(); // Get the front node
        q.pop();

        // Input for the left child
        int l;
        cin >> l;
        if (l != -1) {
            temp->left = new node(l);
            q.push(temp->left);
        }

        // Input for the right child
        int r;
        cin >> r;
        if (r != -1) {
            temp->right = new node(r);
            q.push(temp->right);
        }
    }
}
