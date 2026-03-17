#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        for (int i = 0; i < k; i++)
        {
            int pre = nums[n - 1];
            for (int j = 0; j < n; j++) 
            {
                int temp = nums[j];
                nums[j] = pre;
                pre = temp;
            }
        }
    }
};

int main()
{
    // input data
    int ary[] = {1,2,3,4,5,6,7};
    int amount = sizeof(ary) / sizeof(ary[0]);
    vector<int> data(ary, ary+amount);

    // solution
    Solution s;
    s.rotate(data, 3);

    // print
    cout << "Answer : ";
    for(int i=0; i<amount; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
