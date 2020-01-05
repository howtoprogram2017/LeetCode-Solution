## 1307. Minimum Insertion Steps to Make a String Palindrome
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

### Example 1:
_ _ _
**Input**: s = "zzazz"

**Output**: 0

Explanation: The string "zzazz" is already palindrome we don't need any insertions.
### Example 2:
_ _ _
**Input**: s = "mbadm"

**Output**: 2

**Explanation**: String can be "mbdadbm" or "mdbabdm".
### Example 3
_ _ _
**Input**: s = "leetcode"

**Output**: 5

Explanation: Inserting 5 characters the string becomes "leetcodocteel".
### Example 4:
_ _ _
**Input**: s = "g"

**Output**: 0
### Example 5:
_ _ _
**Input**: s = "no"

**Output**: 1
