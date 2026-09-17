006 Zigzag Conversion
===
`String` `Intuition`
# Explanation
* 給定一個 string 和 row number `numRows`。
* 按照垂直的 Zig-Zag 排在 2D array。
* 重新讀取 string row by row。

# Approach 1: Simulate Zig-Zag Movement
* 按照題目給的方式直接重新讀取 string。

## Complexity
* Time: $O(numRows \times n)$
* Space: $O(numRows \times n)$

# Approach 2: String Traversal
* 以 section 為單位，觀察每一個 row 的下個 char。
* 除了第一行和最後一行以外，其餘 row 皆有 section 內的另一個 char。
* 根據觀察，section 內的 char index = section 內總數 - (2 * curRow)。
* 以 row 為單位處理每一行，最後輸出即是答案。

## Complexity
* Time: $O(n)$
* Space: $O(1)$


