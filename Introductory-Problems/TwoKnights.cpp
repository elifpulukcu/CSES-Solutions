/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1072

   Problem: Two Knights
   Description:
   For each k from 1..n, compute the number of ways to place two knights
   on a k x k chessboard so that they do not attack each other.

   Time Complexity:
   O(n). We iterate from 1 to n once, computing the number of valid placements per k.

   Space Complexity:
   O(1). Only a small fixed set of variables are used for each calculation.
 */

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    for (long long k = 1; k <= n; k++) {
        // Total ways to place 2 knights
        long long totalWays = (k * k) * (k * k - 1) / 2;

        // Attacking positions for two knights
        long long attackingWays = 0;
        if (k > 2) {
            attackingWays = 4LL * (k - 1) * (k - 2);
        }

        cout << (totalWays - attackingWays) << "\n";
    }

    return 0;
}
