//Eg: [0,2,5,4,3,1,7,6]
// brute force
int findIndex(int a[], int n) {
    for (int i = n - 1; i > 0; i--) { // Start from n-1 and iterate backward
        if (a[i] > a[i - 1]) {
            return i - 1; // Return the index where a[i] > a[i-1]
        }
    }
    return -1; // Return -1 if no such condition is met
}


//optimal
//Eg: [0,2,5,4,3,1,7,6]
    for (int i = 0; i < n; i++) {
        if (a[i] > first) {
            second = first;
            first = a[i];
        } 
	else if (a[i] > second && a[i] < first) { //Logic resolution: The logic doesn’t handle the case where all elements in the array are the same or when the array has fewer than 2 elements.
            second = a[i];
        }
    }
