/*
Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: 
After sorting the array is: 9,13,20,24,46,52

idea:
S1. ek starting se start karo single element ki aray bana kar usmia ek ek karke next element ko insert karte jao
S2. jab vo naya elements aye to usko array ke elements se apas mai sort karo

*/

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        for (int j = i; (j > 0 && arr[j - 1] > arr[j]); j--) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
        }
    }
}
