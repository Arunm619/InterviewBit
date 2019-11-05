
/**


    According to Wikipedia, a man named Narayana Pandita presented the following simple algorithm to solve this problem in the 14th century.

    1.Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
    2.Find the largest index l > k such that nums[k] < nums[l].
    3.Swap nums[k] and nums[l].
    4.Reverse the sub-array nums[k + 1:].

  The above algorithm can also handle duplicates and thus can be further used to solve Permutations and Permutations II.


 */

vector<int> nextPermutation(vector<int> nums) {
    int k = 0;
    int n = nums.size();
    //from right to left find first pair where i < j find i.
    for (k = n - 2; k >= 0; k--) {
        if (nums[k] < nums[k + 1]) {
            break;
        }
    }
    //cant find any, we are in last perm return reversed nums.
    if (k == -1) {
        reverse(begin(nums), end(nums));
        return nums;
    } else {

        //find first greater number from right to left than k.
        int l;
        for (l = n - 1; l > k; l--) {
            if (nums[l] > nums[k]) {
                break;
            }
        }
        swap(nums[l], nums[k]);
        reverse(begin(nums) + k + 1, end(nums));
        return nums;
    }

}


/**
 *  Time - O(N)
 *  Space - O(1)

    Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

    If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.

    Note:

    1. The replacement must be in-place, do **not** allocate extra memory.
    2. DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.
    Input Format:

    The first and the only argument of input has an array of integers, A.
    Output Format:

    Return an array of integers, representing the next permutation of the given array.
    Constraints:

    1 <= N <= 5e5
    1 <= A[i] <= 1e9
    Examples:

    Input 1:
        A = [1, 2, 3]

    Output 1:
        [1, 3, 2]

    Input 2:
        A = [3, 2, 1]

    Output 2:
        [1, 2, 3]

    Input 3:
        A = [1, 1, 5]

    Output 3:
        [1, 5, 1]

    Input 4:
        A = [20, 50, 113]

    Output 4:
        [20, 113, 50]

 */