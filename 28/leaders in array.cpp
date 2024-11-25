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


/*
My solution need some improvments
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
    int i=0,j=0,n=arr.size();
    vector<int> temp={0};
    while(i<n||j<n){
        if(arr[i]>=arr[j]){
            if(j!=n){
                j++;
            }
            else{
                temp.push_back(arr[i]);
                j=i;i++;
            }
        }
        else{
            if(i!=n){
                i++;
            }
            else{
                temp.push_back(arr[j]);
                i=j;j++;
            }
        }
    }
    return temp;
} 
};
*/
