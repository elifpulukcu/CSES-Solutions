/*
   CSES Problem Set
   Link: https://cses.fi/problemset/task/2165

   Problem: Tower of Hanoi
   Description:
   We have three pegs (labeled 1, 2, and 3) and n disks on peg 1 in ascending order
   of size (from top to bottom). The goal is to move all disks from peg 1 to peg 3,
   using peg 2 as auxiliary, without ever placing a larger disk on top of a smaller disk.

   The minimal number of moves required for n disks is (2^n - 1). After computing
   this number, we need to output the exact sequence of moves, where each move is
   represented by two integers a and b (meaning we move a disk from peg a to peg b).

   Time Complexity:
   O(2^n). The recursive solution yields 2^n - 1 moves.

   Space Complexity:
   O(n). The recursion depth is n in the worst case.
*/

#include <iostream>
using namespace std;

void moveDisks(int n, int fromPeg, int toPeg, int auxPeg) {
    if (n == 1) {
        // Base case: move a single disk directly
        cout << fromPeg << " " << toPeg << "\n";
        return;
    }
    // Move top (n-1) disks from 'fromPeg' to 'auxPeg', using 'toPeg' as auxiliary
    moveDisks(n - 1, fromPeg, auxPeg, toPeg);
    // Move the largest disk from 'fromPeg' to 'toPeg'
    cout << fromPeg << " " << toPeg << "\n";
    // Move the (n-1) disks from 'auxPeg' to 'toPeg', using 'fromPeg' as auxiliary
    moveDisks(n - 1, auxPeg, toPeg, fromPeg);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Minimum number of moves is 2^n - 1
    long long moves = (1LL << n) - 1; 
    cout << moves << "\n";

    // Solve Tower of Hanoi from peg 1 to peg 3 using peg 2 as auxiliary
    moveDisks(n, 1, 3, 2);

    return 0;
}
