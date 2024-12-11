/*
  --> they uses doubly linked list for storage due to which they have O(1) for insertions better than vectors
*/

1.  list<int> ls;  // Create a list of integers
    // Add elements at the front
    ls.push_front(5);
    ls.emplace_front(2);

2.  // Add elements at the back
    ls.push_back(10);
    ls.emplace_back(15);

// rest functions same as vector
// begin, end, rbegin, rend, clear, insert, size, swap
