#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sorting
        sort(begin(nums), end(nums));

        // keep tracking the diff
        int diff = INT_MAX;

        // n times two pointers algorithm
        int sz = nums.size();
        for(int i = 0; i < sz; i++) {
            // two pointers algorithm
            int left = i + 1;
            int right = sz - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < target) {
                    left++;
                }else if(sum > target) {
                    right--;
                }else{
                    return target;
                }
                // update the diff
                if(abs(sum - target) < abs(diff)) {
                    diff = target - sum;
                }
            } // while
        } // for
        return (target - diff);
    }
};

int main(int agrc, char* argv[]) {
    // input
    vector<int> nums = {-1,2,1,-4};

    // solution
    Solution s;
    int ans = s.threeSumClosest(nums, 1);

    // output
    cout << "Answer: " << ans << endl;

    return 0;
}