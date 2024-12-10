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
