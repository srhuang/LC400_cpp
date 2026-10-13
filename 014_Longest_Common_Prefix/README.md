014 Longest Common Prefix
===
`String` `Trie`
# Explanation
* find the longest common prefix string amongst an array of strings.

# Approach 1: Horizontal scanning
* 先用第一個 string 完整的當成 prefix 和第二個 string 比較。
* 不成功就將 prefix 少一個 char，然後繼續和第二個 string 比較。
* 直到 prefix is empty，就代表沒有 common prefix。
* 成功後再用 prefix 跟第三個 string 比較，直到最後。

## Complexity
* Time: $O(S)$, where S is the sum of all characters in all strings.
* Space: $O(1)$

# Approach 2: Vertical scanning
* 先把每個字串的第一個字母作比較。
* 如果成功就繼續比較下個字母。
* 如果失敗就回傳到目前為止的成功 substring。

## Complexity
* Time: $O(S)$, best case is $O(n \times minLen)$, there are `n` strings.
* Space: $O(1)$

# Approach 3: Divide and Conquer
* 將比較兩字串這件事分成左右兩堆。(Divide)
* 然後分層的兩兩比較。(Conquer)
* recursion depth is $O(\log n)$, we have `n` strings.

## Complexity
In the worst case we have `n` equal strings with length `m`.
* Time: $O(S)$.
* Space: $O(m \times \log n)$

# Approach 4: Binary Search
* 針對最終的答案使用 binary search。
* 差別只是在於，比較運算不是找數字，而是判斷是否有 common prefix。
* middle 通常會靠左邊，因為 integer  的緣故。
* 終止條件中，right 會是最終答案，而 left = right + 1.(跳出 while loop)

## Complexity
In the worst case we have `n` equal strings with length `m`.
* Time: $O(S\times\log m)$, 
* Space: $O(1)$

# Approach 5: Trie
* Build the trie.
* Using the first string to query the longest common prefix.
* Using `isEnd` to mark the end of string.

## Complexity
In the worst case we have `n` equal strings with length `m`.
* Time: $O(S)$ to build trie, $O(m)$ for query.
* Space: $O(S)$ for trie.
