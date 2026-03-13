#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        for (int left = 0; left < height.size(); left++)
        {
            for (int right = left + 1; right < height.size(); right++)
            {
                int width = right - left;
                int area = min(height[left], height[right]) * width;
                maxarea = max(maxarea, area);
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

