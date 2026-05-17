005 Longest Palindromic Substring
===

# Explanation
* 給定一個 string。
* 找出最長的回文 substring。

# Approach 1: Brute Force
* 窮舉所有 substring。
* 從最長的substring 開始檢查是否有回文。
* 一找到符合條件就立刻返回。

## Complexity
* Time: $O(n^3)$
* Space: $O(1)$

# Approach 2: Dynamic Programming
* 建立 DP table 的起始值。
* 從最短長度的 substring 開始檢查。
* 走訪所有可能的起始點。
* 最後更新的 answer 就是最長回文 substring。

## Complexity
* Time: $O(n^2)$
* Space: $O(n^2)$

# Approach 3: Expand From Centers
* 挑選中心點，並且分成長度為奇數和偶數的 substring。
* 分別找出最長的回文 substring。
* 最後檢查並更新 answer。

## Complexity
* Time: $O(n^2)$
* Space: $O(1)$

