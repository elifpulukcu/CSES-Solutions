/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/2205

   Problem: Gray Code
   Description:
   Given an integer n (1 <= n <= 16), generate all 2^n distinct bit strings of length n such that
   any two consecutive strings differ in exactly one bit (i.e., their Hamming distance is 1).
   We can output any valid Gray code ordering.

   Approach (Reflect-and-Prefix Method):
   1. Base case: If n = 1, the Gray code is ["0", "1"].
   2. Recursively build the Gray code for n-1 bits.
   3. Make a copy of the existing list and reverse it.
   4. Prefix each element of the original list with "0", and each element of the reversed list with "1".
   5. Concatenate the reversed list to the original one to form the final Gray code of size 2^n.

   Time Complexity:
   O(n * 2^n).
   There are 2^n code words, each of length n, and constructing/printing them requires O(n) per word.

   Space Complexity:
   O(n * 2^n).
   We store all 2^n bit strings in a vector. Each string can have length up to n.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void generateGrayCode(int n, vector<string>& result) {
    if (n == 1) {
        result.push_back("0");
        result.push_back("1");
        return;
    }
    // Recursively generate for (n-1)
    generateGrayCode(n - 1, result);

    // Reflect the existing list
    vector<string> reversedPart = result;
    reverse(reversedPart.begin(), reversedPart.end());

    // Prefix '0' to the original part
    for (int i = 0; i < (int)result.size(); i++) {
        result[i] = "0" + result[i];
    }
    // Prefix '1' to the reversed part
    for (int i = 0; i < (int)reversedPart.size(); i++) {
        reversedPart[i] = "1" + reversedPart[i];
    }

    // Append reversed part to the end
    result.insert(result.end(), reversedPart.begin(), reversedPart.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grayCode;
    grayCode.reserve((1 << n)); 
    generateGrayCode(n, grayCode);

    for (const auto &code : grayCode) {
        cout << code << "\n";
    }

    return 0;
}
