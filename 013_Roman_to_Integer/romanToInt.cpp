#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int ans = 0;
        int i = 0;
        while (i < s.size()) {
            int firstValue = values[s[i]];

            // get second value if need
            int secondValue = 0;
            if ((i + 1) < s.size()) {
                secondValue = values[s[i+1]];
            }

            // parsing one or two chars
            if (secondValue > firstValue) {
                ans += (secondValue - firstValue);
                i += 2;
            } else {
                ans += firstValue;
                i ++;
            }
        } // while

        return ans;
    }
};

int main(int argc, char* argv[]) {
    // input data
    string data = "MCMXCIV";

    // solution
    Solution s;
    int ans = s.romanToInt(data);

    // print
    cout << "Answer: " << ans << endl;

    return 0;
}