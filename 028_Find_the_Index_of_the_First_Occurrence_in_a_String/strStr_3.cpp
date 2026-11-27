#include <iostream>

using namespace std;

class Solution {
    // constants for hash
    int radix_1 = 26;
    int mod_1 = 1000000033;
    int radix_2 = 27;
    int mod_2 = 2147483647;
public:
    int strStr(string haystack, string needle) {
        int size_n = needle.size();
        int size_h = haystack.size();
        if (size_h < size_n) return -1;

        // calculate the max factor of MSB
        long factor_1_max = 1;
        long factor_2_max = 1;
        for (int i = 0; i < size_n; i++) {
            factor_1_max = (factor_1_max * radix_1) % mod_1;
            factor_2_max = (factor_2_max * radix_2) % mod_2;
        }

        // get needle hash
        pair<int, int> hash_n = getHash(needle, size_n);

        // check substring of haystack
        pair<int, int> hash_h = {0, 0};
        for (int start = 0; start <= (size_h - size_n); start++) {
            if (0 == start) {
                hash_h = getHash(haystack, size_n);
            } else {
                int msb = haystack[start - 1] - 'a';
                int lsb = haystack[start + size_n - 1] - 'a';
                hash_h.first = (
                    ((long)hash_h.first * radix_1) % mod_1 + mod_1
                    - (msb * factor_1_max) % mod_1
                    + lsb
                    ) % mod_1;
                hash_h.second = (
                    ((long)hash_h.second * radix_2) % mod_2 + mod_2
                    - (msb * factor_2_max) % mod_2
                    + lsb
                    ) % mod_2;
            }

            // if hash match, return.
            if ((hash_h.first == hash_n.first) 
                && (hash_h.second == hash_n.second)) {
                return start;
            }
        }
        return -1;
    }

private:
    pair<int, int> getHash(string str, int sz) {
        int hash_1 = 0;
        long factor_1 = 1;
        int hash_2 = 0;
        long factor_2 = 1;
        for (int i = sz - 1; i >= 0; i--) {
            hash_1 = (hash_1 + (str[i] - 'a') * factor_1) % mod_1;
            factor_1 = (factor_1 * radix_1) % mod_1;
            hash_2 = (hash_2 + (str[i] - 'a') * factor_2) % mod_2;
            factor_2 = (factor_2 * radix_2) % mod_2;
        }
        return make_pair(hash_1, hash_2);
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