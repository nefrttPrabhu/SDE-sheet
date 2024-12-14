/*
            1
           / \
          2   3
           \
            5
        The output: 5 2 3 1
*/


void postorder(node* root) {
    if (root == NULL) // Base condition to stop recursion
        return;

    postorder(root->left);       // Traverse the left subtree first
    postorder(root->right);      // Then traverse the right subtree
    cout << root->data << " ";   // Visit the current node
}
