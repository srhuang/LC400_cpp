#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (0 != x)
        {
            int pop = x % 10;
            x /= 10;
            // check overflow and underflow
            if ((rev > INT_MAX / 10)
                || ((rev == INT_MAX / 10) && (pop > INT_MAX % 10))
                || (rev < INT_MIN / 10)
                || ((rev == INT_MIN / 10) && (pop < INT_MIN % 10)))
            {
                return 0;
            }

            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main(int argc, char* argv[])
{
    // input data
    int data = -123;

    // solution
    Solution s;
    int ans = s.reverse(data);

    // print
    cout << "Answer: " << ans << endl;
}