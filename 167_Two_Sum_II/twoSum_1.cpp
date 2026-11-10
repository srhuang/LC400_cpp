#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz = numbers.size();
        for (int i = 0; i < sz; i++) {
            // binary search
            int left = i + 1;
            int right = sz - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                int sum = numbers[i] + numbers[mid];
                if (sum < target) {
                    left = mid + 1;
                } else if (sum > target) {
                    right = mid - 1;
                } else {
                    return {i + 1, mid + 1};
                }
            } // while
        } // for
        return {-1, -1};
    }
};

int main(int argc, char* argv[]) {
    // input
    vector<int> numbers = {2,7,11,15};

    // solution
    Solution s;
    vector<int> ans = s.twoSum(numbers, 9);

    // output
    cout << "Answer: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}