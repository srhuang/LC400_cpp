189 Rotate Array
===

# Explanation
* 將 array 向右旋轉 `k` 次。
* array size is `n`.

# Approach 1: Brute Force
* 每次向右移動所有的值。
* 重複 `k` 次。
* 這個解法會造成 Time Limit Exceeded。

## Complexity
* Time: $O(n\*k)$
* Space: $O(1)$

# Approach 2: Using Extra Array
* 直接使用另一個 array 存儲旋轉後的結果。

## Complexity
* Time: $O(n)$
* Space: $O(n)$

# Approach 3: Using Cyclic Replacements
* 從第0個開始，將數值放到正確的位置。
* 可能會有數個 cyclic。
* 閉環回到頭後，加一便是下個 cyclic。
* 直到做完 `n` 次。

## Complexity
* Time: $O(n)$
* Space: $O(1)$

# Approach 4: Using Reverse
* reverse all array
* reserse first `k` elements
* reverse last `n-k` elements


## Complexity
* Time: $O(n)$
* Space: $O(1)$
