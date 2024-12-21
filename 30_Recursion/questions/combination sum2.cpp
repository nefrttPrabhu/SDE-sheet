#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end()); 
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

    void backtrack(const vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) // i> start ye check kar rha ki hum aage badhe hi ki ni as i==start when I1 and in I2 i will be i++ but start remains same and agar ha toh fir ye dekho ki uske phele wala ie i-1th index wala bhi same hi ith wale ke toh usko fir se iteration mai dalne se duplicate ka error ayega, isiliye hum remove kar rhe 
            continue;                                            //Eg: [1,1,1,2,2]                                   
            if (candidates[i] > target) break; 
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, combination, result);
            combination.pop_back(); 
        }
    }
};
