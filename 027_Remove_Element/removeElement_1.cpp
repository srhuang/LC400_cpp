#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

int main(int argc, char* agrv[]) {
    // input
    vector<int> nums = {1,2,3,3,4,4,4,4,5,5,5,5,5,6,7,8,9};
    
    // solution
    Solution s;
    int answer = s.removeElement(nums, 5);

    // output
    cout << "Answer is "<< answer <<endl;
    for(int i = 0; i < answer; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

