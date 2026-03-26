004 Median of Two Sorted Arrays
===

# Explanation
* 給定兩個已排序的 Array: n1, n2。
* 找出中位數。
* 時間複雜度為 $O(log(n1+n2))$

# Approach
* 利用 binary search 來找尋適當的 m1。
* 中位數的 index 可以先算好，因此給定 n1, n2，就可以決定中位數 index k。
* 注意 binary search 是在什麼條件下把 m1 剔除。
* m1 or m2 等於 0 表示完全不取該陣列數值。
* m1 or m2 等於 size 表示完全取該陣列的數值。
* 需要考慮總個數是奇數還是偶數。
* 這題困難的是邊際條件很複雜。
* 採用 [https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/](花花酱 LeetCode 4. Median of Two Sorted Arrays)

## Complexity
* Time: $O(log(min(n1, n2)))$
* Space: $O(1)$


