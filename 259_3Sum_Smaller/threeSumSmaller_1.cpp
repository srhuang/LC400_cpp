#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int sz = nums.size();
        int cnt = 0;
        // find every possible set of triplets
        for(int i = 0; i < sz; i++) {
            for(int j = i + 1; j < sz; j++) {
                for(int k = j + 1; k < sz; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum < target) {
                        cnt++;
                    }
                }
            }
        }
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