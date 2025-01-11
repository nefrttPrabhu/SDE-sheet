/*
Pattern: A B A B A C D
Output: [0, 0, 1, 2, 3, 0, 0]

*/
// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int p = 0; // Prefix pointer
    int s = 1; // Suffix pointer
    lps[0] = 0; // lps[0] is always 0

    while (s < pattern.length()) {
        if (pattern[s] == pattern[p]) {
            p++;
            lps[s] = p; // idha rhoga ye ki p start mai zero hi toh agar ye uper likhte and uper wali line neeche ifnot doing lps[s]=p+1 else it ok then [0, 0, 0, 1, 2, 3, 0] instead of [0, 0, 1, 2, 3, 4, 0]
            s++;
        } 
        else 
        {
            if (p == 0) {
                lps[s] = 0; //diff mil gya zero karo 
                s++; //aage dekho matching hone lagi ki nhi 
            } 
            else 
            {
                p = lps[p - 1]; //peeche jao dekho same hi nhi or peeeche jao
            }
        }
    }
