int fun(vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return 1; // Target found
        }

        if (arr[mid] > target) {
            return fun(arr, low, mid - 1, target); // Search in the left half
        } 
        else {
            return fun(arr, mid + 1, high, target); // Search in the right half
        }
    }
    return -1; // Target not found
}
