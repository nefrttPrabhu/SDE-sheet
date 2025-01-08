// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int p = 0; // Prefix pointer
    int s = 1; // Suffix pointer
    lps[0] = 0; // lps[0] is always 0

    while (s < pattern.length()) {
        if (pattern[s] == pattern[p]) {
            p++;
            lps[s] = p;
            s++;
        } else {
            if (p != 0) {
                p = lps[p - 1];
            } else {
                lps[s] = 0;
                s++;
            }
        }
    }
