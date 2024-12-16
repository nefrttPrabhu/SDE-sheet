//The function is declared as void fun(int n) so it does not return anything in the recursive case.
void printNumbers(int n) {
    if (n == 0) {
        return; // Base case
    }
    cout << n << " ";      // Print the current number before recursion
    printNumbers(n - 1);   // Recursive call
}

int main() {
    int n = 5;
    printNumbers(n);       // Call the recursive function
    cout << endl;
    return 0;
}


//The function is declared as int fun(int n) so it does return a int value in the recursive case. to the recursive cases and the main which calls it
int printNumbers(int n) {
    if (n == 0) {
        return 0; // Base case: stop recursion
    }
    int last = printNumbers(n - 1); // Recursive call
    cout << n << " ";              // Print the current number after recursion
    return last + 1;               // Return control back to the previous call
}

int main() {
    int n = 5;                     // Set the value of n
    int result = printNumbers(n);  // Call the recursive function
    cout << "\nControl returned to main with result: " << result << endl;
    return 0;
}
