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

            bool isEven;
            if((h-mid)%2 == 0)
            isEven = true;
            else
            isEven = false;

            if(nums[mid] == nums[mid+1]){
                if(isEven){
                    l=mid+2;
                }
                else{ 
                    h=mid-1;
                }
            }
            else{
                if(isEven){
                    h=mid;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return nums[h];
    }
};
