/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1084

   Problem: Apartments

   Description:
   You are given n desired apartment sizes by n applicants and m actual apartment sizes. 
   Each applicant will accept an apartment if its size does not differ by more than k 
   from their desired size. Determine the maximum number of applicants that can get a suitable apartment.

   Approach:
   1. Read the integers n (number of applicants), m (number of apartments), and k (max allowed difference).
   2. Store the desired sizes in a vector (applicants) and the apartment sizes in another vector (apartments).
   3. Sort both vectors in non-decreasing order.
   4. Use two pointers i (for applicants) and j (for apartments). Initially i = 0, j = 0.
      - If abs(applicants[i] - apartments[j]) <= k, it's a match. Increment matches, i, and j.
      - Else if apartments[j] < applicants[i] - k, then j++ (apartment is too small).
      - Otherwise, i++ (apartment is too large for this applicant).
   5. Print the number of matched applicants.

   Time Complexity:
   O(n log n + m log m), due to sorting the two lists. 
   The two-pointer matching itself takes O(n + m).

   Space Complexity:
   O(n + m), we store both lists of sizes in vectors.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // for abs()
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> applicants(n), apartments(m);
    
    for(int i = 0; i < n; i++){
        cin >> applicants[i];
    }
    for(int j = 0; j < m; j++){
        cin >> apartments[j];
    }
    
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    
    int i = 0, j = 0;
    int matches = 0;
    
    while(i < n && j < m){
        long long a = applicants[i];
        long long b = apartments[j];
        
        if(abs(a - b) <= k){
            matches++;
            i++;
            j++;
        }
        else if(b < a - k){
            j++;
        }
        else {
            i++;
        }
    }
    
    cout << matches << "\n";
    return 0;
}
