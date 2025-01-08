/*
Enter the text: ababcabcabababd
Enter the pattern: abababd
Pattern found at index 10

*/
// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int p = 0; // Prefix pointer
    int s = 1; // Suffix pointer
    lps[0] = 0; // lps[0] is always 0

    while (s < pattern.length()) {
        if (pattern[s] == pattern[p]) {
            p++;
            lps[s] = p; // idha rhoga ye ki p start mai zero hi toh agar ye uper likhte and uper wali line neeche then [0, 0, 0, 1, 2, 3, 0] instead of [0, 0, 1, 2, 3, 4, 0]
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
