/*
        1
       / \
      2   3
     / \
    4   5
output: 1 2 3 5 3

*/


void preorder(node* root) // node left right jiski jitni importance utna phle vo as per the name here we have pre: node highest then left then right 
{
    if(node==NULL) // recusrion se pura tree traverse kar rhe
    return node;
    cout << root->val << " "; 
    preorder(node->left); // pura traverse jabtak null nhi milta
    preorder(node->right); // pura left traverse hone ke baad right pura jabtak null nhi milta
}
