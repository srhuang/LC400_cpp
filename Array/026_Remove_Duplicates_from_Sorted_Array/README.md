026 Remove Duplicates from Sorted Array
===

# Explanation
* sorted array 移除重複項目。
* in-place。

# Approach 1
* 用兩個 pointer：一個負責走訪所有 element；另一個紀錄最後一個有效值。
* 只要遇到數值不等於最後一個有效值，就將指標往後並且做 data copy。

## Complexity
* Time: $O(n)$
* Space: $O(1)$
