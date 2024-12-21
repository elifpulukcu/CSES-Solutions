/*
   CSES Problem Set - Repetitions
   Link: https://cses.fi/problemset/task/1069

   Problem: Repetitions
   Description:
   You are given a DNA sequence consisting of characters A, C, G, and T.
   Determine the length of the longest contiguous substring of repeating characters.

   Time Complexity:
   O(n). The algorithm traverses the string once, updating the longest repetition count.

   Space Complexity:
   O(1). Only constant extra variables are needed for tracking the current and maximum repeats.
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dna;
    cin >> dna;

    int maxCount = 1;
    int currentCount = 1;
    char prev = dna[0];

    for (int i = 1; i < (int)dna.size(); ++i) {
        if (dna[i] == prev) {
            currentCount++;
        } else {
            currentCount = 1;
        }
        prev = dna[i];
        maxCount = max(maxCount, currentCount);
    }

    cout << maxCount << "\n";
    return 0;
}

