#include <iostream>
#define N 4
using namespace std;

bool IsSafe(int board[N][N], int row, int col) {
    // check vertiacal ( will start from previous row)
    for (int i = row - 1, j = col; i >= 0; i--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // check left digonal
    for (int i = row - 1, j = col -1; i >= 0 && j >= 0 ; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // check right digonal
    for (int  i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool NQueen(int board[N][N], int row) {
    // base condition 
    if (row == N) {
        return true;
    }

    // check all the column 
    for (int col = 0; col < N; col++)
    {
        // check if the queen can be plced
        if (IsSafe(board, row, col)) {
            // update the entry
            board[row][col] = 1;
            if (NQueen(board, row + 1))
                return true;
            // if place not available then reset the position
            board[row][col] = 0;
        }
    }
    // when no suitabel positon is found
    return false;
}

int main()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                         };
    NQueen(board, 0);
    // print the vector
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        printf("\n");
    }
}
