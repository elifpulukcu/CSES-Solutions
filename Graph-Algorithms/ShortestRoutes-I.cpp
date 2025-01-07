#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

class Solution {
public:
    void solve() {
        int n, m;
        cin >> n >> m;
        
        vector<vector<pair<int,ll>>> adj(n+1);
        for(int i = 0; i < m; i++) {
            int a, b;
            ll c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
        }
        
        vector<ll> dist(n+1, 1e18);
        dist[1] = 0;
        
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0, 1});
        
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if(d > dist[u]) continue;
            
            for(auto [v, w] : adj[u]) {
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            cout << dist[i] << " ";
        }
        cout << endl; // Satır sonu eklendi
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution solution;
    solution.solve();
    
    return 0;
}