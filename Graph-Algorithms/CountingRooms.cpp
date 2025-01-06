/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1192

   Problem: Counting Rooms

   Description:
   You are given a grid of size n×m representing a building map. 
   Each cell is either '.' (floor) or '#' (wall). Two floor cells 
   belong to the same "room" if they are directly connected by an edge 
   (up, down, left, right). The task is to count how many distinct rooms 
   are in the building.

   Approach:
   1. Read integers n (rows) and m (columns).
   2. Read the grid as a vector of strings.
   3. Maintain a 2D visited array (n×m) initialized to false.
   4. Iterate over every cell. If the cell is '.' (floor) and not visited:
        - Increment rooms counter (we found a new room).
        - Perform a BFS (or DFS) from this cell to mark all connected floor cells
          in the same room as visited.
   5. After the loops finish, print the number of rooms.

   Time Complexity:
   O(n * m)
   Each cell is visited at most once in BFS/DFS, giving O(n*m) overall.

   Space Complexity:
   O(n * m)
   We store the grid of size n×m and a visited matrix of the same size.
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int rooms = 0;

    // 4-directional movement
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    // BFS Lambda
    auto bfs = [&](int sx, int sy) {
        queue<pair<int,int>> q;
        q.push({sx, sy});
        visited[sx][sy] = true;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(!visited[nx][ny] && grid[nx][ny] == '.'){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                rooms++;
                bfs(i, j);
            }
        }
    }

    cout << rooms << "\n";
    return 0;
}
