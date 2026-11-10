#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int sz = nums.size();
        int cnt = 0;
        sort(begin(nums), end(nums));

        // two pointers
        for (int i = 0; i < sz - 2; i++) {
            int left = i + 1;
            int right = sz - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    cnt += (right - left);
                    left++;
                } else {
                    right--;
                }
            } // while
        } // for
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    // input
    vector<int> nums = {-2,0,1,3};

    // solution
    Solution s;
    int ans = s.threeSumSmaller(nums, 2);

    // output
    cout << "Answer: " << ans << endl;
    
    return 0;
}