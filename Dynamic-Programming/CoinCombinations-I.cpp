/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1635

   Problem: Coin Combinations I

   Description:
   You are given n distinct coin denominations and an integer x. You need to calculate 
   the number of ways (order matters) to form the sum x using the given coins. 
   For instance, if x = 5 and coins are {1, 2}, 
   sequences like [1,2,2], [2,1,2], [2,2,1], [1,1,1,1,1], etc. count as distinct ways 
   if their order of coins is different.

   Approach:
   1. Read integers n (number of coins) and x (the target sum).
   2. Read the distinct coin denominations into a vector.
   3. Create a dp array of size x+1, where dp[i] represents the number of ways to form sum i.
   4. Base case: dp[0] = 1 (there is exactly one way to form sum 0 — using no coins).
   5. For each i from 1 to x:
        For each coin c:
           If i - c >= 0, then dp[i] += dp[i - c], taken modulo 10^9 + 7.
   6. Finally, print dp[x] as the result.

   Time Complexity:
   O(n * x)
   We iterate over all x values (1..x) and for each value, we iterate over n coins.

   Space Complexity:
   O(x)
   We use a one-dimensional dp array of size x+1.
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
    dp[0] = 1; // Base case: one way to form sum 0

    for(int i = 1; i <= x; i++){
        for(int c : coins){
            if(i - c >= 0){
                dp[i] = (dp[i] + dp[i - c]) % MOD;
            }
        }
    }

    cout << dp[x] << "\n";
    return 0;
}
