//personal method jaise code ekek row ke liye likha tha row ke liye alag fng banado then row number bhejte jao or triangle row print hoti jayengi
#include <bits/stdc++.h>
using namespace std;

void fun(int row) {
    int ans = 1; // Initialize the first element
    for (int i = 0; i <= row; i++) { 
        cout << ans << " "; 
        ans = ans * (row - i) / (i + 1); // Compute the next element in the row
    }
    cout << endl; // Move to the next row
}

int main() {
    int n;
    cin >> n; // Input number of rows
    for (int row = 0; row < n; row++) { 
        fun(row); // Pass the current row to `fun`
    }
    return 0;
}



// Brute force
int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}



// optimal
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}
