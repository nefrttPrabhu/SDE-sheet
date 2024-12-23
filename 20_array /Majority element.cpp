/*
Input Format:
  N = 10, nums[] = {4,4,2,4,3,4,4,3,2,4}
Output: 4

S1. phele dekhliya start mai konkisko cancel kar de rha 
S2. then baad mai dekh rhe jo bacha jiska count zyada 
S3. vo element majority let kar liya but as per the ATQ: frq > (size of array)/2
S4. last mai ek for ka loop chala liye uss element ko le karo  
S5. if uski frq as per ATQ hi then that is the majority element else DNE
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}
