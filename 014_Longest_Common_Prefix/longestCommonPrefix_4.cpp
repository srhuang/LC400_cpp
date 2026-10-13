#include <iostream>

using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }

        // find min length of the strings
        int minLen = INT_MAX;
        for(int i = 0; i < strs.size(); i++) {
            minLen = min(minLen, (int)strs[i].size());
        }

        // binary search
        int left = 1;
        int right = minLen;
        while(left <= right) {
            int mid = (left + right) / 2;
            // comparison function
            if(compare(strs, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return strs[0].substr(0, (left + right) / 2);
    }

private:
    bool compare(vector<string>& strs, int size) {
        string str1 = strs[0].substr(0, size);
        for(int i = 1; i < strs.size(); i++) {
            if(strs[i].find(str1) != 0 ) {
                return false;
            }
        }
        return true;
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