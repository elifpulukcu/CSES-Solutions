/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1629

   Problem: Movie Festival

   Description:
   You have n movies, each with a start time (a) and an end time (b). Your task is 
   to find the maximum number of movies you can watch in their entirety, ensuring 
   no two chosen movies overlap in time.

   Approach:
   1. Read n (the number of movies).
   2. For each movie, store a pair (start_time, end_time).
   3. Sort the list of movies by their end time in ascending order.
   4. Initialize a variable current_end = 0 (the earliest time you're free).
   5. Iterate over the sorted movies:
      - If the start time of the current movie is >= current_end, 
        it means we can watch it, so increment the count and update current_end 
        to this movie's end time.
   6. Print the count of movies watched.

   Time Complexity:
   O(n log n), dominated by sorting the n movies.

   Space Complexity:
   O(n), to store the list of movie intervals.
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
    vector<pair<long long, long long>> movies(n);
    
    for(int i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        movies[i] = {a, b};
    }
    
    // Sort by ending time
    sort(movies.begin(), movies.end(), [](auto &m1, auto &m2){
        return m1.second < m2.second;
    });
    
    long long count = 0;
    long long current_end = 0;
    
    for(const auto &movie : movies){
        if(movie.first >= current_end){
            count++;
            current_end = movie.second;
        }
    }
    cout << count << "\n";
    return 0;
}
