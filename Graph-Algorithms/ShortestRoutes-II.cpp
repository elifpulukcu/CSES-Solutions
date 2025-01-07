#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class Solution {
public:
   void solve() {
       int n, m, q;
       cin >> n >> m >> q;
       
       vector<vector<ll>> dist(n+1, vector<ll>(n+1, 1e18));
       for(int i = 1; i <= n; i++) dist[i][i] = 0;
       
       for(int i = 0; i < m; i++) {
           int a, b; ll c;
           cin >> a >> b >> c;
           dist[a][b] = min(dist[a][b], c);
           dist[b][a] = min(dist[b][a], c);
       }
       
       // Floyd-Warshall
       for(int k = 1; k <= n; k++) {
           for(int i = 1; i <= n; i++) {
               for(int j = 1; j <= n; j++) {
                   if(dist[i][k] != 1e18 && dist[k][j] != 1e18) {
                       dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                   }
               }
           }
       }
       
       while(q--) {
           int a, b;
           cin >> a >> b;
           cout << (dist[a][b] == 1e18 ? -1 : dist[a][b]) << "\n";
       }
   }
};

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   
   Solution solution;
   solution.solve();
   
   return 0;
}