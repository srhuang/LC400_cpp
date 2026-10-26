167 Two Sum II
===
`Array` `Two Pointers`
# Explanation
* Given sorted array.
* Return two indices of the two numbers such that they add up to a specific target number.

# Approach 1: Two Pointers
* 使用兩個 pointers，分別指向 array 的兩端。
* 如果 pointers 所指的值相加小於目標，就將左邊的 pointer 向右移動。
* 如果 pointers 所指的值相加大於目標，就將右邊的 pointer 向左移動。
* 如果相等，就找到答案了。

## Complexity
* Time: $O(n)$
* Space: $O(1)$