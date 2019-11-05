
int appearsNby3(vector<int> nums) {
    int n = nums.size();
    int first = INT_MAX, second = INT_MAX;
    int count1 = 0, count2 = 0;
    for (int num : nums) {
        if (first == num) {
            count1++;
        } else if (second == num) {
            count2++;
        } else if (count1 == 0) {
            count1++;
            first = num;
        } else if (count2 == 0) {
            count2++;
            second = num;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0, count2 = 0;

    for (int num : nums) {
        if (num == first) {
            count1++;
        } else if (num == second) {
            count2++;
        }
    }

    if (count1 > n / 3) {
        return first;
    } else if (count2 > n / 3) {
        return second;
    }
    return -1;
}

/**
 * Time - O(N)
 * Space - O(1)
 *
 You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1
1 occurs 3 times which is more than 5/3 times.
 */