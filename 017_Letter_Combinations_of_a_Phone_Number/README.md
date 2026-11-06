017 Letter Combinations of a Phone Number
===
`String` `Backtracking`
# Explanation
* Given the string of digits.
* return all possible letter combinations.

# Approach 1: Backtracking
* map for digits and letters.
* backtracking.
* pruning if the path is the same size as the letters.

## Complexity
* Time: $O(4^n \times n)$
* Space: $O(n)$, the depth of the recursion.



