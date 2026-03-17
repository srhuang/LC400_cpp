001 Two Sum
===

# Explanation
* 給定一個任意的 array ，以及一個 target value。
* 回傳兩個 index numbers。
* index 所含的值相加等於 target value。

# Approach 1: Brute Force
* 檢查每一個 value x。
* 確認 array 是否有另一個 target - x 。

## Complexity
* Time: $O(n^2)$
* Space: $O(1)$

# Approach 2: Hash Table
* 計算每個 element 的差值。
* 在 hash table 中找尋是否存在差值。
* 如果不存在則加入該 value 到 hash table 中。
* 如果存在則回傳這兩個 index。

## Complexity
* Time: $O(n)$
* Space: $O(n)$ (hash table)
