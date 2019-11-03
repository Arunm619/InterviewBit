vector <vector<int>> Solution::diagonal(vector <vector<int>> &A) {
    vector <vector<int>> result;
    int n = A.size();
    int m = A[0].size();
    vector<int> temp;
    int k, col, row;
    for (k = 0; k < n; k++) {
        temp.clear();
        col = 0;
        row = k;
        while (row >= 0) {
            temp.push_back(A[row][col]);
            row--;
            col++;
        }
        result.push_back(temp);
    }


    for (k = 1; k < m; k++) {
        temp.clear();
        row = n - 1;
        col = k;
        do {
            temp.push_back(A[row][col]);
            row--;
            col++;
        } while (col < m);
        result.push_back(temp);
    }

    for (auto &each : result) reverse(begin(each), end(each));
    return result;
}


/**
 * Time - O(N*M)
 * Space - O(1)
 *

 Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:


Input:

1 2 3
4 5 6
7 8 9

Return the following :

[
[1],
[2, 4],
[3, 5, 7],
[6, 8],
[9]
]


Input :
1 2
3 4

Return the following  :

[
[1],
[2, 3],
[4]
]
 */