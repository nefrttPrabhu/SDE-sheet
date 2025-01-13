//no return type
void isPalindromeHelper(int original, int& reversed, int n) {
    if (n == 0) {
        return; // Base case
    }
    reversed = reversed * 10 + (n % 10); // Build the reversed number
    isPalindromeHelper(original, reversed, n / 10); // Recursive call
}

void isPalindrome(int n) {
    int reversed = 0;
    isPalindromeHelper(n, reversed, n); // Helper function to reverse the number
    if (n == reversed) cout << n << " is a palindrome" << endl;
    }

//int return type
int reverseNumber(int n, int reversed = 0) {
    if (n == 0) {
        return reversed; // Base case: return the reversed number
    }
    return reverseNumber(n / 10, reversed * 10 + (n % 10)); // Recursive call
}

int isPalindrome(int n) {
    int reversed = reverseNumber(n); // Call the helper to reverse the number
    return n == reversed;            // Check if the number is a palindrome
}


//M2:
// Recursive function to check if the array is a palindrome
int isPalindrome(int i, int n, int arr[]) {
    // Base case: If all elements up to the middle are checked
    if (i >= n / 2)
        return 1;
    // If a mismatch is found
    if (arr[i] != arr[n - 1 - i])
        return -1;
    // Recursive check for the next elements
    return isPalindrome(i + 1, n, arr);
}

// Recursive function to check if the array is a palindrome
void isPalindrome(int i, int n, int arr[], bool &result) {
    // Base case: If all elements up to the middle are checked
    if (i >= n / 2 || !result) 
        return;

    // If a mismatch is found
    if (arr[i] != arr[n - 1 - i]) {
        result = false;
        return;
    }

    // Recursive check for the next elements
    isPalindrome(i + 1, n, arr, result);
}
