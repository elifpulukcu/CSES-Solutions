/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/2431

   Problem: Digit Queries
   Description:
   Consider an infinite string S formed by writing all positive integers in
   ascending order: "123456789101112131415...". For a given 1-indexed position k,
   determine which digit (0-9) is at that position in S.

   Approach:
   1. We observe that S is grouped by digit lengths:
      - All 1-digit numbers: 1..9 (9 numbers, total of 9*1 = 9 digits).
      - All 2-digit numbers: 10..99 (90 numbers, total of 90*2 = 180 digits).
      - All 3-digit numbers: 100..999 (900 numbers, total of 900*3 = 2700 digits).
      - In general, d-digit numbers: 9*10^(d-1) numbers, each with d digits, total = 9*10^(d-1)*d digits.
   2. Given k, we iterate over digit lengths d from 1 upwards and subtract the block sizes
      until we reach the block where k belongs. For example, if k is large, we skip 1-digit,
      2-digit blocks, etc., until k is within the d-digit block.
   3. Once we identify d, we have an offset from the start of that d-digit block.
      Let base = 10^(d-1) be the first d-digit number.
      - The offset in digits is (k - 1) (0-based).
      - The specific integer index offset is (k - 1) // d.
      - The digit index inside that number is (k - 1) % d.
      So the actual number is base + (k - 1) // d. We extract the needed digit from that number.
   4. Print the resulting digit.

   Complexity:
   - Time Complexity: O(q * log(k)) per query, but practically d <= 18 for 64-bit range (10^18).
     So each query takes about O(d) = O(18) steps, which is very efficient for q <= 1000.
   - Space Complexity: O(1). Only a few temporary variables are used for each query.
*/

#include <iostream> 
#include <string>     
using namespace std;
using namespace std;

long long findDigit(long long k) {
    // d = number of digits in the block
    long long d = 1;
    long long countInBlock = 9; // 9 * 10^(d-1)
    
    // 1) Identify the block (digit length) where k belongs
    while (true) {
        long long blockSize = countInBlock * d; // total digits in the d-digit block
        if (k <= blockSize) {
            // k is in this d-digit block
            break;
        }
        k -= blockSize;  // skip this entire block
        d++;
        countInBlock *= 10; // next block has 10x more numbers (e.g., 9 -> 90 -> 900 -> 9000)
    }
    
    // 2) Now, k (1-indexed) is within the d-digit block
    // 'base' is the first d-digit number, e.g. d=2 => 10, d=3 => 100 ...
    long long base = 1;
    for (int i = 1; i < d; i++) {
        base *= 10LL;
    }
    
    // offset in 0-based indexing
    long long offset = k - 1; 
    // which number inside the d-digit block
    long long numberIndex = offset / d; 
    // digit inside that specific number
    long long digitIndex = offset % d;  
    
    // actual number
    long long number = base + numberIndex;
    // convert to string to extract the specific digit
    string s = to_string(number);
    
    // s[digitIndex] is the character we want
    return s[digitIndex] - '0'; // convert char to int
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        cout << findDigit(k) << "\n";
    }
    return 0;
}
