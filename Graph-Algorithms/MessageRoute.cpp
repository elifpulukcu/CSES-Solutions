/*
    CSES Problem Set
    Link: https://cses.fi/problemset/task/1667

    Problem: Message Route

    Description:
    We have an undirected graph with n vertices (labeled 1 to n) and m edges.
    We need to find a path from vertex 1 (Uolevi's computer) to vertex n (Maija's computer).
    If such a path exists, we should output the minimum number of computers on that path 
    (including both endpoints), followed by one example of such a route. 
    If no path exists, print "IMPOSSIBLE".

    Approach (BFS):
    1. Read n (number of vertices) and m (number of edges).
    2. Build an adjacency list (adj) of size n+1 to store the graph.
    3. Create a visited array and a parentArr array, both of size n+1, initialized appropriately.
    4. Perform a BFS starting from node 1:
       - Mark node 1 as visited and enqueue it.
       - While the queue is not empty:
          - Dequeue the front node u.
          - If u == n, we can stop BFS early because we’ve reached the destination.
          - Otherwise, for each neighbor v of u, 
            if it is not visited, mark it visited, record u as its parent, and enqueue v.
    5. After BFS, if node n is not visited, print "IMPOSSIBLE".
       Otherwise, reconstruct the path by following parentArr[] from n backward until -1.
       Reverse that path, and print its length and the nodes in order.

    Time Complexity:
    O(n + m)
    We do a BFS once, which visits each vertex and edge at most once.

    Space Complexity:
    O(n + m)
    We store the graph in an adjacency list and use arrays of size n+1 for visited and parentArr.

    Note:
    - The BFS ensures the path found from 1 to n is of shortest length in terms of number of edges.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static const int MAXN = 100000;
vector<int> adj[MAXN + 1];
bool visited[MAXN + 1];
int parentArr[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        parentArr[i] = -1;
        visited[i] = false;
    }

    // BFS
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == n) break; // destination reached

        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                parentArr[v] = u;
                q.push(v);
            }
        }
    }

    // If n is not visited, no path exists
    if(!visited[n]){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct the path
    vector<int> path;
    int cur = n;
    while(cur != -1){
        path.push_back(cur);
        cur = parentArr[cur];
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(int node : path){
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
