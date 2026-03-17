#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (hash.find(diff) != hash.end()) {
                return {i, hash[diff]};
            }
            hash[nums[i]] = i;

        }

        return {};
    }
};

int main(int argc, char* argv[])
{
    // input data
    int ary[] = {2, 7, 11, 15};
    int n = sizeof(ary) / sizeof(ary[0]);
    vector<int> data(ary, ary + n);

    // solution
    Solution s;
    vector<int> ans = s.twoSum(data, 9);

    // print
    if (!ans.empty()) {
        cout << "Answer: " << ans[0] << ", " << ans[1] << endl;
    } else {
        cout << "No Answer" << endl;
    }
}
