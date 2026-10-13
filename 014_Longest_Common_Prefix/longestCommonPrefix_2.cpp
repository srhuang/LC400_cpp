#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }

        // vertical scanning
        for(int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++) {
                if((strs[j].size() == i) || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            } // for
        } // for

        return strs[0];
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