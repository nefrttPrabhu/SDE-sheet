/*
  there is a huge difference between redundant and unbalanced expression
  Before proceeding to redundant we need to check if the expression is balanced or not as this it invalid to operate on an unbalanced expression
  coz an it is vague to operate as we dont know that 
  The question arises why the expression has opening bracket: What does this parenthesis group? Does it continue further, or was it meant to close after b?
  The question arises why the expression has closing bracket: What was supposed to be grouped here? Did the expression start earlier, or is this a mistake?
  When parentheses are unbalanced:
  The meaning of the expression becomes ambiguous.
  It is logically invalid and cannot be processed or simplified correctly until the missing parentheses are added or the extra ones are removed to balance the expression.

  Differences in Key Properties
  Property	           |        Redundant Expression           |	  Unbalanced Expression
  Parentheses Balanced |	              Yes                    |              No
  Evaluation Possible	 |                Yes                    |             	No
  Logical Structure    | Includes unnecessary PAIR of brackets | 	Has mismatched parentheses
  Example              |     	       ((a + b))                 |            (a + b
*/

#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expression) {
    stack<char> st;
    for (char ch : expression) {
        if (ch == '(') {
            st.push(ch);
        } 
        else if (ch == ')') 
        {
            if (st.empty()) {
                return false; // More closing brackets than opening ie unbalanced
            }
            st.pop(); // matching opening mil gya closing ka
        }
    }
    return st.empty(); // Stack should be empty if balanced
}

bool hasRedundantBrackets(string expression) {
    stack<char> st;

    for (char ch : expression) {
        if (ch == ')') 
        {
            bool isRedandant = true;
            while (!st.empty() && st.top() != '(') //jab tak opening nhi aata seach karte rho tab tak jab tak stack empty nhi hota
            {
                char top = st.top();
                st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedandant = false;
                }
            }
            if (!st.empty()) {
                st.pop(); // Remove the opening parenthesis '('
            }
            if (isRedandant) {
                return true; // Redundant brackets found
            }
        }
        else {
            st.push(ch); // Push all other characters until closing is not attained
        }
    }//for
    return false; // No redundant brackets found
}

int main() {
    string expression;
    cout << "Enter the expression: ";
    cin >> expression;

    if (!isBalanced(expression)) {
        cout << "The expression has unbalanced parentheses.\n";
    } else if (hasRedundantBrackets(expression)) {
        cout << "The expression contains redundant brackets.\n";
    } else {
        cout << "The expression does not contain redundant brackets.\n";
    }

    return 0;
}
