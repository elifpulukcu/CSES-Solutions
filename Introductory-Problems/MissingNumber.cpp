/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1083

   Problem: Missing Number
   Description:
   You are given all integers from 1 to n except for one missing integer.
   The task is to find that single missing integer.

   Time Complexity:
   O(n). Reading and summing the input (n-1) integers takes linear time.

   Space Complexity:
   O(1). Only a few variables are used to store partial sums and the result.
 */


#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n; cin >> n;
    int64_t sum_expected = n * (n + 1) / 2;
    int64_t sum_given = 0;

    for (int i = 0; i < n - 1; i++) {
        int64_t x; cin >> x;
        sum_given += x;
    }

    cout << (sum_expected - sum_given) << "\n";
    return 0;
}

