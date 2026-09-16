#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        array<int, 2> ans = {0, 0};

        // length = 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // length = 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                ans = {i, i+1};
            }
        }

        // length >=3
        for (int length = 3; length <= n; length++) {
            for (int i = 0; (i + length - 1) < n; i++) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }

        // construct the answer
        int start = ans[0];
        int end = ans[1];
        return s.substr(start, end - start + 1);
    }
};

int main()
{
    // input data
    string data("babad");

    // solution
    Solution s;
    string ans = s.longestPalindrome(data);

    // print
    cout << "Answer: " << ans << endl;

}

