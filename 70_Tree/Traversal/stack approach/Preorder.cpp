
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder; // To store the result of preorder traversal
        if (root == NULL) return preorder; // If root is NULL, return an empty vector
        
        stack<TreeNode*> st; // Stack to facilitate iterative traversal
        st.push(root); // Start with the root node
        
        while (!st.empty()) { // While there are nodes in the stack
            root = st.top(); // Get the top node of the stack
            st.pop(); // Remove it from the stack
            
            preorder.push_back(root->val); // Add the node's value to the preorder vector
            
            // Push the right child first, so the left child is processed first (LIFO order)
            if (root->right != NULL) st.push(root->right);
            if (root->left != NULL) st.push(root->left);
        }
        
        return preorder; // Return the preorder traversal
    }
};
