//Eg: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//      0  1   0  4   3  5  6   1  5
//S1: max sum subarray 

int kadaneModified(vector<int>& a) {
    int sum = 0;        // To store the current subarray sum
    int maxi = INT_MIN; // To store the maximum sum found so far

    for (size_t s = 0; s < a.size(); s++) {
        sum += a[s];          // Add the current element to the sum
        if (sum > 0) {        // If the sum is positive, check for the maximum
            maxi = max(maxi, sum);
        } else {
            sum = 0;          // Reset the sum to 0 if it becomes negative
        }
    }

    return maxi; // Return the maximum sum of a contiguous subarray
}
