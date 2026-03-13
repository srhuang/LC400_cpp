#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int j = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=val) {
                nums[j++] = nums[i];
            }
        }
        return j;
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

