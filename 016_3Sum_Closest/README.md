016 3Sum Closest
===
`Array` `Two Pointers`
# Explanation
* 給定一個整數 array。
* 在所有三個相加的值中，最靠近 target 的值。

# Approach 1: Two Pointers
* Sorting Array.
* 從左到右依序做 two pointers 的算法。
* 需要記錄當前的 index `i`，以此為起點 `i+1` 做 two pointers。
* keep tracking the diff between target and sum.

## Complexity
* Time: $O(n^2)$
* Space: $O(\log n)$, for sorting.


