//http://interviewbitsolution.blogspot.com/2016/09/find-duplicate-in-array.html


//cant handle case when no duplicates are present
int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0];
    int fast = A[A[0]];
    while (fast != slow) {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while (fast != slow) {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}

/**
 * Time - O(N)
 * Space - O(1)
 *
Given a read only array of n + 1 integers between 1 and n,
 find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1


 */