void generatePermutations(vector<int> &a, int index, vector<vector<int>> &ans) {
    if (index == a.size()) {  // Base case: If index reaches the end, store the permutation
        ans.push_back(a);
        return;
    }

    for (int i = index; i < a.size(); i++) {
        swap(a[index], a[i]);  // Swap to create a new permutation
        generatePermutations(a, index + 1, ans);
        swap(a[index], a[i]);  // Backtrack to the previous state
    }
}
