int nonleaf(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) //root==null means aage koi node he nhi hi  && left==null&&right==null means node hi but uske koi left right mai kuch nhi hi ab
        return 0;                                                    //(root == NULL). Without this check, the code will fail if called on an empty tree.
    return (1 + nonleaf(root->left) + nonleaf(root->right));
}

int nonleaf(Node* root) {
    // Base case: Handle empty tree
    if (root == NULL) {
        return 0;
    }

    // Base case: If it's a leaf node, return 0
    if (root->left == NULL && root->right == NULL) { 
        return 0;
    }

    // Recursive case: Count the current node as non-leaf and proceed to children
    return (1 + nonleaf(root->left) + nonleaf(root->right));
}
