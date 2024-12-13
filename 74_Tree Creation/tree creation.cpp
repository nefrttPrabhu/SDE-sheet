// Online C++ compiler to run C++ program online
/* OUTPUT
                    Tree structure:
                        1
                       / \
                      2   3
                       \
                        5
*/

#include <iostream>
using namespace std;
class Node // struct type a data coz koi bhi type a data types ko store kar sakta hi 
{
    int data; // int type stored hi 
    Node* left; //pointer type stored hi
    Node* right; //pointer type stored hi
    
    Node(int val) // constructor
    {
        data = val;         // Assigns the provided value to the node's data field. ye store karega node ki value bina dekhe right hi ya left coz uski jankari left right pointers rakhenge
        left = NULL;        // Initializes the left child to NULL (no child yet). ye store kar rhe ki growth left side hi 
        right = NULL;       // Initializes the right child to NULL (no child yet). ye store kar rhe ki growth right side hi 
        // left and right pointers to NULL since the new node doesn't have children initially i.e vo kahan or kisko point karenge
    }
};

int main() {
    // Creating the root node with value 1
    Node* root = new Node(1); // root node define kiya hi with value and ye call kar rha node constructor ko 

    // Adding children to the root
    root->left = new Node(2); //apne se new node create kiya hi, root se start hoke left ki side grow karna
    root->right = new Node(3); // apne se right node create kiya hi, root se start hoke right ki side grow karna

    // Adding a child to the left node
    root->left->right = new Node(5); // apne se left ke right node ko value assign kari hi waise he karte jao as per our need
}







