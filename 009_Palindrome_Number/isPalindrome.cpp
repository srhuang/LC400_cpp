#include <iostream>

using namespace std;

class Solution {

public:
    bool isPalindrome(int x) {

        // negative integer could not be palindrome
        if (x < 0 || (x % 10 ==0 && x != 0)) {
            return false;
        }

        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit
        if ((rev == x) || rev / 10 == x) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char* argv[]) {
    // input data
    int data = 1221;

    //solution
    Solution s;
    bool ans = s.isPalindrome(data);

    // print
    cout << "Answer: " << ans << endl;
}