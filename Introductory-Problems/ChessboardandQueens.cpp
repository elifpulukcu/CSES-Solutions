/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1624

   Problem: Chessboard and Queens
   Description:
   We have an 8x8 chessboard with some squares reserved (*) and some free (.).
   We must place 8 queens on the free squares so that no two queens attack each other,
   and reserved squares cannot hold a queen. We want to count how many distinct ways
   there are to place all 8 queens under these conditions.

   Approach (Backtracking):
   1. Read the board, store which squares are free or reserved.
   2. We attempt to place one queen per row in a valid column.
   3. A column is valid if:
      - It is not already occupied by another queen.
      - The square is not reserved.
      - No diagonal conflict with existing queens.
   4. We use three arrays (or bitmasks) to track used columns and diagonals:
      - colUsed[c] indicates if column c is occupied.
      - diag1Used[d1] for the "/" diagonals, where d1 = row + col.
      - diag2Used[d2] for the "\" diagonals, where d2 = row - col + (boardSize - 1).
   5. If we manage to place queens in all 8 rows, we increment a global counter.

   Time Complexity:
   O(8^8) in the worst naive sense (trying each column in each row), but in practice
   backtracking prunes heavily. For n=8, this is feasible within 1 second.

   Space Complexity:
   O(1) additional aside from the fixed arrays (since the board is 8x8 and we have a few
   boolean arrays for columns and diagonals). Recursion depth is 8 at most.
*/

#include <iostream>
#include <cstring>
using namespace std;

static const int N = 8;
bool colUsed[N], diag1Used[2*N - 1], diag2Used[2*N - 1];
char board[N][N];
long long ways = 0;

void backtrack(int row) {
    if (row == N) {
        // Successfully placed 8 queens
        ways++;
        return;
    }
    for (int col = 0; col < N; col++) {
        // If current square is free (.) and not under attack
        if (board[row][col] == '.' &&
            !colUsed[col] &&
            !diag1Used[row + col] &&
            !diag2Used[row - col + (N - 1)]) {

            // Place queen
            colUsed[col] = true;
            diag1Used[row + col] = true;
            diag2Used[row - col + (N - 1)] = true;

            backtrack(row + 1);

            // Remove queen (backtrack)
            colUsed[col] = false;
            diag1Used[row + col] = false;
            diag2Used[row - col + (N - 1)] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> board[r][c];
        }
    }

    memset(colUsed, false, sizeof(colUsed));
    memset(diag1Used, false, sizeof(diag1Used));
    memset(diag2Used, false, sizeof(diag2Used));

    // Start backtracking from row 0
    backtrack(0);

    cout << ways << "\n";

    return 0;
}
