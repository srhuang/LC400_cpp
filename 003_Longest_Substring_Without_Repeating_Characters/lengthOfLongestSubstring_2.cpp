#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;

        int left = 0;
        int right = 0;

        int ans = 0;
        while (right < s.length())
        {
            char r = s[right];
            count[r]++;

            while (count[r] > 1)
            {
                char l = s[left];
                count[l]--;
                left++;
            }

            ans = max(ans, right - left + 1);

            right++;
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
