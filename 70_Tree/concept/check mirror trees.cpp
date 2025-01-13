//S1 non recursive
// Function to check if two trees are mirrors (iterative)
bool areMirrors(Node* root1, Node* root2) {
    // If both roots are NULL, they are mirrors
    if (!root1 && !root2) return true;

    // If only one of them is NULL, they are not mirrors
    if (!root1 || !root2) return false;

    // Create two queues for level order traversal
    queue<Node*> q1, q2;

    // Push roots of both trees
    q1.push(root1);
    q2.push(root2);

    // Loop until both queues are empty
    while (!q1.empty() && !q2.empty()) {
        // Extract nodes from both queues
        Node* node1 = q1.front();
        Node* node2 = q2.front();
        q1.pop();
        q2.pop();

        // Check if the data of the two nodes is different
        if (node1->data != node2->data) return false;

        // Push children into the queues in opposite order
        // For node1: left first, then right
        // For node2: right first, then left
        if (node1->left && node2->right) {
            q1.push(node1->left);
            q2.push(node2->right);
        } else if (node1->left || node2->right) {
            // If one has a child and the other does not
            return false;
        }

        if (node1->right && node2->left) {
            q1.push(node1->right);
            q2.push(node2->left);
        } else if (node1->right || node2->left) {
            // If one has a child and the other does not
            return false;
        }
    }

    // If both queues are empty, they are mirrors
    return q1.empty() && q2.empty();
}


//S2: recursive 
// Function to check if two trees are mirrors
bool areMirrors(Node* root1, Node* root2) {
    // Base case: If both nodes are NULL, they are mirrors
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // If one node is NULL and the other isn't, they are not mirrors
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Check:
    // 1. Data at the two nodes is the same
    // 2. Left subtree of root1 is a mirror of the right subtree of root2
    // 3. Right subtree of root1 is a mirror of the left subtree of root2
    return (root1->data == root2->data) &&
           areMirrors(root1->left, root2->right) &&
           areMirrors(root1->right, root2->left);
}
