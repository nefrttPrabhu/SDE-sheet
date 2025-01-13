int BS(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential overflow
        
        if (arr[mid] == target) {
            return mid; // Target found
        }
        
        else if (arr[mid] < target) {
            low = mid + 1; // Search the right half
        }
          
        else {
            high = mid - 1; // Search the left half
        }
    }

    return -1; // Target not found
}
