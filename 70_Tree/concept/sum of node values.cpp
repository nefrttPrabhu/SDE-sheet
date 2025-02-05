int sumOfNodes(Node* root) {
    if (root == nullptr)
        return 0;
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}
