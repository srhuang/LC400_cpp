#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size_n = needle.size();
        int size_h = haystack.size();
        if (size_h < size_n) return -1;

        // longest prefix suffix(LPS) for needle
        vector<int> lps(size_n);
        int pre = 0;
        lps[0] = 0;
        int i = 1;
        while (i < size_n) {
            if (needle[i] == needle[pre]) {
                lps[i] = pre + 1;
                pre++;
                i++;
            } else {
                if (0 == pre) {
                    lps[i] = 0;
                    i++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        } // while

        // searching
        int index_n = 0;
        int index_h = 0;
        while (index_h < size_h) {
            if (haystack[index_h] == needle[index_n]) {
                index_h++;
                index_n++;
                if (index_n == size_n) {
                    return (index_h - size_n);
                }
            } else {
                if (0 == index_n) {
                    index_h++;
                } else {
                    index_n = lps[index_n - 1];
                }
            }
        } // while
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