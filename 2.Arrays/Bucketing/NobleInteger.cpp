int Solution::solve(vector<int> &A) {
    sort(begin(A), end(A));
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == A[i + 1]) continue;
        if (A[i] == A.size() - 1 - i) {
            //solution =  A[i];
            return 1;
        }
    }
    if (A.back() == 0)
        //solution = 0
        return 1;
    return -1;
}

/**
    Input  : [7, 3, 16, 10]
    Output : 3
    Number of integers greater than 3
    is three.

    Input  : [-1, -9, -2, -78, 0]
    Output : 0
    Number of integers greater than 0
    is zero.

*/


/**
 * Time - O(NlogN)
 * Space - O(1)
 *


Noble Integer
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.


 Given an array arr[], find a Noble integer in it. An integer x is said to be Noble in arr[]
 if the number of integers greater than x are equal to x. If there are many Noble integers, return any of them. If there is no, then return -1.
 */
