/*
    CSES Problem Set
    Link: https://cses.fi/problemset/task/1668

    Problem: Building Teams

    Description:
    You are given n students (numbered 1..n) and m friendship relations between them.
    Your task is to split these students into two different teams such that no pair of friends
    end up in the same team. If this is not possible, print "IMPOSSIBLE".
    
    Essentially, this is a graph bipartite check problem:
    - Each student is a node in the graph.
    - Each friendship is an undirected edge between two nodes.
    If the graph is bipartite, print the team numbers for all students (1 or 2);
    otherwise, print "IMPOSSIBLE".

    Approach:
    1. Build an adjacency list for the n students.
    2. Use a color array colorArr[] of size n+1, initialized to 0 (uncolored).
       We will color them with 1 or 2 to represent the two teams.
    3. For each uncolored student i (colorArr[i] == 0), perform a BFS:
       - Color i with team 1.
       - For each neighbor v of i, if v is uncolored, color it with the opposite color.
         If it is already colored with the same color, bipartite condition fails -> print "IMPOSSIBLE" and stop.
    4. If no conflict is found, print the color assigned to each student.

    Time Complexity:
    O(n + m)
    We effectively visit every vertex and edge once in BFS.

    Space Complexity:
    O(n + m)
    We store the graph in adjacency lists and maintain an array of colors.

    Note:
    - The BFS-based bipartite check ensures a valid 2-coloring if it exists.
    - If any connected component cannot be 2-colored, we output "IMPOSSIBLE".
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int MAXN = 100000;
vector<int> adj[MAXN + 1];
int colorArr[MAXN + 1]; // 0: uncolored, 1 or 2 for two teams

bool bfsColor(int start) {
    queue<int> q;
    q.push(start);
    colorArr[start] = 1; // Assign the first node team 1

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (colorArr[v] == 0) {
                // Not colored yet, assign opposite color
                colorArr[v] = (colorArr[u] == 1 ? 2 : 1);
                q.push(v);
            }
            else if (colorArr[v] == colorArr[u]) {
                // Conflict: same team for adjacent nodes
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Initially, all vertices are uncolored (0)
    for(int i = 1; i <= n; i++) {
        colorArr[i] = 0;
    }

    // Perform BFS for each connected component
    for(int i = 1; i <= n; i++) {
        if(colorArr[i] == 0) {
            if(!bfsColor(i)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    // If successful, print the color of each student
    for(int i = 1; i <= n; i++) {
        cout << colorArr[i] << " ";
    }
    cout << "\n";

    return 0;
}
