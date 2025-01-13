int findMinSubstring(string s, int totalDistinct) {
    int n = s.size();
    vector<int> count(256, 0); // ASCII-based count
    int diff = totalDistinct; // Number of distinct characters to find
    int first = 0, second = 0, len = INT_MAX;

    while (second < n) {
        // Expand the window
        while (diff != 0 && second < n) {
            if (count[s[second]] == 0) 
                diff--; // New distinct character found
            
            count[s[second]]++;
            second++;
        }

        // Shrink the window
        while (diff == 0) {
            len = min(len, second - first); // Update the minimum length
            count[s[first]]--;

            if (count[s[first]] == 0) 
                diff++; // Lost a distinct character
            
            first++;
        }
    }

    return len == INT_MAX ? -1 : len; // Return -1 if no valid substring exists
}


/* Explaination of line 3:
           0 1 2 3 4 5 6 7 8 9 10 11
  Example: A A B B A A A B B A C  C

  
| Inner Loop 1 (while diff != 0)                                              | Inner Loop 2 (while diff == 0)                                              |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 0                                                                  | Current Window: [first = 0, second = 11]                                    |
| s[second] = A: count[A] = 1                                                 | Substring = AABBAAABBAC                                                     |
| diff = 2 (new distinct character A)                                         | Shrink the window: count[A] = 5                                             |
| Increment second → second = 1                                               | diff = 0 (still valid)                                                      |
|                                                                             | Increment first → first = 1                                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 1                                                                  | Current Window: [first = 1, second = 11]                                    |
| s[second] = A: count[A] = 2                                                 | Substring = ABBAAABBAC                                                      |
| diff = 2 (no change in distinct count)                                      | Shrink the window: count[A] = 4                                             |
| Increment second → second = 2                                               | diff = 0 (still valid)                                                      |
|                                                                             | Increment first → first = 2                                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 2                                                                  | Current Window: [first = 2, second = 11]                                    |
| s[second] = B: count[B] = 1                                                 | Substring = BBAAABBAC                                                       |
| diff = 1 (new distinct character B)                                         | Shrink the window: count[B] = 3                                             |
| Increment second → second = 3                                               | diff = 0 (still valid)                                                      |
|                                                                             | Increment first → first = 3                                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 3                                                                  | Current Window: [first = 3, second = 11]                                    |
| s[second] = B: count[B] = 2                                                 | Substring = BAAABBAC                                                        |
| diff = 1 (no change in distinct count)                                      | Shrink the window: count[B] = 2                                             |
| Increment second → second = 4                                               | diff = 0 (still valid)                                                      |
|                                                                             | Increment first → first = 4                                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 4                                                                  | Current Window: [first = 4, second = 11]                                    |
| s[second] = A: count[A] = 3                                                 | Substring = AAABBAC                                                         |
| diff = 1 (no change in distinct count)                                      | Shrink the window: count[A] = 3                                             |
| Increment second → second = 5                                               | diff = 0 (still valid)                                                      |
|                                                                             | Increment first → first = 5                                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 5                                                                  | Current Window: [first = 5, second = 11]                                    |
| s[second] = A: count[A] = 4                                                 | Substring = AABBAC                                                          |
| diff = 1 (no change in distinct count)                                      | Shrink the window: count[A] = 2                                             |
| Increment second → second = 6                                               | diff = 0 (still valid)                                                      |
|                                                                             | Increment first → first = 6                                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 6                                                                  | Current Window: [first = 6, second = 11]                                    |
| s[second] = A: count[A] = 5                                                 | Substring = ABBAC                                                           |
| diff = 1 (no change in distinct count)                                      | Shrink the window: count[A] = 1                                             |
| Increment second → second = 7                                               | diff = 0 (still valid)                                                      |
|                                                                             | Increment first → first = 7                                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 7                                                                  | Current Window: [first = 7, second = 11]                                    |
| s[second] = B: count[B] = 3                                                 | Substring = BBAC                                                            |
| diff = 1 (no change in distinct count)                                      | Shrink the window: count[B] = 1                                             |
| Increment second → second = 8                                               | diff = 0 (still valid)                                                      |
|                                                                             | Increment first → first = 8                                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 8                                                                  | Current Window: [first = 8, second = 11]                                    |
| s[second] = B: count[B] = 4                                                 | Substring = BAC                                                             |
| diff = 1 (no change in distinct count)                                      | Shrink the window: count[B] = 0                                             |
| Increment second → second = 9                                               | diff = 1 (invalid substring)                                                |
|                                                                             | Increment first → first = 9                                                 |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 9                                                                  | Current Window: [first = 9, second = 11]                                    |
| s[second] = A: count[A] = 6                                                 | Substring = BAC                                                             |
| diff = 1 (no change in distinct count)                                      | Shrink the window: count[B] = 0                                             |
| Increment second → second = 10                                              | diff = 1 (invalid substring)                                                |
|                                                                             | Increment first → first = 10                                                |
|-----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| second = 10                                                                 | Current Window: [first = 10, second = 11]                                   |
| s[second] = C: count[C] = 1                                                 | Substring = C                                                               |
| diff = 0 (new distinct character C)                                         | Shrink the window: count[C] = 0                                             |
| Increment second → second = 11                                              | diff = 1 (invalid substring)                                                |
| Exit Inner Loop 1 (as diff == 0).                                           | Increment first → first = 11                                                |


BAC ke baad chala second hi 11 diff hi 0 ek baar or 
2nd while chala
 len=min(3,3)=3 ayi 
 count[s[first]]- - hua
window size dec hua hogya AC
unique B gya 
if() true hua
diff++ hua
first aage badha A pe aya 
ab 2nd while false ho gya 

main while check hua second=11<size=12 i.e true 
1st while(true) hua 
if(false hi) 
diff no change
window size increase hua  ACC last C was second =11 and second++ hua second=12 hogya 

but agar inner while chlta rha coz of the flow of while and diff inc nhi hoga coz no unique after that toh second++ hota rahega and 
13 ho jayega if outer while loop itna power nhi hi ki andar wala while ko rok sake tab tak inner while run hota rahega infinity tak 
different character aya he nhi to inner wala ruka he nhi and outer wala inner ko rok nhi sakta coz after entire execution of the 
inner while is not over tab tah outer while ki condition will not be checked but tab tak he inner while inaccessible memory pe chla jayega and 
segmentation fault aa jayega coz loop ka yahi hota hi ki run until all the line in the loop ie till the end  of outer loops then the condition 
of the outer loop is checked but idhar while ke andar while hi ab hoga ye inner wala while infinity tak jayega if seg fault nhi ata as different 
ab zero hoga nhi second++ hota rahega inner while end hua nhi outer while condition second<size chck nhi hogi to error ayega
*/



Key Differences Between the Two:
//Logic 1:
if (count[s[first]] == 1) {
    diff++;
}
count[s[first]]--;

What it does: This checks if the character at first is the last occurrence in the current window (i.e., count[s[first]] == 1 before decrementing). If so, it increments diff, as removing this character would reduce the number of distinct characters in the window.
Drawback: This logic is slightly less intuitive because it separates the check (if (count[s[first]] == 1)) and the actual decrement (count[s[first]]--). While correct, it’s harder to follow, especially when reasoning through the code flow.


//Logic 2:
count[s[first]]--;
if (count[s[first]] == 0) {
    diff++;
}

What it does: This reduces the count of s[first] first and then checks if it has dropped to 0. If so, it updates diff to reflect that the substring has lost a distinct character.
Why it’s better: This logic is simpler and more natural, as it follows a cause-and-effect sequence:
First, remove the character from the window (count[s[first]]--).
Then check if this removal made the character absent (count[s[first]] == 0).
Update diff if necessary.
