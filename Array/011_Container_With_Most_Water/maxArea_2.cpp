#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxarea = 0;

        while (i < j)
        {
            maxarea = max(maxarea, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxarea;
    }
};

int main(int argc, char* argv[])
{
    // input data
    int ary[] = {1,8,6,2,5,4,8,3,7};
    int amount = sizeof(ary) / sizeof(ary[0]);
    vector<int> data(ary, ary + amount);

    // solution
    Solution s;
    int answer;
    answer = s.maxArea(data);

    // print
    cout << "Answer: " << answer << endl;

    return 0;
}

