/*
S1. define queue
S2. create a visited array
S3. adjecency list
*/
    // Function to return Breadth First Traversal of given graph.
    vector<int> BFS(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;

        q.push(0); // gets the 1st node of the graph
        vector<int> bfs; 
      
        while(!q.empty())// iterate till the queue is empty 

        {
            int node = q.front(); // get the topmost element in the queue
            q.pop(); // node mai store kar liya then q ke top se pop kar diya
            bfs.push_back(node); //wahi fir bfs jo output chahiye usmai dla diya
            
            for(auto it : adj[node]) // traverse for all its neighbours and ye list given hoti hi 
            {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};




//M2:
void BFS(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    vector<int> bfs_result;

    q.push(root);
    
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        
        bfs_result.push_back(node->data); // Store node value instead of pointer
        
        if (node->left)  q.push(node->left);  // Push left child first
        if (node->right) q.push(node->right); // Push right child next
    }
}
