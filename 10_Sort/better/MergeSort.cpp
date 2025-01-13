/*
Example 2:
Input: N=7,arr[]={3,2,8,5,1,4,23}
Output: 1,2,3,4,5,8,23

S1: phele pura todete jao chota chota or chota left tree ko mid ki help se and recursion
S2: then same for right tree
S3: then start to sort from left nodes to right
S4: sort karte jao array return karte jao

*/

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high) 
    {
        if (arr[left] <= arr[right]) //sorting ho rhi in ascending order 1 2 3 4....
        {
            temp.push_back(arr[left]);
            left++;
        }
        else //sorting ho rhi in ascending order 1 2 3 4.....
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //
    while (left <= mid) //right exhausted ho gyi  
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) //left exhausted ho gyi  
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half sort chahiye tabtak jabtak high is greater than low jaise he high = low hua mid cal karte karte merge ko call karo and sort the values
    mergeSort(arr, mid + 1, high); // right half sort chahiye same as above
    merge(arr, low, mid, high);  // merging sorted halves 
}
