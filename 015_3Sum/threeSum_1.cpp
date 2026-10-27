#include <iostream>

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

private:
    void twoSum(vector<int>& nums, int idx, vector<vector<int>>& ret) {
        int left = idx + 1;
        int right = nums.size() - 1;
        while(left < right) {
            int sum = nums[idx] + nums[left] + nums[right];
            if(sum == 0) {
                ret.push_back({nums[idx], nums[left], nums[right]});
                left++;
                right--;
                // ignore the duplicate results
                while((left < right) && (nums[left] == nums[left-1])) {
                    left++;
                }
            }else if(sum < 0) {
                left++;
            }else {
                right--;
            }
        } // while
    }
};

int main(int argc, char* argv[]) {
    // input data
    vector<int> data = {-1,0,1,2,-1,-4};

    // solution
    Solution s;
    vector<vector<int>> ans = s.threeSum(data);

    // answer
    cout << "Answer: " << endl;
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}