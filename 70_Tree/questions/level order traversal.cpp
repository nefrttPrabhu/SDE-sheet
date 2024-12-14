vector<int> ans(Node* root) {
    if (!root) return {};  // Handle edge case where the root is null

    queue<Node*> q;
    q.push(root);
    vector<int> ans;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        ans.push_back(temp->data);// Add the current node's data to the result

        // Push the left and right children if they exist
        if (temp->left) //no need to write temp->left->data!=-1 as already written is enough as if there exist the address it will be an numerical data but of not then node ends with null due to which if will become false and terminate
        {
            q.push(temp->left);
        }
      
        if (temp->right) 
        {
            q.push(temp->right);
        }
    }
    return ans;
}
