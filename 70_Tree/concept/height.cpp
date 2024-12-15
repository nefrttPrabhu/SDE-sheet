int nonleaf(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) //root==null means aage koi node he nhi hi  && left==null&&right==null means node hi but uske koi left right mai kuch nhi hi ab
        return 0;
    return (1 + nonleaf(root->left) + nonleaf(root->right));
}
