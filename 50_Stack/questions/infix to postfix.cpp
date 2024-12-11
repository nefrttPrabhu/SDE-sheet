#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to define operator precedence
int priority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1; // Lowest precedence
    }
    if (ch == '*' || ch == '/') {
        return 2; // Higher precedence
    }
    if (ch == '^') {
        return 3; // Highest precedence
    }
    return 0; // Non-operator
}

// Function to convert infix to postfix
string infixToPostfix(string e) {
    stack<char> st;   // Stack to hold operators
    string ans = "";  // Resulting postfix expression
    int n = e.length();

    for (int i = 0; i < n; i++) {
        char ch = e[i];

        // If the character is an operand, add it to the result
        if ((ch >= 'A' && ch <= 'Z') || 
            (ch >= 'a' && ch <= 'z') || 
            (ch >= '0' && ch <= '9')) {
            ans += ch;
        }
        // If the character is an opening parenthesis, push it onto the stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If the character is a closing parenthesis
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            // Pop the opening parenthesis
            if (!st.empty()) {
                st.pop();
            }
        }
        // If the character is an operator
        else {
            while (!st.empty() && priority(ch) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }//for

    // Pop all remaining operators from the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

// Main function to test the conversion
int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}


