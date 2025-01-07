#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const string dir = "URDL";

class Solution {
   int n, m;
   vector<vector<char>> grid;
   vector<vector<vector<bool>>> visited;
   pair<int,int> start;
   vector<pair<int,int>> monsters;
   
   bool isValid(int x, int y) {
       return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
   }
   
   bool isBoundary(int x, int y) {
       return x == 0 || x == n-1 || y == 0 || y == m-1;
   }
   
   bool bfs() {
       queue<pair<int,int>> q;
       queue<pair<int,int>> mq;
       vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m));
       vector<vector<char>> direction(n, vector<char>(m));
       
       q.push(start);
       for(auto& m : monsters) mq.push(m);
       
       vector<vector<int>> dist(n, vector<int>(m, 1e9));
       vector<vector<int>> mdist(n, vector<int>(m, 1e9));
       
       dist[start.first][start.second] = 0;
       for(auto& m : monsters) {
           if(m.first >= 0 && m.second >= 0)
               mdist[m.first][m.second] = 0;
       }
       
       while(!q.empty() || !mq.empty()) {
           // Monster movement
           int msize = mq.size();
           while(msize--) {
               auto [x, y] = mq.front();
               mq.pop();
               
               for(int i = 0; i < 4; i++) {
                   int nx = x + dx[i];
                   int ny = y + dy[i];
                   
                   if(isValid(nx, ny) && mdist[nx][ny] == 1e9) {
                       mdist[nx][ny] = mdist[x][y] + 1;
                       mq.push({nx, ny});
                   }
               }
           }
           
           // Player movement
           int size = q.size();
           while(size--) {
               auto [x, y] = q.front();
               q.pop();
               
               if(isBoundary(x, y) && dist[x][y] < mdist[x][y]) {
                   vector<char> path;
                   int cx = x, cy = y;
                   while(cx != start.first || cy != start.second) {
                       path.push_back(direction[cx][cy]);
                       auto [px, py] = parent[cx][cy];
                       cx = px; cy = py;
                   }
                   
                   cout << "YES\n" << path.size() << "\n";
                   for(int i = path.size()-1; i >= 0; i--)
                       cout << path[i];
                   cout << "\n";
                   return true;
               }
               
               for(int i = 0; i < 4; i++) {
                   int nx = x + dx[i];
                   int ny = y + dy[i];
                   
                   if(isValid(nx, ny) && dist[nx][ny] == 1e9 && dist[x][y] + 1 < mdist[nx][ny]) {
                       dist[nx][ny] = dist[x][y] + 1;
                       parent[nx][ny] = {x, y};
                       direction[nx][ny] = dir[i];
                       q.push({nx, ny});
                   }
               }
           }
       }
       return false;
   }

public:
   void solve() {
       cin >> n >> m;
       grid.resize(n, vector<char>(m));
       
       for(int i = 0; i < n; i++) {
           for(int j = 0; j < m; j++) {
               cin >> grid[i][j];
               if(grid[i][j] == 'A') start = {i, j};
               else if(grid[i][j] == 'M') monsters.push_back({i, j});
           }
       }
       
       if(!bfs()) cout << "NO\n";
   }
};

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   
   Solution solution;
   solution.solve();
   
   return 0;
}