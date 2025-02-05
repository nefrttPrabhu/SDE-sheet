int sizeOfBinaryTree(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftSize = sizeOfBinaryTree(root->left);
    int rightSize = sizeOfBinaryTree(root->right);
    
    return leftSize + rightSize + 1;
}
