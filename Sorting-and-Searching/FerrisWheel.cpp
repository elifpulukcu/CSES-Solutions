/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1090

   Problem: Ferris Wheel

   Description:
   We have n children, each with a certain weight. A Ferris wheel has gondolas, 
   each of which can hold at most two children, subject to a maximum allowed total weight x. 
   The goal is to minimize the number of gondolas needed to seat all children.

   Approach:
   1. Read the integer n and the maximum capacity x.
   2. Store the weights of the n children in a vector and sort it in non-decreasing order.
   3. Use two pointers: 
      - 'left' starting at the beginning (lightest child),
      - 'right' starting at the end (heaviest child).
   4. If the sum of w[left] and w[right] is <= x, we can seat them together, so move both pointers (left++, right--).
      Otherwise, seat only the heaviest child (right--).
   5. Each iteration corresponds to using one gondola.
   6. Continue until all children are seated.
   7. Print the total number of gondolas.

   Time Complexity:
   O(n log n), due to sorting the children’s weights. 
   The two-pointer process itself is O(n).

   Space Complexity:
   O(n), for storing the list of weights.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> w(n);
    
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    
    int left = 0, right = n - 1;
    int gondolas = 0;
    
    while(left <= right){
        if(w[left] + w[right] <= x){
            left++;
            right--;
        } else {
            right--;
        }
        gondolas++;
    }
    
    cout << gondolas << "\n";
    return 0;
}
