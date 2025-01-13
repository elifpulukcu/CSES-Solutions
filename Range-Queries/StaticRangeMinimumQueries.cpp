/*
    CSES Problem Set
    Link: https://cses.fi/problemset/task/1647

    Problem: Static Range Minimum Queries (RMQ)

    Description:
    We have an array of n integers and need to process q queries. Each query provides 
    two integers L and R, and we must return the minimum value in the subarray [L, R].
    The array is static: there are no updates to the elements after initial input.

    Approach (Sparse Table):
    1. We use a Sparse Table data structure st[i][k], where:
       - st[i][0] = arr[i].
       - st[i][k] = min(st[i][k-1], st[i + 2^(k-1)][k-1]) for k >= 1.
    2. Building the Sparse Table takes O(n log n) time.
    3. For each query [L, R]:
       - Let length = R - L + 1.
       - Let k = floor(log2(length)).
       - The minimum is min(st[L][k], st[R - 2^k + 1][k]).
       This query is O(1) because it just uses two table lookups and a comparison.

    Time Complexity:
    - Building st: O(n log n).
    - Each query: O(1).
    - Total: O(n log n + q).

    Space Complexity:
    - We store st[i][k] for i in [1..n], k in [0..log2(n)], which is O(n log n) memory.
    - The array arr itself takes O(n).

    Note:
    - Sparse Table is ideal for static range queries where the array does not change.
    - If we had dynamic updates, we would need a Segment Tree or Fenwick Tree (but for min, 
      Segment Tree is more common).
*/

#include <iostream>   
#include <vector>     
#include <algorithm>  
#include <cmath>      
#include <climits>    

using namespace std;

static const int MAXN = 200000;
static const int LOGN = 18; 

long long st[MAXN+1][LOGN+1]; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> arr(n+1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    // st[i][0] = arr[i]
    for(int i = 1; i <= n; i++){
        st[i][0] = arr[i];
    }

    for(int k = 1; (1 << k) <= n; k++){
        for(int i = 1; i + (1 << k) - 1 <= n; i++){
            st[i][k] = min(st[i][k-1], st[i + (1 << (k-1))][k-1]);
        }
    }

    while(q--){
        int L, R;
        cin >> L >> R;
        int length = R - L + 1;
        // Compute k = floor(log2(length)) efficiently
        int k = 31 - __builtin_clz(length);
        long long ans = min(st[L][k], st[R - (1 << k) + 1][k]);
        cout << ans << "\n";
    }

    return 0;
}
