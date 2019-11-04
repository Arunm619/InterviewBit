#include <iostream>
#include <vector>
#include <set>

using namespace std;
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
int solve(vector<string> A) {
    vector<double> numbers{};
    numbers.reserve(A.size());
    for(auto& i : A){
        numbers.push_back(stod(i));
    }

    return    threeSumWithinRange(numbers);
}

/*

  1 2 3
  i
    j
      k
*/



int main() {
  cout << solve({"0.234022", "0.051717", "0.820402", "0.492629", "0.004825", "0.589073"});

    return 0;
}