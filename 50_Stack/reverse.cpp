#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int element) //I1:( ,1) I2:(1,2) I3:(21,3) I4:(321,4) I5:(4321,5)    // Insert 1 at Bottom: Stack becomes [1].
{                                                                                                       // Insert 2 at Bottom: Stack = [1]
    if (s.empty()) {                                                                                    //                     Pops 1, inserts 2, then pushes 1 back
        s.push(element);                                                                                //                     Stack becomes [2, 1]
        return;                                                                                         // Insert 3 at Bottom: Stack = [2, 1]
    }                                                                                                   //                     Pops 1, 2, inserts 3, then pushes 2, 1 back
                                                                                                        //                     Stack becomes [3, 2, 1]
    int topElement = s.top();                                                                           // Insert 4 at Bottom: Stack = [3, 2, 1]
    s.pop();                                                                                            //                     Pops 1, 2, 3, inserts 4, then pushes 3, 2, 1 back
    insertAtBottom(s, element);                                                                         //                     Stack becomes [4, 3, 2, 1]
                                                                                                        // Insert 5 at Bottom: Stack = [4, 3, 2, 1]
    s.push(topElement);                                                                                 //                     Pops 1, 2, 3, 4 inserts 5, then pushes 4, 3, 2, 1 back
}                                                                                                       //                     Stack becomes [5, 4, 3, 2, 1]
                                                                                                        // I1:( ,1) I2:(1,2) I3:(21,3) I4:(321,4) I5:(4321,5) ye jitni iterations hi utni baar chalega ye insert ka fng coz reverse sabka top kaat rha tha tab tak insert reducing stack and new tops ke sath wait kar rha tha
void reverseStack(stack<int> &s) //I1:54321, I2:4321, I3:321, I4:21, I5:1
{
    if (s.empty()) {
        return;
    }

    int topElement = s.top(); //5 , 4 , 3 , 2 , 1 
    s.pop(); //4321, 321, 21, 1
    reverseStack(s); //I1:4321, I2:321, I3:21, I4:1 ye chota karta jayega stack ko coz neeche insert fng vo choti choti list ko leta jayega then 

    insertAtBottom(s, topElement); //I1:(4321,5) I2:(321,4) I3:(21,3) I4:(1,2) I5:( ,1) 1st execution will take for I5->I4->I3->I2->I1
}

// Helper function to print the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Main function
int main() {
    stack<int> s;

    // Input values into the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // s=[5,4,3,2,1] top element=5

    cout << "Original stack: ";
    printStack(s);     // s=[5,4,3,2,1] top element=5

    // Reverse the stack
    reverseStack(s);     // s=[5,4,3,2,1] top element=5

    cout << "Reversed stack: ";
    printStack(s);    // s=[1,2,3,4,5] top element=1

    return 0;
}

