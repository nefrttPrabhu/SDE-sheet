class Solution {
    public void moveZeroes(int[] nums) {
        int z = 0; // Pointer for the next zero position

        // Traverse the array
        for (int nz = 0; nz < nums.length; nz++) {
            if (nums[nz] != 0) {
                // Swap non-zero element to the position of the next zero
                int temp = nums[nz];
                nums[nz] = nums[z];
                nums[z] = temp;
                z++; // Increment zero pointer
            }
        }
    }
}
