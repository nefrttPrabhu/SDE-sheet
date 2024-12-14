
/*
Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting the array is: 9, 13, 20, 24, 46, 52

idea:
S1. idhar 1st element ko suppose karlo sabse chota hi
S2. puri array mai usse chota search karo mila then index note karlo then inner se bahr nikal karke swap karlo dono
S3. aise hoga kya apne app he smallest 1st baan jayega toh j ka loop shuru he tab i se karo coz starting mai sort hota ja rha
*/

#include<bits/stdc++.h>

using namespace std;
void selection_sort(int arr[], int n) {
  // selection sort
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
}
