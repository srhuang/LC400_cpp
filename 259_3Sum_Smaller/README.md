259 3Sum Smaller
===
`Array` `Two Pointers`
# Explanation
* 給定一個整數 array。
* 在所有三個相加的值中，小於 target 的個數。

# Approach 1: Brute Force (TLE)
* 列舉所有可能的組合，一一檢查是否有小於 target。

## Complexity
* Time: $O(n^3)$
* Space: $O(1)$

# Approach 2: Binary Search
* Sorting Array.
* 前兩個值用窮舉的方式。
* 第三個值使用 binary search 找尋小於 target 的最大 index.

## Complexity
* Time: $O(n^2\log n)$
* Space: $O(1)$

# Approach 3: Two Pointers
* Sorting Array.
* 第一個用窮舉的方式。
* 後面兩個使用 two sum pointers 的方式。

## Complexity
* Time: $O(n^2)$
* Space: $O(1)$