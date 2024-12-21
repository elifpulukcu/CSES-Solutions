/*
   CSES Problem Set - Weird Algorithm
   Link: https://cses.fi/problemset/task/1068

   Problem: Weird Algorithm
   Description:
   Given a positive integer n, repeatedly apply the following steps:
   - If n is even, divide it by 2.
   - If n is odd, multiply it by 3 and add 1.
   Continue this process until n becomes 1, and output each value in the sequence.

   Time Complexity:
   O(k), where k is the number of steps before the sequence reaches 1.
   For n up to 1e6, this is efficient in practice.

   Space Complexity:
   O(1). Only a single variable (n) is updated repeatedly.
 */

#include <iostream>  
#include <cstdint>   
#include <ios>       
#include <string>    

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t n;
    std::cin >> n;

    std::cout << n;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        std::cout << " " << n; 
    }

    std::cout << "\n"; 
    return 0;
}
