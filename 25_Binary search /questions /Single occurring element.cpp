//M1 : Binary Search
/*
all below wrt a                                                                                 m m+1
Case 1: mid == mid+1 : even are remaining then no single on left, it will be found on the right a, a,b,b,c
Case 2: mid == mid+1 : odd are remaining then no single on left,the single will be on the right a, a,b,b
Case 3: mid != mid+1 : odd are remaining then no single on left,the single will be on the right a, b,b,c
Case 4: mid != mid+1 : even are remaining then no single on right, it will be found on the left a, b,b,c,c
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        int l=0,
            h=n-1;
        while(l < h){ //l<=h no effect its just same as l<h just it chech same element twice
            int mid = l + (h - l)/2;

            bool isEven; //is used to determine whether the number of elements on the right side of the mid index is even or odd.
            if((h-mid)%2 == 0)
            isEven = true;
            else
            isEven = false;

            if(nums[mid] == nums[mid+1]){
                if(isEven){
                    l=mid+2; //a, a,b,b,c:  a and a equal hi toh seedha b pe jane ke liye .... right mai hoga
                }
                else{ 
                    h=mid-1; //left mai hoga
                }
            }
                 
            else{
                if(isEven){
                    h=mid; // left jao but mid bhi hoskta hai single 
                }
                else{
                    l=mid+1; //right mia hoga
                }
            }
        }
        return nums[h];
    }
};


//M2 : 
int findSingleNonDuplicate(int a[], int n) {
    for (int i = 0; i < n; i += 2) {  // Increment by 2 to skip pairs
        if (i == n - 1 || a[i] != a[i + 1]) { // idhar ye hai ki aagr single element ki array hue toh bhi ye i == n-1 handle karlega
            return a[i];  // Return the single non-duplicate element
        }
    }
    return -1;  // Default case (should not occur if input is valid)
}


//M3 : XOR
int singleNonDuplicate(int a[], int n) {
    int result = 0;  // Initialize result to 0
    for (int i = 0; i < n; i++) {
        result ^= a[i];  // XOR each element with the result
    }
    return result;  // The result will hold the single non-duplicate element
}

//M3 : Hashmap
#include <unordered_map>

int singleNonDuplicate(int a[], int n) {
    std::unordered_map<int, int> freq;  // Create a hash map to store frequencies

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    // Find the element with a frequency of 1
    for (const auto& pair : freq) {
        if (pair.second == 1) {
            return pair.first;  // Return the single non-duplicate element
        }
    }

    return -1;  // Return -1 if no such element exists (shouldn't happen with valid input)
}




//M4:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        int n = nums.size();
        
        if ( n == 1 ) return nums[0];

        if ( nums[0] != nums[1] ) return nums[0];

        if ( nums[n-2] != nums[n-1] ) return nums[n-1];

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) {
                return nums[mid];
            } 
//take five numbers index will be from 0 - 4
            else if(mid % 2 && nums[mid - 1] == nums[mid] ||    //if mid is odd means single element will be on the left of the mid 
                    mid % 2 == 0 && nums[mid] == nums[mid + 1]) //if mid is even means remaining are even number of numbers to the right of mid so if mid and adjsecnt is equal means the single is on the right of mid + 1
                    {
                low = mid + 1;
            } 
            
            else {
                high = mid - 1;
            }
        }
        return 0;
    }
};
