/*
Example: nums = [3, 4, 5, 1, 2]
Output: 1
nums = [4, 5, 6, 7, 0, 1, 2]
Output: 0
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {//idhar = is liye nhi nikal coz last mai jab r and l will be on same spot then mid=3+(3-3)/2=3 toh baar baar 3 ata rhta and mid and r would have never updated and loop infinity tak fass jata
            int mid = left + (right - left) / 2;

            // If the middle element is greater than the rightmost element,
            // the minimum is in the right half.
            if (nums[mid] > nums[right]) { //for mid=2 and r=4 nums[mid]=5 > nums[r]=2 which is correct by condition but wrong as its supposed to be a sorted array
                left = mid + 1;
            } 
            // Otherwise, the minimum is in the left half (including mid).
            else {
                right = mid;
            }
        }

        // The left pointer points to the minimum element.
        return nums[left]; //nums[right] both are same
    }
};


/*
Example 3:
Input: nums = [11, 13, 15, 17]
Initial Values:
left = 0, right = 3

First Iteration:
mid = left + (right - left) / 2 = 0 + (3 - 0) / 2 = 1
nums[mid] = nums[1] = 13
nums[right] = nums[3] = 17
Since nums[mid] <= nums[right], the minimum must be in the left half (including mid).
Update: right = mid = 1

Second Iteration:
mid = left + (right - left) / 2 = 0 + (1 - 0) / 2 = 0
nums[mid] = nums[0] = 11
nums[right] = nums[1] = 13
Since nums[mid] <= nums[right], the minimum must be in the left half (including mid).
Update: right = mid = 0
*/
