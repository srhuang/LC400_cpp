042 Trapping Rain Water
===

# Explanation
* Array index 差距代表 width,  Array value 代表海拔圖。
* 計算最大蓄水量。

# Approach 1: Brute Force
* 針對特定的 index，計算左邊最高的高度，再計算右邊最高的，最後取較小的高度，再用這個高度減去該 index 的高度，就是該 index 蓄水量。
* 加總每個 index 的蓄水量就是最終答案。
* 這個解法會造成 Time Limit Exceeded。

## Complexity
* Time: $O(n^2)$
* Space: $O(1)$

# Approach 2: Two Pointers
* 用兩個 pointer： 一個指向頭，一個指向尾端。
* `left_max` 紀錄截至目前左邊最高的數值。
* `right_max` 紀錄截至目前右邊最高的數值。
* 挑選高度較低的一端，準備計算蓄水量。
* 如果高度較低的一側沒有超越最大值(`left_max` or `right_max`)，則計算該 index的蓄水量。
* 如果成功更新最大值，則不須計算蓄水量。(代表該 index 無法蓄水)

## Complexity
* Time: $O(n)$
* Space: $O(1)$

