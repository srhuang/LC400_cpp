#include <iostream>

using namespace std;

class Solution {
    // variables
    vector<string> ans;
    int amount;
public:
    vector<string> generateParenthesis(int n) {
        amount = n;
        backtracking("", 0, 0);
        return ans;
    }

private:
    void backtracking(string cur, int left_cnt, int right_cnt) {
        // pruning
        if (cur.size() == (2 * amount)) {
            ans.push_back(cur);
            return;
        }

        // exploration
        if (left_cnt < amount) {
            cur.push_back('(');
            backtracking(cur, left_cnt + 1, right_cnt);
            cur.pop_back();
        }
        if (left_cnt > right_cnt) {
            cur.push_back(')');
            backtracking(cur, left_cnt, right_cnt + 1);
            cur.pop_back();
        }

        // pruning
        return;
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