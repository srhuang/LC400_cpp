012 Integer to Roman
===
`Integer` `Math`
# Explanation
* 整數轉成羅馬數字。
* M(1000), D(500), C(100), L(50), X(10), V(5), I(1)
* CM(900), CD(400), XC(90), XL(40), IX(9), IV(4)
* 盡可能最大的羅馬數字表示。

# Approach 1: Greedy
* 將數值與羅馬數字由大到小一一排列對應。
* 依序從最大的開始產出羅馬數字。

## Complexity
* Time: $O(1)$
* Space: $O(1)$
