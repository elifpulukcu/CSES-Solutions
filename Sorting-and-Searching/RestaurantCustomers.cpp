/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1619

   Problem: Restaurant Customers

   Description:
   We have n customers in a restaurant. For each customer, we have an arrival time (a) 
   and a leaving time (b). We need to determine the maximum number of customers 
   present in the restaurant at the same time.

   Approach:
   1. Read the integer n (number of customers).
   2. Create an array (vector) of “events”. Each customer contributes two events:
      - (a, +1)  meaning a customer arrives at time a
      - (b, -1)  meaning a customer leaves at time b
   3. Sort these events first by time; if two events have the same time, 
      the departure event (-1) should come before the arrival event (+1) 
      to avoid overcounting.
   4. Traverse the sorted list of events in order, maintaining a running count of how many 
      customers are currently in the restaurant (add 1 on arrival, subtract 1 on departure).
   5. Track the maximum value of this running count throughout. Print it at the end.

   Time Complexity:
   O(n log n).
   We sort 2n events, which takes O(n log n). The single pass over the events is O(n).

   Space Complexity:
   O(n), to store the arrival and departure events (2n events total, which is proportional to n).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<long long,int>> events;
    events.reserve(2*n);
    
    for(int i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        // +1 for arrival, -1 for departure
        events.push_back({a, +1});
        events.push_back({b, -1});
    }
    
    // Sort by time; if tie, place departure (-1) before arrival (+1)
    sort(events.begin(), events.end(), [](auto &e1, auto &e2){
        if(e1.first == e2.first)
            return e1.second < e2.second;
        return e1.first < e2.first;
    });
    
    long long current = 0, maximum_customers = 0;
    for(const auto &ev : events){
        current += ev.second;
        maximum_customers = max(maximum_customers, current);
    }
    cout << maximum_customers << "\n";
    return 0;
}
