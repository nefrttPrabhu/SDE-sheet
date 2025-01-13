//Eg: (){}[] {[]()} {[()]}will work 
//Eg: [{]} will not work coz ekdum he sequence main check kar rha next ka next coz jaise he ] aya else mai gya then vo seach karega [ but milega { toh idhar false ho jayega

#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (char c : s) 
        {
            if (c == '(' || c == '{' || c == '[') //andar kuch bhi backets ke alawa sab ignore
            {
                stack.push(c);  // Push opening brackets only
            } 
            //if(c==')'|| c == '}' || c == ']') iski need isliye nhi hue coz uper wala if dale he sirf brackets ko rha tha 
            else //koi bhi opening bracket category se hi nhi toh closing he hoga category hum neeche check karlenge
            {
                // If the stack is empty or the top of the stack doesn't match
                // the corresponding opening bracket, return false
                if (stack.empty()) //empty hi toh kya he nikaloge
                  return false;

                char top = stack.top();
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '['))  {
                    stack.pop();  // Pop the matching opening bracket
                } 
                else {
                    return false;  // If the brackets don't match ek baar bhi hua seedha return false
                }
            }
        }

        return stack.empty();  // If the stack is empty, all brackets are matched
    }
};
