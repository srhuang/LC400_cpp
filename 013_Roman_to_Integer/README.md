013 Roman to Integer
===
`String` `Math`
# Explanation
* 羅馬數字轉成整數。
* M(1000), D(500), C(100), L(50), X(10), V(5), I(1)
* CM(900), CD(400), XC(90), XL(40), IX(9), IV(4)：減掉前面的數值。
* 一次要檢查兩個 char。

# Approach 1: Left-to-Right Pass
* 從左到右 parsing 數值會越來越小。
* 如果發現下一個數值變大，代表遇到減法的情況，一次會處理兩個 chars。

## Complexity
* Time: $O(1)$
* Space: $O(1)$
