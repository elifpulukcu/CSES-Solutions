#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

class Solution {
public:
   void solve() {
       int n, m;
       cin >> n >> m;
       
       vector<vector<pair<int,ll>>> adj(n+1);
       for(int i = 0; i < m; i++) {
           int a, b; ll x;
           cin >> a >> b >> x;
           adj[a].push_back({b, x});
       }
       
       // Check for positive cycle reachable from 1 to n
       vector<ll> dist(n+1, -1e18);
       vector<int> cnt(n+1, 0);
       vector<bool> inqueue(n+1, false);
       queue<int> q;
       
       dist[1] = 0;
       q.push(1);
       inqueue[1] = true;
       
       while(!q.empty()) {
           int u = q.front();
           q.pop();
           inqueue[u] = false;
           
           for(auto [v, w] : adj[u]) {
               if(dist[v] < dist[u] + w) {
                   dist[v] = dist[u] + w;
                   cnt[v] = cnt[u] + 1;
                   
                   if(cnt[v] >= n) {
                       if(canReachN(v, n, adj)) {
                           cout << -1 << endl;
                           return;
                       }
                   }
                   
                   if(!inqueue[v]) {
                       q.push(v);
                       inqueue[v] = true;
                   }
               }
           }
       }
       
       cout << dist[n] << endl;
   }
   
private:
   bool canReachN(int start, int n, vector<vector<pair<int,ll>>>& adj) {
       vector<bool> visited(n+1, false);
       queue<int> q;
       q.push(start);
       visited[start] = true;
       
       while(!q.empty()) {
           int u = q.front();
           q.pop();
           
           if(u == n) return true;
           
           for(auto [v, w] : adj[u]) {
               if(!visited[v]) {
                   visited[v] = true;
                   q.push(v);
               }
           }
       }
       
       return false;
   }
};

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   
   Solution solution;
   solution.solve();
   
   return 0;
}