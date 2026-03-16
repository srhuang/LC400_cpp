#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int water = 0;
        for (int i = 0; i < size; i++)
        {
            int left_max = 0;
            int right_max = 0;
            // check left side
            for (int j = i; j >= 0; j--)
            {
                left_max = max(left_max, height[j]);
            }

            // check right side
            for (int j = i; j < size; j++)
            {
                right_max = max(right_max, height[j]);
            }

            water += min(left_max, right_max) - height[i];
        }

        return water;
    }
};

int main(int argc, char* argv[])
{
    // input data
    int ary[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int amount = sizeof(ary) / sizeof(ary[0]);
    vector<int> data(ary, ary + amount);

    // solution
    Solution s;
    int answer = s.trap(data);

    // print
    cout << "Answer: " << answer << endl;

    return 0;
}
