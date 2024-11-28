/*
          1
         / \
        2   3
         \
          5
      output: 2 5 1 3
*/

void inorder(node* root) {
    if (root == NULL) // Base condition to stop recursion
        return;

    inorder(root->left);       // Traverse the left subtree first
    cout << root->data << " "; // Visit the current node
    inorder(root->right);      // Traverse the right subtree
}

