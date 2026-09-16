#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            // odd
            string odd = expand(s, i, i);
            if (odd.size() > ans.size()) {
                ans = odd;
            }

            // even
            string even = expand(s, i, i+1);
            if (even.size() > ans.size()) {
                ans = even;
            }
        }
        return ans;
    }

private:
    string expand(string s, int left, int right) {
        while (left >=0 && right < s.size()) {
            if (s[left] == s[right]) {
                left--;
                right++;
            } else {
                break;
            }
        } // while
        return s.substr(left + 1, right - left - 1);
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

