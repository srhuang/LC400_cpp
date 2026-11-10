#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        for (; length > 0; length--) {
            int start = 0;
            for (; (start + length) <= s.size(); start++) {
                // check palindromic
                if (check(s, start, start + length - 1)) {
                    return s.substr(start ,length);
                }
            }
        }
        return "";
    }

private:
    bool check(string s, int start, int end) {
        int left = start;
        int right = end ;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main(int argc, char* argv[]){
    // input
    string data("babad");

    // solution
    Solution s;
    string ans = s.longestPalindrome(data);

    // output
    cout << "Answer: " << ans << endl;

    return 0;
}

