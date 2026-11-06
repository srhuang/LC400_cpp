#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sorting
        sort(begin(nums), end(nums));

        // keep tracking the diff
        int diff = INT_MAX;

        // binary search
        int sz = nums.size();
        for(int i = 0; i < sz; i++) {
            for(int j = i + 1; j < sz; j++) {
                int left = j + 1;
                int right = sz - 1;
                while(left <= right) {
                    int mid = (left + right) / 2;
                    int sum = nums[i] + nums[j] + nums[mid];
                    if(sum < target) {
                        left = mid + 1;
                    }else if(sum > target) {
                        right = mid - 1;
                    }else{
                        return sum;
                    }
                    // update the diff
                    if(abs(sum - target) < abs(diff)) {
                        diff = target - sum;
                    }
                } // while
            } // for
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