
/*
Example 2:
Input: N = 8 , Arr[] = {4,6,2,5,7,9,1,3}
Output: 1 2 3 4 5 6 7 9

S1: we 1st work on moving the pivot to the right position
S2: then we work on achieveing smaller elements on the right and bigger elements on the left of the pivot and also wrt pivot
S3: we move i and j check if i is greater tha pivot and j having smaller than pivot then replacing them 
S4: all doing the swaps if i and j crosses then stop moving i and j and return the jth index coz that is the place where supposed pivot is to be placed
S5: swap supposed pivot with jth index
S6: then work this same for the left side of pivot and then right side of the pivot

*/
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++; // agar chota hi toh aage badho coz hum toh bada seaarch kar rhe  coz bade toh sab right of pivot hone chehiye
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--; // agar bada hi toh aage badho coz hum toh chot seaarch kar rhe coz chote toh sab left of the pivot hone chehiye
        }
        if (i < j) // i or j cross nhi kiye chote left aate jayen bade rigth jate jaye
          swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]); // cross ho gya pivot ke liye index mil gaya
    return j; 
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}
