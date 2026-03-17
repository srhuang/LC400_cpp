#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }

        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < 2 || nums[i] > nums[j-2]) {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};

int main(int argc, char* argv[])
{
    // input data
    int ary[] = {1,2,3,3,3,4,4,4,4,5,5,5,5,5,5,5,6,7,8};
    int amount = sizeof(ary) / sizeof(ary[0]);
    vector<int> data(ary, ary + amount);

    // solution
    Solution s;
    int answer;
    answer = s.removeDuplicates(data);

    // print
    cout << "Answer: " << answer << endl;
    cout << "Output: ";
    for(int i = 0; i < answer; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
