// Recursive function to swap array elements
void swapElements(int i, int n, int arr[]) {
    // Base case: Stop when the middle of the array is reached
    if (i >= n / 2)
        return;
    // Swap the i-th element with the (n-1-i)-th element
    swap(arr[i], arr[n - 1 - i]);
    // Recursive call to the next pair of elements
    swapElements(i + 1, n, arr);
}


// Recursive function to swap array elements
int swapElements(int i, int n, int arr[]) {
    // Base case: Stop when the index reaches the middle of the array
    if (i >= n / 2)
        return 1; // Indicate successful completion
    // Swap the elements at index i and (n - 1 - i)
    swap(arr[i], arr[n - 1 - i]);
    // Recursive call for the next elements
    return swapElements(i + 1, n, arr);
}
