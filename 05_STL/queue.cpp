
    queue<int> q;

    // Pushing elements into the queue
    q.push(1);    // Queue: {1}
    q.push(2);    // Queue: {1, 2}
    q.emplace(4); // Queue: {1, 2, 4}

    // Modify the back element
    q.back() += 5; // Queue: {1, 2, 9}

    // Print the back element
    q.back();  // Prints 9

    // Print the front element
    q.front();  // Prints 1

    // Pop the front element
    q.pop(); // Queue: {2, 9}
    q.front();  // Prints 2

    // Check the size of the queue
    q.size();  // Prints 2

    // Check if the queue is empty
    q.empty();  // Prints 1

    // Swap contents with another queue
    queue<int> q2;
    q2.push(100);
    q2.push(200); // q2: {100, 200}

    q.swap(q2); 

    q.front();  // Prints 100  q={100, 200}
    q2.front();  // Prints 2  q2={2, 9}

