
    stack<int> st;

    // Pushing elements onto the stack
    st.push(1);  // Stack: {1}
    st.push(2);  // Stack: {2, 1}
    st.push(3);  // Stack: {3, 2, 1}
    st.push(3);  // Stack: {3, 3, 2, 1}
    st.emplace(5);  // Stack: {5, 3, 3, 2, 1}

    // Access the top element
    st.top();  // Prints 5

    // Pop the top element
    st.pop();  // Stack: {3, 3, 2, 1}
    st.top();  // Prints 3

    // Check size of the stack
    st.size();  // Prints 4

    // Check if the stack is empty
    st.empty();  // Prints 1

    // Swap contents with another stack
    stack<int> st1, st2;
    st1.push(10);
    st1.push(20);  // st1: {20, 10}

    st2.push(30);
    st2.push(40);  // st2: {40, 30}

    st1.swap(st2);

