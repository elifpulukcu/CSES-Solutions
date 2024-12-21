/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1754

   Problem: Coin Piles
   Description:
   We have two piles of coins containing a and b coins respectively. A move consists of
   removing (1 coin from the first pile and 2 from the second) or (2 from the first pile
   and 1 from the second). Determine if both piles can be emptied simultaneously.

   Conditions for "YES":
   - (a + b) % 3 == 0
   - max(a, b) <= 2 * min(a, b)

   Time Complexity:
   O(t). For t test cases, each check is done in constant time.

   Space Complexity:
   O(1). We only store a few variables per test.
*/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        if ((a + b) % 3 == 0 && max(a, b) <= 2 * min(a, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
