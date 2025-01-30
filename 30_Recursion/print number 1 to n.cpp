//void ie not return value
void printNumbers(int n) {
    if (n == 0) {
        return; // Base case
    }
    printNumbers(n - 1);  // Recursive call
    cout << n << " ";     // Print the current number after recursion
}

//int as the return type
int printNumbers(int n) {
    if (n == 0) {
        return 0; // Base case: stop recursion
    }
    int prev = printNumbers(n - 1); // Recursive call first
    cout << n << " ";               // Print after recursion (ensuring ascending order)
    return prev + 1;                // Return count of numbers printed (optional) nothing much as the fng having a int return type thats y 
}
