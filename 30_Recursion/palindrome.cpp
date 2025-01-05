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

    // Print the result
    if (n == reversed) {
        cout << n << " is a palindrome" << endl;
    } else {
        cout << n << " is not a palindrome" << endl;
    }
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
