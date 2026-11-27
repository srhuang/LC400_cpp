#include <iostream>

using namespace std;

class Solution {
    // constants for hash
    int radix = 26;
    int mod = 1000000033;
public:
    int strStr(string haystack, string needle) {
        int size_n = needle.size();
        int size_h = haystack.size();
        if (size_h < size_n) return -1;

        // calculate max factor for MSB
        long factor_max = 1;
        for (int i = 0; i < size_n; i++) {
            factor_max = (factor_max * radix) % mod;
        }

        // get needle hash
        int hash_n = getHash(needle, size_n);

        // check substrings of haystack
        int hash_h = 0;
        for (int start = 0; start <= (size_h - size_n); start++) {
            if (0 == start) {
                hash_h = getHash(haystack, size_n);
            } else {
                int msb = haystack[start - 1] - 'a';
                int lsb = haystack[start + size_n - 1] - 'a';
                hash_h = (
                    ((long)hash_h * radix) % mod + mod // prevent negative values
                    - (msb * factor_max) % mod
                    + lsb
                    ) % mod;
            }
            
            // if hash match, check the characters
            if (hash_h == hash_n) {
                for (int i = 0; i < size_n; i++) {
                    if (haystack[start + i] != needle[i]) {
                        break;
                    }
                    // match
                    if (i == size_n - 1) {
                        return start;
                    }
                }
            }
        }
        return -1;        
    }
private:
    int getHash(string str, int sz) {
        int hash = 0;
        long factor = 1;
        for (int i = sz - 1; i >= 0; i--) {
            hash = (hash + (str[i] - 'a') * factor) % mod;
            factor = (factor * radix) % mod;
        }
        return hash;
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