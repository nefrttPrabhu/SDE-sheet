class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder; // To store the result of inorder traversal
        stack<TreeNode*> st; // Stack to manage traversal
        TreeNode* node = root; // Start with the root node
        
        while (true) {
            if (node != NULL) {
                // Push the current node onto the stack and move to its left child
                st.push(node);
                node = node->left;
            } else {
                // If the stack is empty, we are done
                if (st.empty()) break;
                
                // Process the node at the top of the stack
                node = st.top();
                st.pop();
                inorder.push_back(node->val); // Add the node's value to the result
                
                // Move to the right child of the node
                node = node->right;
            }
        }
        
        return inorder; // Return the inorder traversal
    }
};
