/*
--> the largest value gets stored 1st
--> the laexiographically larger value gets stored 1st
*/

    priority_queue<int> pq; // Max-heap by default

    // Pushing elements into the priority queue
    pq.push(5);  // Queue: {5}
    pq.push(2);  // Queue: {5, 2}
    pq.push(8);  // Queue: {8, 2, 5}
    pq.emplace(10); // Queue: {10, 8, 5, 2}

    // Access the top (maximum) element
    pq.top();  // Prints 10

    // Remove the top element
    pq.pop(); // Queue: {8, 2, 5}
    pq.top();  // Prints 8

    // Query size and empty status
    pq.size();  // Prints 3
    pq.empty();  // Prints 1 i.e NO

  // Minimum heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);  // Heap: {5}
    pq.push(2);  // Heap: {2, 5}
    pq.push(8);  // Heap: {2, 5, 8}
    pq.emplace(10); // Heap: {2, 5, 8, 10}
    pq.emplace(1);  // Heap: {1, 2, 8, 10, 5}

    // Access the top (minimum) element
    pq.top();  // Prints 1

    // Remove the top element
    pq.pop(); // Heap: {2, 5, 8, 10}
    pq.top();  // Prints 2
