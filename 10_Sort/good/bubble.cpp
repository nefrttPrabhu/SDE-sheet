
/*
Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting we get 9,13,20,24,46,52
idea:
S1. jaise bubble uper jata bada hota jata waise he uper sabse bada number chala jata hi ek ek karke
S2. toh j ka loop hum reduce karte jate i se coz last apne aap he sort hota chala jata
*/
#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
