/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1070

   Problem: Permutations
   Description:
   A permutation of integers 1..n is called beautiful if no two adjacent elements differ by 1.
   Print any such permutation if it exists; otherwise, print "NO SOLUTION".

   Time Complexity:
   O(n). The solution prints the numbers in a single pass, first evens and then odds.

   Space Complexity:
   O(1). No additional data structures are used beyond a few loop variables.
 */

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }

    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
