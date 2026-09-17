007 Reverse Integer
===
`Interger` `Math`
# Explanation
* 給定一個 integer。
* 回傳將每個位元反轉後的 integer。
* 需要處理 integer overflow / underflow。

# Approach 1: Pop and Push
* Pop : 處理最後一位的數字。
* Push : 接在最終答案的後面。
* overflow condition : `if(rev > INT_MAX / 10)`
* overflow condition : `if(rev == INT_MAX / 10 && pop > INT_MAX % 10)`
* underflow condition : `if(rev < INT_MIN / 10)`
* underflow condition : `if(rev == INT_MIN / 10 && pop < INT_MIN % 10)`
* INT_MAX = 2147483647
* INT_MIN = -2147483648

## Complexity
* Time: $O(log(x))$
* Space: $O(1)$



