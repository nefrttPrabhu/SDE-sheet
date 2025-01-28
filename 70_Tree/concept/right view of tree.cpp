void printRightView(Node* root) {
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();
        
        // Traverse all nodes at the current level
        Node* node = NULL;
        while (n--) {
            node = q.front();
            q.pop();
            
            // Enqueue left and right children
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        // Print the rightmost node of the current level
        cout << node->data << " ";
    }
}
