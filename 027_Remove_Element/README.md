027 Remove Element
===
`Array` `Two Pointers`
# Explanation
* 給定一個任意 array，刪除所有特定值。
* in-place: without requiring extra space。

# Approach 1: Two Pointers
* 用兩個 pointer：一個負責走訪所有 element；另一個紀錄最後一個有效值。
* 只要遇到數值不符合特定值就做 data copy 到第一個無效數值，並且將指標往後。

## Complexity
* Time: $O(n)$
* Space: $O(1)$

# Approach 2: Two Pointers - when elements to remove are rare
* 思考一種情況：整個陣列只有頭是特定值，那這樣解法一就會做很多次 data copy。
* 用兩個 pointer：一個紀錄最後一個有效值；另一個紀錄最後一個未處理的數值。
* 只要遇到數值符合特定值，就從陣列尾端 data copy，下個回合同個位置繼續檢查。

## Complexity
* Time: $O(n)$
* Space: $O(1)$
