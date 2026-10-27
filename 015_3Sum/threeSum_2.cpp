#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sorting
        sort(begin(nums), end(nums));

        // n times twoSum
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) {
            // ignore the duplicate results
            if((i == 0) || (nums[i-1] != nums[i])) {
                twoSum(nums, i, ans);
            }
        }
        return ans;
    }

    void twoSum(vector<int>& nums, int i, vector<vector<int>>& ret) {
        unordered_set<int> seen;
        for(int j = i + 1; j < nums.size(); j++) {
            int complement = 0 - nums[i] - nums[j];
            // find the complement
            if(seen.count(complement)) {
                ret.push_back({nums[i], complement, nums[j]});
                // ignore the duplicate results
                while((j + 1 < nums.size()) && (nums[j] == nums[j+1])) {
                    j++;
                }
            }
            seen.insert(nums[j]);
        }
    }
};

int main(int argc, char* argv[]) {
    // input
    vector<int> data = {-1,0,1,2,-1,-4};

    // solution
    Solution s;
    vector<vector<int>> ans = s.threeSum(data);

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