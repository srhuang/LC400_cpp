#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int index = 0;
        int n = s.size();
        int sign = 1;

        // Discard all spaces
        while (index < n && s[index] == ' ') {
            index++;
        }

        // check the sign
        if (index < n && s[index] == '+'){
            sign = 1;
            index++;
        } else if (index < n && s[index] == '-') {
            sign = -1;
            index++;
        }

        // traverse all digit until non-digit
        while (index < n && isdigit(s[index])) {
            int digit = s[index] - '0';

            // check overflow and underflow
            if ((result > INT_MAX / 10)
                || ((result == INT_MAX / 10) && (digit > INT_MAX % 10))
                ) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            index++;
        }

        return result * sign;
    }

};

int main(int argc, char* argv[]) {
    // input data
    string data("42");

    // solution
    Solution s;
    int ans = s.myAtoi(data);

    // print
    cout << "Answer: " << ans << endl;
}