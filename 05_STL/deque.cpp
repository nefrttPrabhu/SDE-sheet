deque<int> dq;
1.  dq.push_front(10);  // {10}
    dq.push_front(20);  // {20, 10}
    dq.push_front(30);  // {30, 20, 10}

2.  // Push elements at the back
    dq.push_back(40);   // {30, 20, 10, 40}
    dq.push_back(50);   // {30, 20, 10, 40, 50}

3.  // Pop an element from the front
    dq.pop_front();     // {20, 10, 40, 50}
    // Pop an element from the back
    dq.pop_back();      // {20, 10, 40}

// rest functions same as vector
// begin, end, rbegin, rend, clear, insert, size, swap
