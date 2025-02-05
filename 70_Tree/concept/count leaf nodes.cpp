int countLeafNodes(Node* root) {
    if (root == nullptr) 
        return 0;
    
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

