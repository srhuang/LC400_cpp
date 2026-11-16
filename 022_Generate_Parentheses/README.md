022 Generate Parentheses
===
`String` `Backtracking`
# Explanation
* generate all combinations of well-formed parentheses.

# Approach 1: Brute Force
* Using queue for BFS all combinations.
* Using left count to check the parentheses is valid.

## Complexity
* Time: $O(2^{2n}\times n)$.
* Space: $O(2^{2n}\times n)$, $2^{2n}$ strings of length $n$, for the second to last level of BFS.

# Approach 2: Backtracking
* 新增左括號，當左括號小於 `n`。
* 新增右括號，當左括號大於右括號。
* 其他狀況會進行剪枝(pruning)。

## Complexity
* Time: $O(\frac {4^n}{\sqrt n})$, `n`th Catalan Number.
* Space: $O(n)$, the depth of the recursive call stack.

# Approach 3: Divide and Conquer
* divide this problem into `left_string` and `right_string`。
* valid string = ( `left_string` ) `right_string`
* $C(n) = "(" + C(0) + ")" + C(n-1)$
* $C(n) = "(" + C(1) + ")" + C(n-2)$
* $C(n) = "(" + C(n-1) + ")" + C(0)$

## Complexity
* Time: $O(\frac {4^n}{\sqrt n})$, $T(n) = \sum _{i=1} ^{n} \frac {4^i}{\sqrt i}$.
* Space: $O(n)$, the maximum depth of the recursion stack.
