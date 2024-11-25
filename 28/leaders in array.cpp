/*
Input: arr = [10, 22, 12, 3, 0, 6]
Output: 22 12 6
S1: check if the number having the elements on the left are smaller 
S2: left(end) se he start karo agar n-i<i toh fir leader hi nhi toh aage badho
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n) {

  vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
 int max = arr[n - 1];
 ans.push_back(arr[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }

  
  return ans;
}
