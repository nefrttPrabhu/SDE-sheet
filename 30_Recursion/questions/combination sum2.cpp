
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
                continue;                                        // Eg: [1,1,1,2,2]  //isse hoga ye ki agar ith index wala ko jab phele he reject kar diya hi and uske baad wala ie i+1th index wala bhi same hi toh usko fir se iteration mai dalna time waste hoga toh isiliye hum remove kar rhe                     
                                                                 // jabtak target achieve nhi hota tab tak lete raho and coz ve target ke close ho rhe hi and jaise he target achieve hua toh fir same elmnt like 2,2 dekhne mai dono same he hi na if we have combination 1,1,2 so picking up 1,1,2 of 3rd and 4th index 2 dekhne mai dono same he hi na 
            if (candidates[i] > target) 
                break; //phele he given arrray sorted hi toh fir agar next element agar target(remaining) se he bada hi toh uske aage wale bhi honge coz of sorted array
            combination.push_back(candidates[i]);
                      //given array , new target        , start, recent set , storing the valid sets
            backtrack(candidates, target - candidates[i], i + 1, combination, result);
            combination.pop_back(); 
        }
    }
};
