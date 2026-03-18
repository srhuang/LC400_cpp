#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;

        int n = s.length();
        int ans = 0;

        int right = 0;
        int left = 0;
        for (; right < n; right++)
        {
            char c = s[right];
            if (hash[c]) {
                left = max(left, hash[c]);
            }
            ans = max(ans, right - left + 1);
            hash[c] = right + 1;
        }

        return ans;
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
