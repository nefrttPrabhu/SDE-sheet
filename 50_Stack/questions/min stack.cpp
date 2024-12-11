//M1
#include <stack>
#include <utility> // For std::pair

using namespace std;

stack<pair<int, int>> st;

void push(int val) {
    if (st.empty()) {
        st.push({val, val}); // If the stack is empty, push the value as both value and min
    } 
    else {
        if (st.top().second > val) { // Compare the current minimum with the new value
            st.push({val, val}); // Push the new value as the new minimum
        } 
        else {
            st.push({val, st.top().second}); // Push the new value but retain the current minimum
        }
    }
}


//M2
else{
  st.push(val,min(val,st.top().second);
}


//M3
push(val){}
pop(){}
top(){}



















