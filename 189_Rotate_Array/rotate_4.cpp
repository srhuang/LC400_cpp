#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(&nums[0], nums.size());
        reverse(&nums[0], k);
        reverse(&nums[k], nums.size() - k);
    }
    void reverse(int *nums, int n)
    {
        for(int i = 0; i < n / 2; i++)
        {
            nums[i] ^= nums[n - i - 1];
            nums[n - i - 1] ^= nums[i];
            nums[i] ^= nums[n - i - 1];
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
