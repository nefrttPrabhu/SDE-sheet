//no return type
void factorialHelper(int n, int& result) {
    if (n == 0 || n == 1) {
        result = 1; // Base case
        return;
    }
    result *= n; // Multiply result by the current number
    factorialHelper(n - 1, result); // Recursive call
}

//int return type
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    }
    return n * factorial(n - 1); // Recursive call
}
