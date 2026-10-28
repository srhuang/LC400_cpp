#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sorting
        sort(begin(nums), end(nums));

        // n times two pointers algorithm
        int sz = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < sz; i++) {
            // two pointers algorithm
            int left = i + 1;
            int right = sz - 1;

            // ignore the duplicate results
            if((i != 0) && (nums[i-1] == nums[i])) {
                continue;
            }

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0) {
                    left++;
                }else if(sum > 0) {
                    right--;
                }else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // ignore the duplicate results
                    while((left < right) && (nums[left] == nums[left-1])) {
                        left++;
                    }
                }
            } // while
        }
        return ans;
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