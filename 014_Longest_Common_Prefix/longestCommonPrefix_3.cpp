#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        return divide(strs, 0, strs.size()-1);
    }

private:
    string divide(vector<string>& strs, int left, int right) {
        if(left == right) {
            return strs[left];
        }

        int mid = (left + right) / 2;
        string lcpLeft = divide(strs, left, mid);
        string lcpRight = divide(strs, mid + 1, right);
        return conquer(lcpLeft, lcpRight);
    }

    string conquer(string lcpLeft, string lcpRight) {
        int minSize = min(lcpLeft.size(), lcpRight.size());
        for(int i = 0; i < minSize; i++) {
            if(lcpLeft[i] != lcpRight[i]) {
                return lcpLeft.substr(0, i);
            }
        }
        return lcpLeft.substr(0, minSize);
    }
};

int main(int argc, char* argv[]) {
    // input data
    vector<string> strs = {"flower", "flow", "flight"};

    // solution
    Solution s;
    string ans = s.longestCommonPrefix(strs);

    // print
    cout << "Answer: " << ans << endl;

    return 0;
}