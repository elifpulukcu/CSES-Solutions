/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1091

   Problem: Concert Tickets

   Description:
   There are n ticket prices for a concert and m customers. Each customer will pay up to 
   a maximum amount t for a ticket. For each customer (in the given order), we need to find 
   the ticket with the greatest price that does not exceed t. If such a ticket exists, 
   print its price and remove it from the pool; otherwise, print -1.

   Approach:
   1. Read n (number of tickets) and m (number of customers).
   2. Insert the n ticket prices into a multiset (allowing duplicates).
   3. For each of the m customers:
      - Let t be the maximum price the customer will pay.
      - Use tickets.upper_bound(t) to find the first element greater than t.
      - If upper_bound(t) == tickets.begin(), there is no ticket <= t ⇒ print -1.
      - Otherwise, decrement the iterator to get the ticket <= t, print it, and remove it from the set.
   4. Continue until all customers are processed.

   Time Complexity:
   O((n + m) * log n).
   - Inserting n tickets into a multiset takes O(n log n).
   - For each of the m queries, upper_bound and erase operations each take O(log n).

   Space Complexity:
   O(n), since we store n ticket prices in the multiset.
*/

#include <iostream>
#include <set>  // for multiset
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    multiset<long long> tickets;
    
    for(int i = 0; i < n; i++){
        long long price;
        cin >> price;
        tickets.insert(price);
    }
    
    while(m--){
        long long t;
        cin >> t;
        // find the largest ticket price <= t
        auto it = tickets.upper_bound(t);
        if(it == tickets.begin()){
            // no ticket <= t
            cout << -1 << "\n";
        } else {
            --it; // now it points to the largest element <= t
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
    return 0;
}
