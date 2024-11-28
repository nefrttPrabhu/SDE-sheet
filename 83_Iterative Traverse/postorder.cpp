// using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder; // To store the postorder traversal result
        if (root == NULL) return postorder; // If the tree is empty, return an empty vector
        
        stack<TreeNode*> st1, st2; // Two stacks for the traversal
        st1.push(root); // Push the root node onto the first stack
        
        while (!st1.empty()) {
            TreeNode* node = st1.top(); // Get the top node of st1
            st1.pop(); // Remove it from st1
            st2.push(node); // Push it onto st2
            
            // Push the left child of the node onto st1, if it exists
            if (node->left != NULL) st1.push(node->left);
            
            // Push the right child of the node onto st1, if it exists
            if (node->right != NULL) st1.push(node->right);
        }
        
        // Collect values from st2 in postorder sequence
        while (!st2.empty()) {
            postorder.push_back(st2.top()->val); // Add the value of the top node in st2
            st2.pop(); // Remove the node from st2
        }
        
        return postorder; // Return the postorder traversal result
    }
};


// using 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder; // To store the traversal result
        if (root == NULL) return postorder; // Return empty vector if tree is empty
        
        stack<TreeNode*> st; // Single stack for traversal
        TreeNode* lastVisited = NULL; // Pointer to keep track of the last visited node
        TreeNode* current = root; // Start from the root node
        
        while (!st.empty() || current != NULL) {
            if (current != NULL) {
                // Traverse to the leftmost node and push nodes onto the stack
                st.push(current);
                current = current->left;
            } else {
                // Peek the top node in the stack
                TreeNode* topNode = st.top();
                
                // If the right subtree exists and hasn't been visited yet, move to the right
                if (topNode->right != NULL && lastVisited != topNode->right) {
                    current = topNode->right;
                } else {
                    // Process the current node and pop it from the stack
                    postorder.push_back(topNode->val);
                    st.pop();
                    lastVisited = topNode; // Mark this node as visited
                }
            }
        }
        
        return postorder; // Return the postorder traversal
    }
};
