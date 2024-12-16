//The function is declared as void fun(int n) so it does not return anything in the recursive case.
void fun(int n) //here its a void so it does not need to return a value
{
    if (n == 0) {
        return; //this is the reason to have this Base case 
    }
    fun(n - 1);    // Recursive call
    cout << n << " "; // Print after the recursive call
}


//The function is declared as int fun(int n) so it does return a int value in the recursive case. to the recursive cases and the main which calls it
int fun(int n) {
    if (n == 0) {
        return 0; // Base case: stop recursion
    }
    int last = fun(n - 1); // Recursive call
    cout << n << " ";              // Print the current number after recursion
    return last + 1;               // Return control back to the previous call
}

int main() {
    int n = 5;                     // Set the value of n
    int result = fun(n);  // Call the recursive function
    cout << "\nControl returned to main with result: " << result << endl;
    return 0;
}
