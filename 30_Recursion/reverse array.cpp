//M1:
void fng(int i, int j, int nums[]) {
    if (i >= j)  // Base condition
        return;
    
    swap(nums[i], nums[j]);  // Swap elements
    fng(i + 1, j - 1, nums); // Recursive call
}
