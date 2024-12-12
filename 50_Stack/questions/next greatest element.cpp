#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> nge(n, -1); // To store the result

    s.push(-1); // Sentinel value to handle empty stack

    for (int i = n - 1; i >= 0; i--) {
        while (s.top() != -1) { // Check stack top
            if (arr[i] > s.top()) { // If current element is greater
                s.pop();
            } else {
                nge[i] = s.top(); // Store next greater element
                break;
            }
        }
        s.push(arr[i]); // Push current element onto the stack
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }
}
