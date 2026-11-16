#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // recursion terminate
        if (0 == n) {
            return {""};
        }

        // recursive case
        vector<string> ans;
        for (int left_cnt = 0; left_cnt < n; left_cnt++) {
            vector<string> left_strs = generateParenthesis(left_cnt);
            vector<string> right_strs = generateParenthesis(n - 1 - left_cnt);
            for (int l = 0; l < left_strs.size(); l++) {
                for (int r = 0; r < right_strs.size(); r++) {
                    ans.push_back("(" + left_strs[l] + ")" + right_strs[r]);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    // input

    // solution
    Solution s;
    vector<string> ans = s.generateParenthesis(3);

    // output
    cout << "Answer: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}