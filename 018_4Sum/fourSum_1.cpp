#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // sorting
        sort(nums.begin(), nums.end());

        // generalized K-sum implementation
        return ksum(nums, target, 0, 4);
    }

private:
    vector<vector<int>> ksum(vector<int>& nums, long long target,
        int start, int k) {
        // variables
        vector<vector<int>> ans;
        int sz = nums.size();

        // two sum
        if(k == 2) {
            return twoSum(nums, target, start);
        }

        // k > 2
        for(int i = start; i < sz; i++) {
            // ignore duplicate results
            if((i != start) && (nums[i] == nums[i-1])) {
                continue;
            }

            // recursion
            vector<vector<int>> ret = ksum(nums, target - nums[i],
                i+1, k-1);
            
            // combine the results
            for(int j = 0; j < ret.size(); j++) {
                vector<int> tmp = {nums[i]};
                tmp.insert(tmp.end(), ret[j].begin(), ret[j].end());
                ans.push_back(tmp);
            }
        } // for
        return ans;
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target,
        int start) {
        // variables
        vector<vector<int>> ans;
        int sz = nums.size();
        int left = start;
        int right = sz - 1;
        
        // two pointers
        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum < target) {
                left++;
            }else if(sum > target) {
                right--;
            }else{
                // find the target
                ans.push_back({nums[left], nums[right]});
                left++;
                right--;
                //ignore the duplicate results
                while((left < right) && (nums[left] == nums[left - 1])) {
                    left++;
                }
            }
        } // while
        return ans;
    }
};

int main(int argc, char* argv[]) {
    // input
    vector<int> nums = {1,0,-1,0,-2,2};

    // solution
    Solution s;
    vector<vector<int>> ans = s.fourSum(nums, 0);

    // output
    cout << "Answer: " << endl;
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}