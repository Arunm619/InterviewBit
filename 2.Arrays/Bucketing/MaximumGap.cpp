int Solution::maximumGap(const vector<int> &A) {

    if (A.size() <= 1) return 0;
    int n = A.size();

    // Make two arrays such that one of them holds the minimum from the left
    // and the other holds maximum from the right
    vector<int> left(n, 0);
    vector<int> right(n, 0);


    // Fill the first array with minimum from the left
    left[0] = A[0];
    for (int i = 1; i < n; i++) {
        left[i] = std::min(left[i - 1], A[i]);
    }

    // Fill the second array with maximum from the right
    right[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = std::max(right[i + 1], A[i]);
    }


    // While we don't traverse the complete array, check if the minimum element is indeed
    // less than the maximum element in the other array, if yes, update the answer.
    // Move the pointer as required. If the element in second array is greater than
    // that in first array, keep moving the second pointer and update the answer
    // else move the first pointer.
    int i = 0, j = 0, ans = -1;
    while (i < n and j < n) {
        if (left[i] <= right[j]) {
            if (j - i > ans) {
                ans = j - i;
            }
            j++;
        } else {
            i++;
        }
    }

    return ans;
}

/**
 * Time - O(N)
 * Space - O(N)
 *


Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
If there is no solution possible, return -1.
Example :
A : [3 5 4 2]
Output : 2
for the pair (3, 4)
 * */