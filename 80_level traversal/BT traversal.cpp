/*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
{
        vector<vector<int>> ans; // To store the final result
        if (root == NULL) 
            return ans; // If root is NULL, return an empty vector
        
        queue<TreeNode*> q; // Queue to facilitate level-order traversal
        q.push(root); // Start with the root node
        
        while (!q.empty()) // While there are nodes to process
        { 
            int size = q.size(); // Get the number of nodes at the current level
            vector<int> level; // Temporary vector to store values of the current level jo ans mai add karta jayega
            
            for (int i = 0; i < size; i++)  // Process all nodes at the current level
            {
                TreeNode* node = q.front(); // Get the front node in the queue
                q.pop(); // Remove it from the queue
                level.push_back(node->val); // Add the node's value to the current level vector
                
                if (node->left != NULL) 
                    q.push(node->left); // If the node has a left child, add it to the queue
                
                if (node->right != NULL) 
                    q.push(node->right); // If the node has a right child, add it to the queue
                // ye dono if he reason hi for the size's size yahi q mai push karte ja rhe left and right childs of the parent nodes
                // I1: size=1 due to node =   [1]    =level 1
                // I2: size=2 due to node =  [2,3]   =level 2
                // I3: size=4 due to node =[4,5,6,7] =level 3
                
            }
            ans.push_back(level); // Add the current level to the final result ->[1]->[2,3]->[4,5,6,7]
        }
        return ans; // Return the level order traversal
    }
};
