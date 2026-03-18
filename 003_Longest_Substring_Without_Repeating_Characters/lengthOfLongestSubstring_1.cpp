#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (checkUnique(s, i, j)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }

    bool checkUnique(string& s, int start, int end) {
        unordered_set<char> chars;

        for (int i = start; i <= end; i++)
        {
            char c = s[i];
            if (chars.count(c)) {
                return false;
            } else {
                chars.insert(c);
            }
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    // input data
    string data("abcabcbb");

    // solution
    Solution s;
    int ans = s.lengthOfLongestSubstring(data);

    // print
    cout << "Answer: " << ans << endl;

    return 0;
}
