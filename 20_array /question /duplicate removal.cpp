/*
Eg: arr[] = {1, 1, 2, 2, 3, 4, 4, 5}
    arr[] = {1, 2, 3, 4, 5,  ,  ,  }
*/

//M1:brute force
void removeDuplicates(vector<int>& arr) {
    set<int> s;
    for (auto i : arr) {
        s.insert(i);  // Insert element into the set
    }
    int a = 0;
    for (auto j : s) {
        arr[a] = j;  // Assign the unique element back to the array
        a++;         // Increment the index
    }
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
    arr[j++] = arr[n - 1];
    n = j; // Update the size of the array to reflect unique elements
}


//M4: 
void removeDuplicates(int arr[], int &n) {
    if (n == 0) return;
    int i = 0;
    int j = 1;

    while (j < n) {
        if (arr[j] != arr[i]) { // Found a new unique element
            i++;               // Move slow pointer
            arr[i] = arr[j];   // Copy unique value
        }
        j++; // Move fast pointer
    }
    n = i + 1; // Update array size
}
