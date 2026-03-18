003 Longest Substring Without Repeating Characters
===

# Explanation
* 給定一個 string。
* 找出最長不重複字元的 substring。

# Approach 1: Brute Force (LTE)
* 窮舉所有 substring。
* 檢查並更新最大長度。

## Complexity
* Time: $O(n^3)$
* Space: $O(min(n, m))$ (size of the charset/alphabet `m`)

# Approach 2: Sliding Window with Count
* 紀錄當前 sliding window 字元出現的數量。
* 當 window 向右 expand 時，檢查該字元數量。
* 如果數量超過一個，則一直移動左邊邊界，直到數量只剩一個。
* 更新最大長度值。

## Complexity
* Time: $O(n)$
* Space: $O(m)$ (size of the charset/alphabet `m`)

# Approach 3: Sliding Window with Hash
* 紀錄當前 sliding window 字元出現的數量。
* 當 window 向右 expand 時，檢查該字元最後出現的 index。
* 如果 index 位在 sliding window 中，則移動左邊邊界。
* Hash 裡面的 index value 要從 1 開始，否則會無法辨認是 `index = 0` 還是不存在。

## Complexity
* Time: $O(n)$
* Space: $O(m)$ (size of the charset/alphabet `m`)

