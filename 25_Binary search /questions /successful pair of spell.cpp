vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    int n = spells.size(), m = potions.size();
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        long long target = (success + spells[i] - 1) / spells[i]; // Ceiling of (success / spells[i])
        int l = 0, r = m - 1;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (potions[mid] >= target) 
                r = mid;  // Move left if potion is sufficient
            else 
                l = mid + 1;  // Move right otherwise
        }
        
        result[i] = (potions[l] >= target) ? (m - l) : 0;
    }
    return result;
}
