002 Add Two Numbers
===

# Explanation
* 利用 linked list 把十進位的數字串起來。
* 執行數學加法後，回傳 linked list 答案。

# Approach
* 按照數學加法一個位元一個位元加。
* 記得要處理 carry (進位)。
* 使用 dummy head 讓程式更優雅。

## Complexity
* Time: $O(max(m, n))$
* Space: $O(1)$

