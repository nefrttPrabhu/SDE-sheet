//M1: brute force
for (int i = 0; k > 0; ) { // Loop until k missing numbers are found
    if (arr[i] == a) { // If the current number 'a' is in the array
        i++;           // Move to the next element in the array
    } else {           // If 'a' is not in the array
        k--;           // Decrease k (missing count)
    }
    a++;               // Increment 'a' to check the next number
}

for (int i = a; i < k + a; i++) { // Output the k-th missing number
    nums = i;
}


//M2: Binary Search 
int findKthMissing(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, right = n - 1;

    // Binary search to find the smallest index where missing numbers >= k
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int missing = arr[mid] - (mid + 1);

        if (missing < k) {
            left = mid + 1; // Move to the right half
        } else {
            right = mid - 1; // Move to the left half
        }
    }

    // At the end of binary search, `left` is the insertion point
    return k + left; // Adjust by adding k to the missing numbers before `left`
}
