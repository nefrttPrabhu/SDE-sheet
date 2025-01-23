//M1: Amazing fact line number14 conversion from 1D to 2D
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  // Number of rows in the matrix
        int n = matrix[0].size();  // Number of columns in the matrix

        int start = 0; // Start index for binary search
        int end = m * n - 1; // End index for binary search

        // Binary search loop
        while (start <= end) {
            int mid = start + (end - start) / 2; // Middle index of the current range

            // Compute the row and column for the middle index
            int element = matrix[mid / n][mid % n];

            // Check if the middle element is equal to the target
            if (element == target) {
                return true;
            }
            // If the element is greater than the target, search in the left half
            else if (element > target) {
                end = mid - 1;
            }
            // If the element is less than the target, search in the right half
            else {
                start = mid + 1;
            }
        }
        return false; // Target not found
    }



//M2: normal 1D visualization of 2D
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int m = arr.size(); 
        int n = arr[0].size(); 

        int i=0; // Start from the first row
        int j=n-1; // Start from the last column of the first row
      
        // Traverse the matrix
        while (i < m && j >= 0) {
            if (target > arr[i][j]) {
                i++; // Move down to the next row
            } else if (target < arr[i][j]) {
                j--; // Move left to the previous column
            } else {
                return true; // Target found
            }
        }
        return false; // Target not found
    }

