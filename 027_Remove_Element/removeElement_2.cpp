#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size();
        int i = 0;
        while (i < j) {
            if (nums[i] == val) {
                nums[i] = nums[j - 1];
                j--;
            } else {
                i++;
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

