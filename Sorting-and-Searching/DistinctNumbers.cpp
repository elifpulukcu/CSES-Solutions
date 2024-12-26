/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1621

   Problem: Distinct Numbers

   Description:
   You are given n integers. Your task is to count how many distinct values exist among them.

   Approach:
   1. Read the integer n.
   2. Read n integers into a data structure (e.g., an unordered_set or set).
   3. The answer is simply the size of this set, which represents the count of unique values.

   Time Complexity:
   O(n) on average when using an unordered_set (amortized insertion).

   Space Complexity:
   O(n), since we need to store all n integers in a set.
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    unordered_set<long long> s;
    s.reserve(n); // optional rehash optimization
    
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
    return 0;
}
