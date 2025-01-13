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
    cout << n << " ";               // Print the current number after recursion
    return printNumbers(n - 1) + 1; //Recursive call and Return control back to the previous call
}
