004 Median of Two Sorted Arrays
===
`Array` `Binary Search`
# Explanation
* 給定兩個已排序的 Array: n1, n2。
* 找出中位數。
* 時間複雜度為 $O(log(n1+n2))$

# Approach
* n1 是長度較短的 array。
* 直接在 n1 上做 binary search，以尋找符合特定條件的 m1。
* 中位數的 index 可以先算好，因此給定 n1, n2，就可以決定中位數 index k。
* m2 = k - m1。
* 目標找到 m1 符合條件：n1[m1-1] <= n2[m2] && n2[m2-1] <= n1[m1]。
* m1 or m2 等於 0 表示完全不取該陣列數值。
* m1 or m2 等於 size 表示完全取該陣列的數值。
* 因此需要在兩個 array n1, n2 的兩端加上 `INT_MIN` and `INT_MAX`。
* 需要考慮總個數是奇數還是偶數。
* 這題困難的是邊際條件很複雜。
* 參考 [Tushar Roy - Coding Made Simple](https://www.youtube.com/watch?v=LPFhl65R7ww)

## Complexity
* Time: $O(log(min(n1, n2)))$
* Space: $O(1)$


