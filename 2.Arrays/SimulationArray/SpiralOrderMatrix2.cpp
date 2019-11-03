
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > spiralOrderMatrix(int size) {
    vector<vector<int>> A(size, vector<int>(size, 0));
    int row = size;
    int col = size;
    int dir = 0;
    int counter = 1;
    int top = 0, left = 0, right = col - 1, bottom = row - 1;
    while (top <= bottom and left <= right) {
        switch (dir) {
            case 0: {
                //go from left to right on top
                for (int i = left; i <= right; i++) {
                    A[top][i] = counter++;
                }
                top++;
                break;
            }
            case 1: {
                //go from top to bottom on right
                for (int i = top; i <= bottom; i++) {
                    A[i][right] = counter++;
                }
                right--;
                break;
            }
            case 2: {
                //go from right to left on bottom
                for (int i = right; i >= left; i--) {
                    A[bottom][i] = counter++;
                }
                bottom--;
                break;
            }
            case 3: {
                //go from bottom to top on left
                for (int i = bottom; i >= top; i--) {
                    A[i][left] = counter++;
                }
                left++;
                break;
            }
        }
        dir = (dir + 1) % 4;
    }
    return A;
}

/**
 *Time - O(N*N)
 * Space - O(1)
 *



Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.

Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
 */

