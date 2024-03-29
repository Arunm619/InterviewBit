void Solution::rotate(vector<vector<int> > &A) {

    //transpose
    int n = A.size();
    for(int i = 0;i<n;i++){
        for(int j = i+1; j < n; j++){
            swap(A[i][j],A[j][i]);
        }
    }

    //reverse
    for(auto& i : A){
        reverse(begin(i),end(i));
    }
}

/**
 * Time - O(N*N)
 * Space - O(1)
 *

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]
Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]
 */


