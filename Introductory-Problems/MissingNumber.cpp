/*
 * Problem: Missing Number (CSES - https://cses.fi/problemset/task/1083)
 * ----------------------------------------------------------------------
 * Description:
 * You are given all the integers from 1 to n, except for one missing integer.
 * Your task is to determine which integer is missing.
 *
 * Input:
 * - The first line contains an integer n (2 <= n <= 2*10^5).
 * - The second line contains n-1 distinct integers in the range [1, n].
 *
 * Output:
 * Print the single missing integer.
 *
 * Example:
 * Input:
 * 5
 * 2 3 1 5
 * Output:
 * 4
 *
 * Idea:
 * A straightforward and efficient approach:
 * - The sum of the integers from 1 to n is n*(n+1)/2.
 * - By summing all the given (n-1) integers and subtracting from the total sum,
 *   we directly find the missing number.
 *
 * Complexity:
 * O(n) time to read the input and sum the values, which is acceptable for n up to 2*10^5.
 * Memory is O(1) aside from input storage (if read one-by-one).
 *
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

