080 Remove Duplicates from Sorted Array II
===

# Explanation
* sorted array 移除重複超過兩次的項目。
* in-place。

# Approach 1
* 用兩個 pointer：一個負責走訪所有 element；另一個紀錄最後一個有效值。
* 使用一個 `count` 紀錄重複的次數，如遇到不同數值則直接 `reset to 1`。
* 只要遇到數值不等於最後一個有效值，就將指標往後並且做 data copy。
* 如果遇到數值相等，但是 `count <= 2`，就將指標往後並且做 data copy。

## Complexity
* Time: $O(n)$
* Space: $O(1)$

# Approach 2
* 用兩個 pointer：一個負責走訪所有 element；另一個紀錄最後一個有效值。
* 只需要比較倒數第二個有效值，如果大於就做 data copy。
* 前兩個不需要做判斷。

## Complexity
* Time: $O(n)$
* Space: $O(1)$