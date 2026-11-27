#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size_n = needle.size();
        int size_h = haystack.size();
        for (int start = 0; start <= (size_h - size_n); start++) {
            // check each needle
            for (int i = 0; i < size_n; i++) {
                if (haystack[start + i] != needle[i]) {
                    break;
                }
                // match
                if (i == (size_n - 1)) {
                    return start;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    // input
    string haystack = "mississipi";
    string needle = "sis";

    // solution
    Solution s;
    int ans = s.strStr(haystack, needle);

    // output
    cout << "Answer: " << ans << endl;

    return 0;
}