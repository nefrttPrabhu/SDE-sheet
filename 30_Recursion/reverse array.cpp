//M1:
void fng(int i, int j) {
    if (i >= j)  // Base condition
        return;
    
    swap(nums[i], nums[j]);  // Swap elements
    fng(i + 1, j - 1); // Recursive call
}


//M2:
void fng(int i) {
    if (i >= n/2)  // Base condition
        return;
    
    swap(nums[i], nums[n - i - 1]);  // Swap elements
    fng(i + 1); // Recursive call
}
