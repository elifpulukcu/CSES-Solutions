/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1633

   Problem: Dice Combinations

   Description:
   We want to find the total number of ways to form a sum n by rolling a six-sided die 
   (with faces 1 through 6) any number of times. Each way is counted distinctly based 
   on the sequence of faces. The answer should be given modulo 10^9 + 7.

   Approach:
   1. Read integer n.
   2. Use a 1D dynamic programming array dp of size (n+1).
      - dp[i] will store the number of ways to form the sum i.
   3. Base case: dp[0] = 1, meaning there is exactly one way to achieve sum 0 (by using no dice).
   4. For each i from 1 to n:
      - For each possible die face from 1 to 6, if i - face >= 0, 
        add dp[i - face] to dp[i] (mod 10^9 + 7).
   5. Output dp[n] as the final answer.

   Time Complexity:
   O(n) 
   We iterate from 1 to n, and within that loop, we do up to 6 constant operations.

   Space Complexity:
   O(n)
   We maintain a dp array of size (n+1).
*/

#include <iostream>
#include <vector>
using namespace std;

static const int MOD = 1000000007; // for (10^9) + 7

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> dp(n+1, 0LL);
    dp[0] = 1; // Base case

    for (int i = 1; i <= n; i++) {
        for (int face = 1; face <= 6; face++) {
            if (i - face >= 0) {
                dp[i] = (dp[i] + dp[i - face]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
