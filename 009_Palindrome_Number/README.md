009 Palindrome Number
===
`Integer` `Math`
# Explanation
* determin the integer is a palindrome.

# Approach 1: Revert half of the number
* negative could not be a palindrome.
* 最後一位是 0，除非是 0 本身，不然不會是 palindrome。
* 奇數長度的 integer 可以不用考慮正中間的數字。

## Complexity
* Time: $O(\log_{10} n)$
* Space: $O(1)$
