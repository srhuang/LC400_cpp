#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40,
            10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"};

        string ans;

        for (int i = 0; (i < values.size()) && (num > 0); i++) {
            while(values[i] <= num) {
                num -= values[i];
                ans += symbols[i];
            }
        }

        return ans;
    }
};

int main(int agrc, char* argv[]) {
    // input data
    int data = 3749;

    // solution
    Solution s;
    string ans = s.intToRoman(data);

    // print
    cout << "Answer: " << ans << endl;

    return 0;
}