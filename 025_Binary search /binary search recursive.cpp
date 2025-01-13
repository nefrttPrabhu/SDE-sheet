int BS(int arr[], int low, int high, int target) 
{
    if (low > high) {
        return -1; // Target not found
    }

    int mid = low + (high - low) / 2; // Prevents potential overflow

    if (arr[mid] == target) {
        return mid; // Target found
    }
    else if (arr[mid] < target) {
        return BS(arr, mid + 1, high, target); // Search right half
    }
    else {
        return BS(arr, low, mid - 1, target); // Search left half
    }
}
