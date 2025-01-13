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



//M1:
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = {-1, -1};
        int left = findLeftIndex(nums, target);
        int right = findRightIndex(nums, target);
        result[0] = left;
        result[1] = right;
        return result;
    }

    private int findLeftIndex(int[] nums, int target) {
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

    private int findRightIndex(int[] nums, int target) {
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


//M2: doing in 1 fng
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Helper functions to find the first and last occurrence
        int first = findBound(nums, target, true);
        int last = findBound(nums, target, false);
        return {first, last};
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int left = 0, right = nums.size() - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    right = mid - 1; // Narrow down to the left part
                } else {
                    left = mid + 1; // Narrow down to the right part
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return bound;
    }
};
