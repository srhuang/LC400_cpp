#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        if (p.size() == 0) {
            return (s.size() == 0);
        }

        // first match
        bool firstMatch = ((s.size() != 0) 
            && (s[0] == p[0] || p[0] == '.'));

        // recursive
        if ((p.size() >= 2) && p[1] == '*') {
            return (isMatch(s, p.substr(2))
                || (firstMatch && isMatch(s.substr(1), p)));
        } else {
            return (firstMatch && isMatch(s.substr(1), p.substr(1)));
        }

    }

};

int main (int argc, char* argv[]) {
    // input data
    string text = "aa";
    string pattern = "a*";

    // solution
    Solution s;
    bool ans = s.isMatch(text, pattern);

    // print
    cout << "Answer: " << ans << endl;
}