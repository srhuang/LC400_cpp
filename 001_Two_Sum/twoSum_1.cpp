#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == target - nums[i]) {
                    return {i, j};
                }
            }
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
