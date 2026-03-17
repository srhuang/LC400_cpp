#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        int count = 0;
        int start = 0;
        while (count < n)
        {
            int cur = start;
            int pre = nums[start];
            do
            {
                int next = (cur + k) % n;
                int temp = nums[next];
                nums[next] = pre;
                pre = temp;
                cur = next;
                count++;
            } while (cur != start);
            start++;
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
