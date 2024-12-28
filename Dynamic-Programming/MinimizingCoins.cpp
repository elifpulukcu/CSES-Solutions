/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1634

   Problem: Minimizing Coins

   Description:
   - You have n distinct coin denominations and a target sum x.
   - You need to determine the minimum number of coins required to form x.
   - If it is not possible to form x using any combination of these coins, print -1.

   Approach:
   1. Read the integers n (number of coins) and x (target sum).
   2. Read the list of coin values into a vector.
   3. Create a DP array dp of size x+1, initialized to a large value (INF).
   4. Base case: dp[0] = 0 (0 coins are needed to make sum 0).
   5. For each sum i from 1 to x:
      - For each coin c in coins, if (i - c) >= 0 and dp[i - c] != INF, 
        then dp[i] = min(dp[i], dp[i - c] + 1).
   6. If dp[x] is still INF, output -1; otherwise output dp[x].

   Time Complexity:
   O(n * x), where n is the number of coins and x is the target sum.
   - We iterate over each of the x sums, and for each sum, we iterate over n coins.

   Space Complexity:
   O(x), for storing the dp array of size (x+1).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    const int INF = 1000000000; 
    vector<int> dp(x + 1, INF);
    dp[0] = 0;  // Base case: 0 coins to form sum 0

    for(int i = 1; i <= x; i++){
        for(int c : coins){
            if(i - c >= 0 && dp[i - c] != INF){
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    if(dp[x] == INF) cout << -1 << "\n";
    else cout << dp[x] << "\n";

    return 0;
}
