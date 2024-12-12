/*
    Eg1: arr = {3,1,2,4,3,5,5}
         nge = {4,2,4,5,5,5,-1}
    Eg2: arr = {4, 5, 2, 10, 8}
         nge = {5, 10, 10, -1, -1}
    Eg3: arr = {6, 0, 8, 1, 3}
         nge = {8, 8, -1, 3, -1}
*/

//M1
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

//M2
void nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1); // To store the next greater element
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        // Remove elements smaller than or equal to the current element
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // If stack is not empty, the top element is the next greater element
        if (!s.empty()) {
            nge[i] = s.top();
        }

        // Push the current element into the stack
        s.push(arr[i]);
    }

//M3 overwritting the given array
void nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;

    s.push(-1); // Sentinel value to handle empty stack

    for (int i = n - 1; i >= 0; i--) {
        while (s.top() != -1) {
            if (arr[i] > s.top())
                s.pop();
            else 
                break;
        }
        // Update arr[i] with the next greater element (top of the stack)
        arr[i] = s.top();
        // Push the current element into the stack for subsequent comparisons
        s.push(arr[i]);
    }
}

//M4 O(1)
void nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    int maxElement = -1; // To track the greatest element to the right

    for (int i = n - 1; i >= 0; i--) {
        int current = arr[i];
        arr[i] = maxElement; // Replace current element with the next greater element
        if (current > maxElement) {
            maxElement = current; // Update the greatest element
        }
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
