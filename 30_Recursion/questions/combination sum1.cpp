/*
    input: [1,2,3,4,5]
    target: 7
    output: [2,2,3]
*/


class Solution {
private:
    void findCombinations(int ind, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& ds) {
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombinations(ind, arr, target - arr[ind], ans, ds);
            ds.pop_back();
        }

        findCombinations(ind + 1, arr, target, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, target, ans, ds);
        return ans;
    }
};
