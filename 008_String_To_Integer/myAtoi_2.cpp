#include <iostream>

using namespace std;

// construct the state machine
enum State {s0, s1, s2, s3};
class StateMachine {
    State state;
    int sign;
    int result;

public:
    // constructor
    StateMachine() {
        state = s0;
        sign = 1;
        result = 0;
    }

    void trans(char ch) {
        switch (state) {
            case s0:
                state_s0(ch);
                break;
            case s1:
                state_s1(ch);
                break;
            case s2:
                state_s2(ch);
                break;
            case s3:
                state_s3(ch);
                break;
            default:
            //error handling
                break;
        }
    }

    int getResult() {
        return sign * result;
    }

    State getState() {
        return state;
    }

private:
    void state_s0(char ch) {
        if (ch == ' ') {
            return;
        } else if ((ch == '-') || (ch == '+')) {
            sign = (ch == '+') ? 1 : -1;
            state = s1;
        } else if (isdigit(ch)) {
           appendDigit(ch);
        } else {
            state = s3;
        }
    }

    void state_s1(char ch) {
        if (isdigit(ch)) {
            appendDigit(ch);
        } else {
            state = s3;
        }
    }

    void state_s2(char ch) {
        if (isdigit(ch)) {
            appendDigit(ch);
        } else {
            state = s3;
        }
    }

    void state_s3(char ch) {
        return;
    }

    void appendDigit(char ch) {
        int digit = ch - '0';
        
        // check overflow and underflow
        if ((result > INT_MAX / 10)
            ||((result == INT_MAX / 10) && (digit > INT_MAX % 10))
            ) {
            if (sign == 1) {
                result = INT_MAX;
            } else {
                result = INT_MIN;
                sign = 1; // no need to deal with sign
            }

            state = s3;
        } else {
            result = result * 10 + digit;
            state = s2;
        }
    }

};

class Solution {
public:
    int myAtoi(string s) {
        StateMachine sm;

        for (int i = 0; (i < s.size()) && (sm.getState() != s3); i++) {
            sm.trans(s[i]);
        }

        return sm.getResult();
    }

};

int main(int argc, char* argv[]) {
    // input data
    string data("42");

    // solution
    Solution s;
    int ans = s.myAtoi(data);

    // print
    cout << "Answer: " << ans << endl;
}