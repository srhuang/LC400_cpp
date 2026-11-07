#include <iostream>
#include <unordered_set>

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
        unordered_set<long long> seen;

        // find the complement
        for(int i = start; i < sz; i++) {
            long long complement = target - nums[i];
            if(seen.count(complement)) {
                ans.push_back({nums[i], int(complement)});
                //ignore duplicate results
                while((i+1 < sz) && (nums[i] == nums[i+1])) {
                    i++;
                }
            }
            seen.insert(nums[i]);
        }
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