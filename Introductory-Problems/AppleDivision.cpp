/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1623

   Problem: Apple Division
   Description:
   We have n apples (1 <= n <= 20), each with a certain weight p_i.
   The goal is to split these apples into two groups such that the difference
   of their total weights is minimized. We need to output this minimal difference.

   Approach (Bitmask Subset Enumeration):
   1. Compute the total sum of all apple weights.
   2. Iterate over all possible subsets (2^n combinations).
   3. For each subset, calculate its sum. Let the complement subset's sum be (total - subsetSum).
      The difference = |subsetSum - (total - subsetSum)| = |total - 2*subsetSum|.
   4. Track the minimum such difference over all subsets.

   Since n <= 20, 2^n can be up to 1,048,576, which is computationally feasible.

   Time Complexity:
   O(2^n * n). We check each of the 2^n subsets, and summing up to n apples in each subset.

   Space Complexity:
   O(1) or O(n) auxiliary, aside from the input storage. We only store partial sums on-the-fly.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long apples[20];
    long long totalWeight = 0;
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
        totalWeight += apples[i];
    }

    // Enumerate all subsets via bitmask
    long long minDiff = LLONG_MAX;
    // There are 2^n subsets, from 0 to (1 << n) - 1
    for (int mask = 0; mask < (1 << n); mask++) {
        long long subsetSum = 0;
        // Check each bit/apples[i]
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subsetSum += apples[i];
            }
        }
        long long currentDiff = llabs(totalWeight - 2LL * subsetSum);
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
        }
    }

    cout << minDiff << "\n";

    return 0;
}
