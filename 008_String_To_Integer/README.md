008 String to Integer
===
`String` `DFA`
# Explanation
* 給定一個 string。
* 回傳 integer。
* Ignore whitespace。
* 需要處理正負號。
* 如果遇到 non-digit 則停止。
* 需要處理 integer overflow / underflow。

# Approach 1: Follow the Rules
* Discard all whitespace.
* check the sign.
* traverse all digit until non-digit.
* check the overflow and underflow.
* overflow condition : `if(result > INT_MAX / 10)`
* overflow condition : `if(result == INT_MAX / 10 && digit > INT_MAX % 10)`
* INT_MAX : 2147483647
* INT_MIN : -2147483648
* return `result * sign`.

## Complexity
* Time: $O(n)$
* Space: $O(1)$

# Approach 2: DFA
* Using state machine to solve the general problems.
* define the state.
* define transitions occurring due to certain input.
* state 0 : initial state.
* state 1 : first sign has been found.
* state 2 : digit parsing state.
* state 3 : daemon state, the end of the parsing.

## Complexity
* Time: $O(n)$
* Space: $O(1)$

