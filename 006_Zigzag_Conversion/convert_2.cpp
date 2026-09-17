#include <iostream>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows)
    {
        if (1 == numRows)
        {
            return s;
        }

        int n = s.size();
        int numInSection = 2 * numRows - 2;
        string ans;

        // for each row
        for (int row = 0; row < numRows; row++)
        {
            int index = row;

            // for each section
            while (index < n)
            {
                ans += s[index];
                if (0 != row && row != numRows -1)
                {
                    // for index in section
                    int diff = numInSection - (2 * row);
                    int index_inSection = index + diff;
                    if (index_inSection < n)
                    {
                        ans += s[index_inSection];
                    }
                }
                index += numInSection;
            } // while
        } // for
        return ans;
    }
};

int main(int argc, char* argv[]) {
    // input data
    string data("PAYPALISHIRING");

    // solution
    Solution s;
    string ans = s.convert(data, 3);

    // print
    cout << "Answer: " << ans << endl;

}

