#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = 
            {{')', '('}, {']', '['}, {'}', '{'}};
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (mapping.find(c) == mapping.end()) {
                // open brackets
                st.push(c);
            } else if (!st.empty() && (mapping[c] == st.top())) {
                st.pop();
            } else {
                return false;
            }
        } // for
        return st.empty();
    }
};

int main(int argc, char* argv[]) {
    // input
    string data = "()[]{}";

    // solution
    Solution s;
    bool ans = s.isValid(data);

    // output
    cout << "Answer: " << ans << endl;

    return 0;
}