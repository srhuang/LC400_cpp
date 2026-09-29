010 Regular Expression Matching
===
`String` `DP`
# Explanation
* 檢查 text string 是否有 match pattern。
* `.` : any single character.
* `*` : zero or more of the preceding character.

# Approach 1: Recursion
* check the first match.
* for Kleene star `*`, we need to deal with two cases: zero and one match.
* each case means separate recursion tree.

## Complexity
* 困難的是 recursion tree 的 time complexity 計算。
* Time Complexity : 整棵 recursion tree 有多少 nodes。
* 考慮 worse case : s = aaaa, p = a\*a\*a\*a\*
* 將 recursion 畫成一棵樹。
* `(M, N)` : `M` 表示 text 總長度，`N` 表示 pattern 總長度。
* `(i, j)` : `i` 表示 s parsing 到的 index, `j` 表示 p parsing 到的 index。
* 每一個狀態（tree node）: `(i, j)` 都有 $\binom{i+j}{i}$ 種不同的 path 抵達。
* 最終有 ($M * \frac{N}{2}$) 不同的 tree node，每一個 tree 會有重複 $\binom{i+j}{i}$ 個 tree node，因此總 tree node 有 $O((M+N)2^{(M+N/2)})$。
* 可以簡化理解成：每遇到`*` recursion tree 就會分裂成兩倍，因此 time complexity: $O(2^n)$
* Time: $O((M+N)2^{(M+N/2)})$ or $O(2^N)$
* Space Complexity : recursion tree 的最大 depth。
* Space: $O(M+N)$

# Approach 2: DP
* `M` 表示 text 總長度，`N` 表示 pattern 總長度。
* State: `dp[i, j]`, take the first i(and j) elements.
* Base case: If the length of the pattern is 0, all text is a mismatch except for empty text.
* Transition: for normal case, depends on `dp[i-1, j-1]`; for Kleene Star(*), depends on `dp[i-1][j]` and `dp[i][j-2]`.
* Answer: `dp[M][N]`

## Complexity
* Time: $O(M\times N)$
* Space: $O(M\times N)$