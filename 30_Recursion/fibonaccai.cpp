//no return type
void fibonacciHelper(int n, int& result) {

    if (n <= 1) {
        result = 1; // Base case for n = 1
        return;
    }
    int prev1 = 0, prev2 = 1; // Variables to store the previous two Fibonacci numbers
    fibonacciHelper(n - 1, prev1); // Recursive call for F(n-1)
    fibonacciHelper(n - 2, prev2); // Recursive call for F(n-2)
    result = prev1 + prev2; // Compute F(n) as F(n-1) + F(n-2)
}

//int return type
int fibonacci(int n) {
    if (n <= 1)
        return 1; // Base case for n = 1 & 0
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive call
}
