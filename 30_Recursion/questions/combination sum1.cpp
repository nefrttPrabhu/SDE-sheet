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
            findCombinations(ind, arr, target - arr[ind], ans, ds); //tab tak add karta rhega jabtak target se chota hi uske baad ye hoga ki nxt index ke number pe jayega removing the last one and all the ones that not to be used 
            ds.pop_back(); //ispe tab ayega jab 
        }

        findCombinations(ind + 1, arr, target, ans, ds); //yahan tab ayega jab maan lo target hi 7 and abhi ka set hi 2,2,2,2 toh ab ye bada ho gya toh uper wale recursion se jab wepas aya toh 2 ko remove kiya and nxt index pe gya iss talash mai ki usko aisa milega ki ya toh target ke equal ho ya fir usse chota 
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, target, ans, ds);
        return ans;
    }
};
