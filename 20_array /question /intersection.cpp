/*
Input: 
A: [1 2 3 3 4 5 6]
, B: [3 3 5]
Output: 3,3,5
Explanation: We are given two arrays A and B. 
The elements present in both the arrays  
are 3,3 and 5.
*/


vector<int> intersectionOfArrays(vector<int>A, vector<int>B){
  vector <int> ans;
  int i = 0, j = 0;
    int a = s1.size();
    int b = s2.size();
  // to traverse the arrays
  while (i < a && j < b) {
    //if current element in i is smaller
    if (s1[i] == s2[j]) { 
      //both elements are equal
      ans.push_back(s1[i]); 
      i++;
      j++;
    } 
    else if (s1[i] > s2[j]) {
      j++;
    } 
    else { 
      i++;
    }
  }
  
  return ans;
    
}
