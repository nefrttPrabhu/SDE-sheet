int height(Node* root) {
    if (root == nullptr)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}
