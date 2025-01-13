/*
    CSES Problem Set
    Link: https://cses.fi/problemset/task/1646
    
    Problem: Static Range Sum Queries

    Description:
    We have an array of n integers (x1, x2, ..., xn) and we need to process q queries.
    Each query gives us two integers a and b and asks: "What is the sum of the values 
    in the subarray [a, b]?".
    
    Because the array is static (no updates to the array values), we can preprocess 
    a prefix sum array to answer each query in O(1) time.

    Approach:
    1. Read n and q.
    2. Read the array arr of size n.
    3. Build a prefix sum array "prefix" where:
         prefix[i] = prefix[i-1] + arr[i], for i = 1..n
       and define prefix[0] = 0 for convenience.
    4. For each query (a, b):
       - The sum in [a, b] is prefix[b] - prefix[a-1].
       - Print the result.

    Time Complexity:
    - Building the prefix sum array takes O(n).
    - Each of the q queries is answered in O(1).
    - Total time complexity: O(n + q).

    Space Complexity:
    - We store the original array arr in O(n).
    - We store the prefix sum array in O(n).
    - Total space complexity: O(n).

    Note:
    - By using prefix sums, we avoid recomputing sums repeatedly.
    - For 1 <= a <= b <= n, prefix[b] - prefix[a-1] always gives the sum 
      of the subarray arr[a..b].

*/

#include <iostream>   
#include <vector>     

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n+1), prefix(n+1, 0LL);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        long long ans = prefix[b] - prefix[a-1];
        cout << ans << "\n";
    }
    return 0;
}
