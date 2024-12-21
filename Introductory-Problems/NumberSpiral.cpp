/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1071

   Problem: Number Spiral
   Description:
   We have an infinite 2D grid, starting with 1 at the top-left corner.
   For each query, output the value at position (y, x) following a defined spiral pattern.

   Time Complexity:
   O(t). Each query is answered in constant time.

   Space Complexity:
   O(1). Only a few variables are used to compute each cell's value.
 */

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long y, x;
        cin >> y >> x;
        long long answer = 0;

        // Determine the maximum of y and x, then use parity logic
        if (x >= y) {
            if (x % 2 == 1) {
                // Odd x
                answer = x * x - (y - 1);
            } else {
                // Even x
                answer = (x - 1) * (x - 1) + y;
            }
        } else {
            if (y % 2 == 0) {
                // Even y
                answer = y * y - (x - 1);
            } else {
                // Odd y
                answer = (y - 1) * (y - 1) + x;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
