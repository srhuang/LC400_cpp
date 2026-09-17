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

        // construct the 2D array
        int n = s.size();
        int sections = ceil(n / (2.0 * numRows - 2));
        int numCols = sections * (numRows - 1);
        vector<vector<char>> matrix(numRows, vector<char>(numCols, ' '));
        int row = 0;
        int col = 0;
        int index = 0;
        while (index < n) 
        {
            // move down
            while((row < numRows) && (index < n))
            {
                matrix[row][col] = s[index];
                row++;
                index++;
            }
            row -= 2;
            col++;

            // move up
            while ((row > 0) && (col < numCols) && (index < n))
            {
                matrix[row][col] = s[index];
                row--;
                col++;
                index++;
            }
        } // while

        // construct the answer
        string ans;
        for (row = 0; row < numRows; row++)
        {
            for (col = 0; col < numCols; col++)
            {
                if (matrix[row][col] != ' ')
                {
                    ans += matrix[row][col];
                }
            }
        }
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

