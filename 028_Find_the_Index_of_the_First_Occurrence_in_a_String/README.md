028 Find the Index of the First Occurrence in a String
===
`String` `Sliding Window`
# Explanation
* Given two strings `haystack` and `needle`.
* return the index of the first occurrence of `needle` in `haystack`.
* $size_n$ denote to the length of the needle, $size_h$ denote to the length of the haystack.

# Approach 1: Sliding Window
* check all substrings.

## Complexity
* Time: $O(size_h\times size_n)$, $O((size_h−size_n+1)\times size_n) = O(size_h\times size_n)$
* Space: $O(1)$

# Approach 2: Rabin-Karp Algorithm (Single Hash)
* design the hash function.
* calculate the hash value of the needle.
* calculate the hash value of the substring of haystack.
* compare char by char when the hash values match.
* `(a-b)%mod` = `(a%mod - b%mod)%mod`, if `(a%mod - b%mod)` is negative, we need add mod, such that `(a%mod + mod - b%mod)%mod`.

## Complexity
* Time: $O(size_h\times size_n)$, $O(size_h+size_n)$ for best case, cause $O(size_n+size_n+(size_h-size_n))$.
* Space: $O(1)$

# Approach 3: Rabin-Karp Algorithm (Double Hash)
* minimize the chance of spurious hits.

## Complexity
* Time: $O(size_h)$, $O(size_n+size_n+(size_h−size_n))$, We can ignore $size_n$ cause $size_h$ > $size_n$.
* Space: $O(1)$

# Approach 4: Knuth–Morris–Pratt Algorithm
* 主要是分析 needle 字串架構，盡可能避免 check char by char.
* build the Longest Prefix Suffix(LPS).
* 當發現 needle and haystack not match, 利用 LPS 來跳過不需要檢查的 prefix.

## Complexity
* Time: $O(size_h)$, build LPS takes $O(size_n)$, searching takes $O(size_h)$. We can ignore $size_n$ cause $size_h$ > $size_n$.
* Space: $O(size_n)$, for LPS.

