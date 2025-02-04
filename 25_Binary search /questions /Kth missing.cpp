//M1: brute force
for (int i = 0; k > 0; ) { // Loop until k missing numbers are found
    if (arr[i] == a) { // If the current number 'a' is in the array
        i++;           // Move to the next element in the array
    } else {           // If 'a' is not in the array
        k--;           // Decrease k (missing count)
    }
    a++;               // Increment 'a' to check the next number
}

for (int i = a; i < k + a; i++) { // Output the k-th missing number
    nums = i;
}


//M2: Binary Search 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            int kitne_missing_till_mid = arr[mid] - (mid+1);
            if(kitne_missing_till_mid < k) {
                s = mid+1;
            }
            else {
                e = mid-1;
            }
        }
        return s+k;
    }
};

/*
number of given array  - (index+1) = no. of numbers
need the kth missing hi mid+k = given array mai kitne ghussenge 
number at index - index gives number of numbers but that index + k give that missing number 

11th position se 6th missing hi but need the 5ht missing ie l=4+5=9 is the 5th missing number

actual:[0,1,2,3,4]
      :[1,2,3,4,5]
given: [2,3,4,7,11]
11-5 = 6 ie 6 missing numbers are there as 11th is at the 5th position irrespective of it actual 11th position this means there are 6 missing numbers but we have been asked for the 5ht missing that why we l=4 and =4(index of the 11 not position)-5(asked missing number)
1 [2] [3] [4] 5 6 [7] 8 9 10 [11]

and binary search ye kar rha hi ki hum mid ke respect mai dekh rahe toh humne dekha 2nd index pe 4 hi iska mtlb ek number missing hoga before 4 and that is 1 itself but need hume 5th missing ki hi humara scope he 1 missing ka hi but toh hum or aage gye 7 pe gye uska index hi 3 postion hi 4 iska ye mtlb 7 ki wajah se 3 missing numbers honge but we need 5th or aage gye scope badhaya last ab 11 he hi 11 ka index hi 4 position hi 5 ie 6 missing numbers honge ab humara scope asked se bhi zyada hi but we need 5th missing but scope hi 6 tak ka toh but reduce karne se direct scope 3 ka he hi last toh no neeed this way we get the 5th missing by adding the given aaray element index to the asked missing number give the missing number itself
*/
