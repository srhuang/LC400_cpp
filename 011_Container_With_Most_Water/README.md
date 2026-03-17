011 Container With Most Water
===

# Explanation
* Array index 差距代表 width,  Array value 代表 height。
* 兩邊高度不同時，取較小的值為 height。
* Area = width * height，找出最大的面積值。

# Approach 1: Brute Force
* 將所有可能性全部走訪一次。
* 這個解法會造成 Time Limit Exceeded。

## Complexity
* Time: $O(n^2)$
* Space: $O(1)$

# Approach 2: Two Pointers
* 用兩個 pointer： 一個指向頭，一個指向尾端。
* 如果要縮小 width，一定要找 height 較低的縮小，否則面積一定不會比較大。

## Complexity
* Time: $O(n)$
* Space: $O(1)$
