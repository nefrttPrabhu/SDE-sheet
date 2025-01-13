//M1: basic
// Function to find the leftmost index of the target
int findLeftIndex(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int leftmost = -1; // Default to -1 if target is not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            leftmost = mid; // Update the leftmost index
            right = mid - 1; // Continue searching on the left side
        } 
        else if (nums[mid] > target) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }

    return leftmost;
}

// Function to find the rightmost index of the target
int findRightIndex(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int rightmost = -1; // Default to -1 if target is not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            rightmost = mid; // Update the rightmost index
            left = mid + 1; // Continue searching on the right side
        } 
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return rightmost;
}



//M2:
 int findLeftIndex(int[] nums, int target) {
        int left = 0, right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        return (left < nums.length && nums[left] == target) ? left : -1;
    }

 int findRightIndex(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (right >= 0 && nums[right] == target) ? right : -1;
    }
}


//M3: doing in 1 fng by calling same fng 1st for left then for right
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int left = 0, right = nums.size() - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    right = mid - 1; // Narrow down to the left part
                } 
                else {
                    left = mid + 1; // Narrow down to the right part
                }
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        return bound;
    }
