/*
Eg: cb34
Output: {};
Eg: abc3dec45
Output: abd
*/
//M1:
class Solution {
public:
    string clearDigits(string s) {
        string a = "";

        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                a.pop_back();
                continue;
            } 

            a += s[i];
        }
        return a;
    }
};



//M2:
class Solution {
public:
    string clearDigits(std::string s) {
        char temp[100];
        int n = s.length(), b = 0;

        for (int i = n - 1; i >= 0; i--) {
            int j = i, c = 0;
            while (j >= 0 && (s[j] >= '0' && s[j] <= '9')) {
                j--;
                c++;
                i = j;
            }
            while (c-- && j >= 0) {
                i--;
                j = i;
            }
            if (i >= 0 && !(s[i] >= '0' && s[i] <= '9')) {
                temp[b] = s[i];
                b++;
            }
        }

        string result = "";
        for (int i = b - 1; i >= 0; i--) {
            result += temp[i];
        }

        return result;
    }
};



//M3:
class Solution {
public:
    std::string clearDigits(std::string s) {
        char temp[100]; 
        int b = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (b > 0) {
                    b--;
                }
            } else {
                temp[b] = s[i];
                b++;
            }
        }

        std::string result = "";
        for (int i = 0; i < b; i++) {
            result += temp[i];
        }

        return result;
    }
};
