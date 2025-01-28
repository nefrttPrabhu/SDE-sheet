//Eg: {1, 2, 3, 4, 3, 2, 1}

for (int i = 0; i < n; i++) {
        if (a[i] < smallest) {
            secondSmallest = smallest; // Update second smallest
            smallest = a[i];           // Update smallest
        } else if (a[i] < secondSmallest && a[i] != smallest) {
            secondSmallest = a[i]; // Update second smallest if it's greater than smallest
        }
    }
