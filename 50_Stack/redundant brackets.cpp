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

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        // Push opening bracket or operator to the stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            st.push(ch);
        } 
        else {
            if (ch == ')') {
            // Check for redundancy
            bool isRedundant = true;

            // Pop elements until an opening bracket is found
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();

                // If an operator is found, the brackets are not redundant
                if (top == '+' || top == '-' || top == '*' || top == '/' || top == '%') {
                    isRedundant = false;
                }
            }

            // Pop the opening bracket
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }

            // If no operator was found, the brackets are redundant
            if (isRedundant) {
                return true;
            }
        }
    }
    }
    // If we finish processing and no redundant brackets are found
    return false;
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
