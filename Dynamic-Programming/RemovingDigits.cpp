/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1637

   Problem: Removing Digits

   Description:
   You have a positive integer n. In each step, you may choose one of its digits d (d > 0) 
   and subtract d from n. The goal is to reach 0 in the minimum possible number of steps. 
   For instance, if n = 27, you can first subtract 7 → 20, then subtract 2 → 18, and so on, 
   until you reach 0.

   Approach:
   1. We use dynamic programming where dp[i] represents the minimum number of steps 
      to reduce i to 0.
   2. Initialize dp[0] = 0, meaning 0 steps are needed to stay at 0.
   3. For each integer i from 1 to n:
      - Extract each digit d of i.
      - If d > 0, update dp[i] = min(dp[i], dp[i - d] + 1).
      - dp array starts with large values (e.g. INT_MAX), so each step ensures the 
        minimum is recorded.
   4. Finally, dp[n] holds the minimum steps to go from n to 0.

   Time Complexity:
   O(n * log(n))
   - For each i from 1 to n, we extract its digits. Extracting digits takes O(log(i)) steps 
     in the worst case. Summed over i=1..n, this is roughly O(n log n).

   Space Complexity:
   O(n)
   - We keep a dp array of size n+1.
*/

#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int temp = i;
        // Extract digits of i
        while(temp > 0){
            int d = temp % 10;
            temp /= 10;
            if(d > 0 && i - d >= 0) {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
