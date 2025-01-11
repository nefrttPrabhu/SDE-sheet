//O(n^3) type 1:
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
            sum += a[k];
            if (sum == 0) {
                c++;
            }
        }
    }
}

//O(n^3) type 2:
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
            sum += a[k];
        }
        if (sum == 0) {
            c++;
        }
    }
}

/*
| Aspect               | type 1                                                  | type 2                                                        |
|----------------------|---------------------------------------------------------|---------------------------------------------------------------|
| Condition Location   | Inside the innermost loop (k loop).                     | Outside the innermost loop, after the sum is calculated.      |
| Sum Calculation      | Checks if (sum == 0) during every step of sum building. | Checks if (sum == 0) only after the subarray sum is complete. |
| Counting Behavior    | A single subarray can be counted multiple times.        | Each subarray is counted exactly once.                        |
| Correctness          | Likely incorrect for this problem.                      | Correct for the zero-sum subarray problem.                    |

for case 1:
Given: a = [3, -1, -2, 0, 2, 6, 4]
i=0,j=4
subarray a = [3, -1, -2, 0, 2]
Subarray considering [3, -1, -2, 0, 2] ie if this one's sum is 0 or not at the end 
Inner Loop Execution (k = 0 to 4):
k = 0: sum = 3        = 3 (not 0).
k = 1: sum = 3 + (-1) = 2 (not 0).
k = 2: sum = 2 + (-2) = 0 (c++ here).
k = 3: sum = 0 + 0    = 0 (c++ again).
k = 4: sum = 0 + 2    = 2 (not 0). this is the actual subarray to be considered but due to above we are considering [3, -1, -2] [3, -1, -2, 0]
iska count ana chahiye 0 aa rha 2 
waise he agar i=0,j=6, subarray a = [3, -1, -2, 0, 2] 
Overcount Issue: Here, Code 1 increments c twice for the same subarray because the sum temporarily equals 0 multiple times during computation.
Why Code 1 Overcounts
Logic Flow: Code 1 checks if (sum == 0) for each element added to the sum. This means:
For a given subarray [i, j], if the sum becomes 0 during intermediate steps (not just at the end), it will count that subarray multiple times.
This overcounting happens because the same subarray is considered multiple times as new elements are added.
*/




//O(n^2)
for (int i = 0; i < n; i++) 
{
    int sum = 0;  
    for (int j = i; j < n; j++) 
    {
        sum += a[j]; 
        if (sum == 0)  
            c++;     
    }
}

/*
1 element = [3]           [-1]        [-2]     [0]*  [2]
2 element = [3,-1]        [-1,-2]     [-2,0]   [0,2]
3 element = [3,-1,-2]*    [-1,-2,0]   [-2,0,2]*
4 element = [3,-1,-2,0]*  [-1,-2,0,2]
5 element = [3,-1,-2,0,2]
output: 4

Zero-Sum Subarrays:
Subarrays with a sum of zero:
[3, -1, -2]
[3, -1, -2, 0]
[-2, 0, 2]
[0]
Total Count (c): 4.
*/




