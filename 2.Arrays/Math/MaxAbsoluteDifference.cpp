


int Solution::maxArr(vector<int> &A) {

    int result = 0;
    int n = A.size();
    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < n; i++) {
        max1 = std::max(max1, A[i] + i);
        max2 = std::max(max2, A[i] - i);

        min1 = std::min(min1, A[i] + i);
        min2 = std::min(min2, A[i] - i);

    }

    return std::max(max1 - min1, max2 - min2);
}

/**
 * Time  - O(N)
 * Space - O(1)
 *
    You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
    f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

    For example,

    A=[1, 3, -1]

    f(1, 1) = f(2, 2) = f(3, 3) = 0
    f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
    f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
    f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

    So, we return 5.




    Hint 1 :
    For two indices i and j, try to observe how we expand f(i, j).


    f(i, j) = |A[i] - A[j]| + |i - j| can be written in 4 ways
    (Since we are looking at max value, we don’t even care if the value becomes negative as long as we are also covering the max value in some way).

    (A[i] + i) - (A[j] + j)
    -(A[i] - i) + (A[j] - j)
    (A[i] - i) - (A[j] - j)
    (-A[i] - i) + (A[j] + j) = -(A[i] + i) + (A[j] + j)
    Note that case 1 and 4 are equivalent and so are case 2 and 3.
    We can construct two arrays with values: A[i] + i and A[i] - i.
    Then, for above 2 cases, we find the maximum value possible.
    For that, we just have to store minimum and maximum values of expressions A[i] + i and A[i] - i for all i.



 */