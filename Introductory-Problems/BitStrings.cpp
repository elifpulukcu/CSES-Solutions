/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1617

   Problem: Bit Strings
   Description:
   Calculate the number of bit strings of length n. The result should be
   given modulo 10^9 + 7.

   Time Complexity:
   O(log n). We use fast exponentiation (binary exponentiation) to compute 2^n mod (10^9 + 7).

   Space Complexity:
   O(1). Only a few variables are required.
*/

#include <iostream>
using namespace std;

static const long long MOD = 1000000007;

// Fast exponentiation to compute (base^exp) % MOD
long long modExp(long long base, long long exp, long long m) {
    long long result = 1;
    base = base % m;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    // Number of bit strings of length n is 2^n (mod 10^9+7).
    cout << modExp(2, n, MOD) << "\n";
    return 0;
}
