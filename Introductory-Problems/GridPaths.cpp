/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1625

   Problem: Grid Paths
   Description:
   We have a 7x7 grid. The path starts at the top-left cell (row=0, col=0) and 
   must end at the bottom-left cell (row=6, col=0) after exactly 48 moves without 
   revisiting any cell. Each move is one step up (U), down (D), left (L), or right (R).
   The input is a 48-character string where each character is either:
       - 'D', 'U', 'L', 'R' (a fixed direction), or
       - '?' (meaning any of the four directions is allowed if valid).
   We want to count how many distinct self-avoiding paths match the given partial pattern.

   Approach (Backtracking / DFS):
   1. We maintain a visited array (7x7) for cells. Start from (0,0) visited.
   2. At step i (0 <= i < 48), look at the i-th character of the pattern:
      - If it is 'D', 'U', 'L', or 'R', attempt only that direction.
      - If it is '?', try all four directions.
   3. For each direction, check if:
      - The move stays within the 7x7 grid,
      - The target cell is not yet visited.
   4. If valid, mark the new cell visited, recurse to step (i+1).
      Then backtrack by unmarking the cell.
   5. If i == 48, check whether the current cell is (6,0). If yes, increment a global counter.

   Time Complexity:
   Potentially up to 4^48 in the worst naive scenario, but heavy pruning (visits out-of-bounds 
   or repeated cells) drastically reduces the actual search space. For a 7x7 board, the 
   maximum path length is 48 steps, so typical backtracking with pruning is feasible.

   Space Complexity:
   O(7*7) = O(49) for the visited grid plus recursion depth up to 48. So O(1) or O(48) 
   additional memory, effectively constant with respect to input constraints.
*/

#include <iostream>
#include <string>
using namespace std;

static const int N = 7;        // 7x7 grid
bool visited[N][N];
long long totalPaths = 0;
string pattern;

// Movements: D, U, L, R
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// Corresponding chars
char dirChar[4] = {'D', 'U', 'L', 'R'};

void backtrack(int step, int r, int c) {
    // If we have used all 48 steps
    if (step == 48) {
        // Check if we are at the bottom-left cell
        if (r == 6 && c == 0) {
            totalPaths++;
        }
        return;
    }

    char cmd = pattern[step];
    // We'll try either the single direction if cmd != '?', or all 4 if cmd == '?'
    if (cmd != '?') {
        int idx = -1;
        // Find which direction index matches cmd
        for (int i = 0; i < 4; i++) {
            if (dirChar[i] == cmd) {
                idx = i;
                break;
            }
        }
        // Attempt this single direction if valid
        int nr = r + dx[idx];
        int nc = c + dy[idx];
        // Check boundaries & visited
        if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
            visited[nr][nc] = true;
            backtrack(step + 1, nr, nc);
            visited[nr][nc] = false;
        }
    } else {
        // Try all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
                visited[nr][nc] = true;
                backtrack(step + 1, nr, nc);
                visited[nr][nc] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> pattern; // 48-character input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    // Mark starting cell visited: (0,0)
    visited[0][0] = true;
    // Start backtracking from step 0, at row=0, col=0
    backtrack(0, 0, 0);

    cout << totalPaths << "\n";
    return 0;
}
