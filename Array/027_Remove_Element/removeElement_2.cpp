#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int n = nums.size();
        int i = 0;
        while(i < n) {
            if(nums[i] == val) {
                nums[i] = nums[n - 1];
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};

int main(int argc, char const *agrv[])
{
    int arry[] = {1,2,3,3,4,4,4,4,5,5,5,5,5,6,7,8,9};
    int amount = sizeof(arry)/sizeof(arry[0]);
    int answer;

    vector<int> data(arry, arry+amount);
    Solution s;
    answer = s.removeElement(data, 5);

    cout << "Answer is "<< answer <<endl;
    cout << "Output is ";
    for(int i=0; i<answer; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}

