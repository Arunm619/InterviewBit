
void setZeroes(vector <vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int hasfirstrowZero = 0, hasfirstcolZero = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                if (i == 0) hasfirstrowZero = 1;
                if (j == 0) hasfirstcolZero = 1;

                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            if (matrix[i][0] == 0 or matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (hasfirstcolZero) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }


    if (hasfirstrowZero) {
        for (int i = 0; i < m; i++) {
            matrix[0][i] = 0;
        }
    }
}
/**
 * Time - O(N*N)
 * Space - O(1)
 *

 Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]
 */