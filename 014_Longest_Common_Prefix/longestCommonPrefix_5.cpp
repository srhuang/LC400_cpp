#include <iostream>

using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    int numChild;
    bool isEnd;

    // constructor
    TrieNode() {
        numChild = 0;
        isEnd = false;
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }

    void put(TrieNode* node, char c) {
        if(child[c - 'a'] == nullptr) {
            child[c - 'a'] = node;
            numChild++;
        }
    }

    TrieNode* get(char c) {
        return child[c - 'a'];
    }

    bool contains(char c) {
        return (child[c - 'a'] != nullptr);
    }

    int getNumChild() {
        return numChild;
    }
};

class Trie {
public:
    TrieNode* root;

    // constructor
    Trie() {
        root = new TrieNode();
    }

    void insert(string str) {
        TrieNode* node = root;
        for(int i = 0; i < str.size(); i++) {
            char c = str[i];
            if(!node->contains(c)) {
                node->put(new TrieNode(), c);
            }
            node = node->get(c);
        }
        node->isEnd = true;
    }

    string longestPrefix(string str) {
        TrieNode* node = root;
        string prefix;
        for(int i = 0; i < str.size(); i++) {
            char c = str[i];
            // end of string
            if(node->isEnd) {
                break;
            }

            // Check whether the child has a common prefix.
            if((!node->contains(c)) || (node->numChild != 1)) {
                break;
            }

            prefix += c;
            node = node->get(c);
        }
        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        if(strs.size() == 1) {
            return strs[0];
        }

        Trie t;
        for(int i = 1; i < strs.size(); i++) {
            t.insert(strs[i]);
        }
        return t.longestPrefix(strs[0]);
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