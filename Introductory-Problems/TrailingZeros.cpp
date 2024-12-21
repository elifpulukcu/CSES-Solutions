/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1618

   Problem: Trailing Zeros
   Description:
   Given an integer n, calculate the number of trailing zeros in n! (factorial of n).

   Time Complexity:
   O(log n). We repeatedly divide n by 5, 5^2, 5^3, ... until n/(5^k) becomes zero.

   Space Complexity:
   O(1). Only a fixed set of variables are used to count the factors of 5.
*/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long countZeros = 0;
    long long divisor = 5;
    while (divisor <= n) {
        countZeros += (n / divisor);
        divisor *= 5;
    }

    cout << countZeros << "\n";
    return 0;
}
