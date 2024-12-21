/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/1622

   Problem: Creating Strings
   Description:
   Given a string of length n (1 <= n <= 8, characters a-z), generate all distinct 
   permutations of its characters and print them in alphabetical order. Then print 
   the number of such permutations. 

   Approach:
   1. Sort the input string in non-decreasing order.
   2. Use std::next_permutation to generate all permutations in lexicographical order.
   3. Store them in a container (e.g. std::vector<std::string>) to avoid duplicates 
      automatically handled by next_permutation (it will only produce unique permutations).
   4. Print the total count and then all permutations in ascending order.

   Time Complexity:
   O(n * n!) in the worst case. For an input of length n, next_permutation is O(n) 
   each call, and there can be up to n! permutations (fewer if there are duplicate characters).

   Space Complexity:
   O(n * n!). We store every permutation (each of length n). For n <= 8, this is feasible.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    // Sort the string to start generating permutations in lexicographical order
    sort(s.begin(), s.end());

    vector<string> permutations;
    permutations.push_back(s);

    // Generate all permutations in ascending order
    while (next_permutation(s.begin(), s.end())) {
        permutations.push_back(s);
    }

    // Print the number of distinct permutations
    cout << permutations.size() << "\n";

    // Print each permutation in alphabetical order
    for (const auto &str : permutations) {
        cout << str << "\n";
    }

    return 0;
}
