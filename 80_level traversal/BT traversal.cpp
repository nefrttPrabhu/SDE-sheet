class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
{
        vector<vector<int>> ans; // To store the final result
        if (root == NULL) return ans; // If root is NULL, return an empty vector
        
        queue<TreeNode*> q; // Queue to facilitate level-order traversal
        q.push(root); // Start with the root node
        
        while (!q.empty()) // While there are nodes to process
        { 
            int size = q.size(); // Get the number of nodes at the current level
            vector<int> level; // Temporary vector to store values of the current level
            
            for (int i = 0; i < size; i++)  // Process all nodes at the current level
            {
                TreeNode* node = q.front(); // Get the front node in the queue
                q.pop(); // Remove it from the queue
                level.push_back(node->val); // Add the node's value to the current level vector
                
                // If the node has a left child, add it to the queue
                if (node->left != NULL) q.push(node->left);
                // If the node has a right child, add it to the queue
                if (node->right != NULL) q.push(node->right);
            }
            
            ans.push_back(level); // Add the current level to the final result
        }
        
        return ans; // Return the level order traversal
    }
};
