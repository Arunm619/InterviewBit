class Solution {
public:
    vector <vector<int>> threeSumLCforZERO(vector<int> &nums) {
        if (nums.empty() or nums.size() < 3) return {};
        vector <vector<int>> result;
        sort(begin(nums), end(nums));
        int n = nums.size();

        for (int start = 0; start < n - 1;) {
            int value1 = nums[start];
            int left = start + 1;
            int right = n - 1;
            while (left < right) {
                int value2 = nums[left];
                int value3 = nums[right];
                int sum = value1 + value2 + value3;
                if (sum == 0) {
                    result.push_back({value1, value2, value3});
                    left++, right--;
                }
                if (sum <= 0) {
                    while (left < right and nums[left] == value2) left++;
                }

                if (sum >= 0) {
                    while (left < right and nums[right] == value3) right--;
                }
            }
            while (start < right and value1 == nums[start]) start++;
        }

        return result;
    }
};


//INTERVIEWBIT range (1,2)
bool threeSumWithinRange(vector<double>& nums) {
    if(nums.empty() or nums.size()<3) return false;
    sort(begin(nums),end(nums));
    int n = nums.size();

    for(int start = 0; start < n-1; ){
        auto value1 = nums[start];
        int left = start+1;
        int right = n-1;
        while(left < right){
            auto value2 = nums[left];
            auto value3 = nums[right];
            auto sum = value1 + value2 + value3;
            if(sum >=1 and sum<=2){
                return true;
            }
            if(sum <= 1){
                while(left < right and nums[left]==value2) left ++;
            }

            if(sum>=2){
                while(left < right and nums[right]==value3) right --;
            }
        }
        while(start < right and value1 == nums[start]) start++;
    }

    return false;
}
int Solution::solve(vector<string> &A) {
    vector<double> numbers;
    numbers.reserve(A.size());
    for(auto& i : A){
        numbers.push_back(stod(i));
    }

    return threeSumWithinRange(numbers);
}

/*

  1 2 3
  i
    j
      k
*/


/**
 *  Time - O(NlogN)
 *  Space - O(1)
 *


    Given an array of real numbers greater than zero in form of strings.
    Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
    Return 1 for true or 0 for false.

    Example:

    Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

    You should return 1

    as

    0.6+0.7+0.4=1.7

    1<1.7<2

    Hence, the output is 1.

    O(n) solution is expected.

    Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.
 */