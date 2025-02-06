class Solution {
public:
    void find(int row, int col, vector<vector<char>>& board, vector<bool>& a){
        int rows = (row/3)*3;
        int cols = (col/3)*3;
        for(int j = 0; j < 9; j++){
            if(board[row][j] != '.'){
                a[board[row][j] - '1'] = 0;
            }
        }
        for(int i = 0; i < 9; i++){
            if(board[i][col] != '.'){
                a[board[i][col] - '1'] = 0;
            }
        }
        for(int i = rows; i < rows + 3; i++){
            for(int j = cols; j < cols + 3; j++){
                if(board[i][j] != '.'){
                    a[board[i][j] - '1'] = 0;
                }
            }
        }
    }
    bool grid(int row, int col, vector<vector<char>>& board){
        if(row == 9){
            return true;
        }
        if(col == 9){
            return grid(row + 1, 0, board);
        }
        else if(board[row][col] == '.'){
            vector<bool> a(9, 1);  // vector containing valid numbers using a vector.
            find(row, col, board, a);
            for(int i = 0; i < 9; i++){
                if(a[i]){
                    board[row][col] = char(i + '1');
                    if(grid(row, col + 1, board)){
                        return true;
                    }
                    board[row][col] = '.';
                }
            }
        }
        else{
            return grid(row, col + 1, board);
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        grid(0, 0, board);
    }
};
