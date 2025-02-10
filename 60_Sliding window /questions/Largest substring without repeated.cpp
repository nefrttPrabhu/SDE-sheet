/*
           0 1 2 3 4 5 6 7 8 9
  Example: A B C D E C B A D F
  output:  C B E A D F
  len: 6

  S1: first second same se start karo and count array banao jo ki number of occurances count karega string mai present elements ki and uss postion pe unka count inc karega same as the hash map
  S2: dekho ki agar wrt second count mai vo element ek baar bhi aya hi ki nhi , if nhi then add inc the elemnts count at 
  S3: if it has already occured then usko remove karne ke liye uske phele ke bhi jitne hi sabko remove karna hoga jo ki first ki help se remove honge coz second to aage ja rha tha first tab tak wait kiya jabtak koi bhi element firse occure nhi kar gya
*/

int lengthOfLongestSubstring(string s) {
        vector<bool> count(256,0);
        int first = 0, 
        second = 0, 
        len = 0;

        while (second < s.size()) {
            while (count[s[second]]) {
                count[s[first]] = 0;
                first++;
            }                     //taking example of C
            count[s[second]] = 1; //s[second] element ko nikal kar layega then count us element ka count inc kardega, second is the pointer use to traver the given string and get the char at that poistion of second then count is increasing the count of the char retruned from the postion of second in the given string
                                  //iska ek or ye kaam hi jab first(pointer ki help) se remove karte rhe toh vo C ka count bhi 0 ho gya tha but later C aya toh isiliye second ko hum baad mai ++ kar rhe taki jo remove hua vo toh 0 ho he gya and jab firse aya toh firse 0 he na reh jaye
            len = max(len, second - first + 1);
            second++;
        }

        return len;
    }




//M2:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int j = 0, i = 0, c = 0;  // j = right pointer, i = left pointer, c = max length
        map<char, int> mp;  // Stores the last index of characters

        while (j < n) {
            if (mp.find(s[j]) == mp.end() || mp[s[j]] < i) {
                // Character is not in the current window
                mp[s[j]] = j;  // Store the last occurrence
                c = max(c, j - i + 1);  // Update max length
                j++;  // Expand window
            } else {
                // Duplicate found: move left pointer `i` to the right of last occurrence
                i = mp[s[j]] + 1;
            }
        }

        return c;
    }
};




//M3:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);  // ASCII character tracking
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            if (lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }
            lastIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};



//M4:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        vector<int> lastIndex(256, -1);  // Tracks the last index of each character
        int maxLength = 0;
        int start = 0;  // Start of the current substring
        
        for (int i = 0; i < n; i++) {
            if (lastIndex[s[i]] >= start) {
                // Move start to the right of the last occurrence of s[i]
                start = lastIndex[s[i]] + 1;
            }
            
            // Update last index of character
            lastIndex[s[i]] = i;

            // Calculate the max length
            maxLength = max(maxLength, i - start + 1);
        }
        
        return maxLength;
    }
};
