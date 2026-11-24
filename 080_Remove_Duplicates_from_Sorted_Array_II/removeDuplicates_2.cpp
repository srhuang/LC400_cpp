#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }

        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i < 2 || nums[i] > nums[j-2]) {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};

int main(int argc, char* argv[]) {
    // input
    vector<int> nums = {1,2,3,3,3,4,4,4,4,5,5,5,5,5,5,5,6,7,8};

    // solution
    Solution s;
    int answer = s.removeDuplicates(nums);

    // print
    cout << "Answer: " << answer << endl;
    for (int i = 0; i < answer; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
