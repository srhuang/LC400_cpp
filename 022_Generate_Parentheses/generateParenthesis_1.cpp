#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // BFS
        queue<string> q;
        q.push("(");
        while (!q.empty()) {
            // pop from queue
            string cur = q.front();
            q.pop();

            // deal with it
            if (cur.size() == (n * 2)) {
                // check valid
                if (isValid(cur)) {
                    ans.push_back(cur);
                }
                continue;
            }

            // push all neighbors
            q.push(cur + "(");
            q.push(cur + ")");
        }
        return ans;
    }

private:
    bool isValid(string str) {
        int leftcount = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                leftcount++;
            } else {
                leftcount--;
            }

            if (leftcount < 0) {
                return false;
            }
        }
        return (leftcount == 0);
    }

};

int main(int argc, char* argv[]) {
    // input

    // solution
    Solution s;
    vector<string> ans = s.generateParenthesis(3);

    // output
    cout << "Answer: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}