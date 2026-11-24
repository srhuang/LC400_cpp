#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }

        int j = 0;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            // track the count
            if (nums[i] == nums[j]) {
                cnt++;
            } else {
                cnt = 1;
            }

            if (cnt <= 2) {
                nums[++j] = nums[i];
            }
        }

        return j + 1;
    }
};

int main(int argc, char* argv[]) {
    // input
    vector<int> nums = {1,2,3,3,3,4,4,4,4,5,5,5,5,5,5,5,6,7,8};

    // solution
    Solution s;
    int answer = s.removeDuplicates(nums);

    // output
    cout << "Answer: " << answer << endl;
    for (int i = 0; i < answer; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
