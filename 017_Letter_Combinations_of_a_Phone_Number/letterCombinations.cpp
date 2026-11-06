#include <iostream>

using namespace std;

class Solution{
    vector<string> ans; // backtracking
    unordered_map<char, string> letters = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    // variables
    string dgt = "";
    int sz = 0;;
public:
    vector<string> letterCombinations(string digits) {
        // variables
        dgt = digits;
        sz = digits.size();

        backtracking("", 0);
        return ans;
    }

private:
    void backtracking(string path, int index) {
        // pruning
        if(path.size() == sz) {
            ans.push_back(path);
            return;
        }

        // exploration
        string choices = letters[dgt[index]];
        for(int i = 0; i < choices.size(); i++) {
            path.push_back(choices[i]);
            backtracking(path, index + 1);
            path.pop_back();
        }
    }

};

int main(int argc, char* argv[]) {
    // input
    string data = "23";

    // solution
    Solution s;
    vector<string> ans = s.letterCombinations(data);

    // output
    cout << "Answer: "<< endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}