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

