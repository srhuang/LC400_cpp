#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }

        // horizontal scanning
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            while(strs[i].find(prefix) != 0) {
                // remove one character
                prefix = prefix.substr(0, prefix.size() - 1);
                if(prefix.empty()) {
                    return "";
                }
            } // while
        }

        return prefix;
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