//M1:brute force
void removeDuplicates(vector<int>& arr) {
    set<int> s;
    
    // Insert elements into the set (duplicates are automatically removed)
    for (auto i : arr) {
        s.insert(i);  // Insert element into the set
    }

    int a = 0;
    // Copy the unique elements from the set back to the array
    for (auto j : s) {
        arr[a] = j;  // Assign the unique element back to the array
        a++;         // Increment the index
    }

    // Resize the array to contain only the unique elements
    arr.resize(s.size());
}



//M2:optimal
void removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return; // Edge case for empty array
    
    int a = 1; // Start from the second element

    for (int j = 1; j < arr.size(); j++) {
        if (arr[a - 1] != arr[j]) { // Compare current element with previous unique element
            arr[a] = arr[j];  // Store unique element at the next position
            a++;              // Move the 'a' pointer to the next position
        }
    }

    // The new size of the array after removing duplicates is 'a'
    arr.resize(a);
}

//M3:
void removeDuplicates(int arr[], int &n) {
    if (n == 0) return; // Handle edge case
    
    int j = 0; // Index for placing unique elements
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) { // If the current and next elements differ
            arr[j++] = arr[i];      // Place the current element in the result
        }
    }
    // Add the last element (since it won't be compared in the loop)
    arr[j++] = arr[n - 1];
    
    n = j; // Update the size of the array to reflect unique elements
}
