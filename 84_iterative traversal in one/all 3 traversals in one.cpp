class Solution {
public:
    vector<vector<int>> treeTraversals(TreeNode* root) {
        // Vectors to store the three types of traversals
        vector<int> pre, in, post;
        if (root == NULL) return {pre, in, post}; // If tree is empty, return empty traversals

        // Stack to simulate recursive traversal
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1}); // Initial state: root node with "stage" 1

        while (!st.empty()) {
            auto it = st.top(); // Peek the top of the stack
            st.pop();           // Pop it for processing

            // Stage 1: Process as part of preorder
            if (it.second == 1) {
                pre.push_back(it.first->val); // Add the node value to preorder
                it.second++;                  // Move to the next stage
                st.push(it);                  // Push the node back with updated stage

                // Push the left child (if exists) with stage 1
                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }
            // Stage 2: Process as part of inorder
            else if (it.second == 2) {
                in.push_back(it.first->val); // Add the node value to inorder
                it.second++;                 // Move to the next stage
                st.push(it);                 // Push the node back with updated stage

                // Push the right child (if exists) with stage 1
                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }
            // Stage 3: Process as part of postorder
            else {
                post.push_back(it.first->val); // Add the node value to postorder
                // No need to push the node back; it's fully processed
            }
        }

        // Return the three traversals
        return {pre, in, post};
    }
};
