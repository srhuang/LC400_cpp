#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // State : take the first m(or n) elements
        bool dp[m+1][n+1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // Base case
                if (j == 0) {
                    dp[i][j] = (i == 0);
                    continue;
                }

                // Transition
                if ((j >= 2) && (p[j-1] == '*')) {
                    bool firstMatch = (i > 0) && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
                    dp[i][j] = (firstMatch && dp[i - 1][j]) || dp[i][j - 2];
                } else {
                    bool firstMatch = (i > 0) && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                    dp[i][j] = firstMatch && dp[i - 1][j - 1];
                }
            }
        }
        // Answer
        return dp[m][n];
    }
};

int main (int argc, char* argv[]) {
    // input data
    string text = "aa";
    string pattern = "a*";

    // solution
    Solution s;
    bool ans = s.isMatch(text, pattern);

    // print
    cout << "Answer: " << ans << endl;
}