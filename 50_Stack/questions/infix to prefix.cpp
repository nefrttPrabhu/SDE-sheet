/*
  S1: Reverse the infix expression
  S2: Replace '(' with ')' and ')' with '(' in reversed expression
  S3: Convert the modified infix to postfix
  S4: Reverse the postfix result to get the prefix expression
*/

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

        
        //agar closing mila hi toh fir tab tak ans mai add karta or pop karta rhega jabtak ki opening nhi mil jata
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            //add and all sab hogya ab Pop the opening parenthesis
            if (!st.empty()) {
                st.pop();
            }
        }
            
        // If the character is an operator ans mai add karna hi ki nhi priority dekh ke karo sab 
        else {//ye wala else likhna toh uper wale elseif ke phele chahiye tha but fir elsif mai sare operators likne pad jata ye mehnat se bachne ke liye he ye chalaki ki hi
            while (!st.empty() && priority(ch) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            } 
            st.push(ch); //iska matlab vo symbol ab mila hi jiski priority zyada hi stack ke top element se
        }
        
    }//for

    // sara priority, brackets wala kaam hogya hi ab bache hue sab remove kardo
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Convert infix to prefix
    // Step 1: Reverse the infix expression
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    // Step 2: Replace '(' with ')' and ')' with '(' in reversed expression
    for (char &ch : reversedInfix) {
        if (ch == '(') {
            ch = ')';
        } else if (ch == ')') {
            ch = '(';
        }
    }

    // Step 3: Convert the modified infix to postfix
    string prefixReversed = infixToPostfix(reversedInfix);

    // Step 4: Reverse the postfix result to get the prefix expression
    string prefix = prefixReversed;
    reverse(prefix.begin(), prefix.end());

    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
