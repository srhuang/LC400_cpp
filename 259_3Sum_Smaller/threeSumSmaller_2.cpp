#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int sz = nums.size();
        int cnt = 0;
        // sorting
        sort(begin(nums), end(nums));

        // binary search
        for (int i = 0; i < sz - 2; i++) {
            for (int j = i + 1; j < sz - 1; j++) {
                int left = j;
                int right = sz - 1;
                while (left < right) {
                    int mid = (left + right + 1) / 2;
                    int sum = nums[i] + nums[j] + nums[mid];
                    if (sum < target) {
                        left = mid;
                    } else {
                        right = mid - 1;
                    }
                } // while
                cnt += (left - j);
            } // for
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