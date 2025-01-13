class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, n = height.size();
        vector<int> lm = leftmax(height, n);
        vector<int> rm = rightmax(height, n);

        for (int i = 0; i < n; i++) {
            sum += min(lm[i], rm[i]) - height[i];
        }
        return sum;
    }

    vector<int> leftmax(vector<int>& height, int n) {
        vector<int> lm(n);
        lm[0] = height[0];

        for (int i = 1; i < n; i++) {
            lm[i] = max(lm[i - 1], height[i]);
        }

        return lm;
    }

    vector<int> rightmax(vector<int>& height, int n) {
        vector<int> rm(n);
        rm[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rm[i] = max(rm[i + 1], height[i]);
        }

        return rm;
    }
};

/* errors to be fixed
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, n = height.size();
        vector<int> lm = leftmax(height, n);
        vector<int> rm = rightmax(height, n);

        for (int i = 0; i < n; i++) {
            sum += min(lm[i], rm[i]) - height[i];
        }
        return sum;
    }

    vector<int> leftmax(vector<int>& height, int n) {
        vector<int> lm(n,0);
        for (int i = 0; i < n-1; i++) {
            lm[i] = max(lm[i+1], height[i]);
        }

        return lm;
    }

    vector<int> rightmax(vector<int>& height, int n) {
        vector<int> rm(n,0);
        for (int i = n - 2; i >=0; i--) {
            rm[i] = max(rm[i], height[i+1]);
        }

        return rm;
    }
};

*/


//solution 2
void trap(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return; // Handle edge case
    
    int l = 0, r = n - 1;
    int lm = 0, rm = 0, total = 0;

    while (l < r) {
        if (arr[l] < arr[r]) {
            if (arr[l] > lm) {
                lm = arr[l]; // Update left max
            } else {
                total += lm - arr[l]; // Add trapped water
            }
            l++; // Move left pointer
        } else {
            if (arr[r] > rm) {
                rm = arr[r]; // Update right max
            } else {
                total += rm - arr[r]; // Add trapped water
            }
            r--; // Move right pointer
        }
    }
    cout << total << endl; // Output the result
}

