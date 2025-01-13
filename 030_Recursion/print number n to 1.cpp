//The function is declared as void fun(int n) so it does not return anything in the recursive case.
void printNumbers(int n) {
    if (n == 0) {
        return; // Base case
    }
    cout << n << " ";      // Print the current number before recursion
    printNumbers(n - 1);   // Recursive call
}



//The function is declared as int fun(int n) so it does return a int value in the recursive case. to the recursive cases and the main which calls it
int printNumbers(int n) {
    if (n == 0) {
        return 0; // Base case: stop recursion
    }
    cout << n << " ";               // Print the current number
    return printNumbers(n - 1) + 1; // Recursive call and return value
}


