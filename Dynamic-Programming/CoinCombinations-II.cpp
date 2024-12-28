/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1636

   Problem: Coin Combinations II

   Description:
   You are given n distinct coin denominations and an integer x. You need to calculate 
   the number of ways to form the sum x, but now the order of coins does not matter. 
   For example, if x = 5 and coins are {1, 2}, 
   - the combination [1,2,2] is the same as [2,1,2] or [2,2,1] (i.e., we only consider 
     the distinct set of coins, not the sequence).

   Approach:
   1. Read integers n (number of distinct coins) and x (the target sum).
   2. Read the coin denominations into a vector.
   3. Create a dp array of size x+1, where dp[i] represents the number of ways 
      to form the sum i without regard to the order of coins.
   4. Base case: dp[0] = 1 (there is exactly one way to form the sum 0 — by using no coins).
   5. For each coin c in coins (outer loop):
        For each total i from c to x (inner loop):
           dp[i] = (dp[i] + dp[i - c]) % MOD
      This ensures each combination is counted exactly once, 
      because we first fix one coin and build up from there.

   Time Complexity:
   O(n * x)
   - n coin denominations and we compute dp for each value from 1 to x in an inner loop.

   Space Complexity:
   O(x)
   - We keep a one-dimensional dp array of size x+1.
*/

#include <iostream>
#include <vector>
using namespace std;

static const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<long long> dp(x+1, 0LL);
    dp[0] = 1;

    for(int c : coins) {
        for(int i = c; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }

    cout << dp[x] << "\n";
    return 0;
}
