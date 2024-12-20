/*
 * Problem: Weird Algorithm (CSES - https://cses.fi/problemset/task/1068)
 * ---------------------------------------------------------------------
 * Description:
 * Given a positive integer n, repeatedly apply the following steps:
 * - If n is even, divide it by 2.
 * - If n is odd, multiply it by 3 and add 1.
 * Continue until n becomes 1.
 *
 * Input:
 * A single integer n (1 <= n <= 1e6).
 *
 * Output:
 * Print all values of n in the sequence, from the initial n down to 1.
 *
 * Example:
 * Input: 3
 * Output: 3 10 5 16 8 4 2 1
 *
 * Idea:
 * Straightforward simulation of the process until n = 1.
 * Complexity is O(steps), where the number of steps is bounded by the Collatz conjecture behavior.
 * For given constraints (n up to 1e6), this runs very fast.
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
