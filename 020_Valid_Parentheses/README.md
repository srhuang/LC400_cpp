020 Valid Parentheses
===
`Stack` `Operation`
# Explanation
* 給定一個充滿括號的字串。
* 判斷括號是否符合合法。

# Approach 1: Stack
* Using stack.
* push stack when encounter an opening bracket.
* pop stack when encounter an closing bracket and checking the top of stack.
* in the end, the stack should be empty.

## Complexity
* Time: $O(n)$, traverse the string.
* Space: $O(n)$, for the stack.


