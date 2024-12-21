/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1094

   Problem: Increasing Array
   Description:
   You are given an array of n integers which must be transformed into a non-decreasing array.
   On each move, you may increase the value of any single element by one.
   The goal is to minimize the total number of such moves.

   Time Complexity:
   O(n). The algorithm iterates through the array once, comparing each element to the previous one.

   Space Complexity:
   O(1). Only a constant amount of extra memory is used (to store the current and previous element values).
 */

#include <iostream>    
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long moves = 0;
    long long previous;
    cin >> previous;

    for (long long i = 1; i < n; i++) {
        long long current;
        cin >> current;
        if (current < previous) {
            moves += (previous - current);
        } else {
            previous = current;
        }
    }

    cout << moves << "\n";
    return 0;
}
