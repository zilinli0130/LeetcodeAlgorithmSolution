# 76. Minimum Window Substring
###### Tag: Two Pointers, Sliding Window, Hash Table

We first need to use a map to store all the characters for stirng `t`. The goal for the substring `s[i:j]` inside string `s` is to satisfy that the every character in t (including duplicates) is included (`M`). Once we find out this potential substring, we could move left pointer `i` to the right to find out a smaller substring. Rememeber to decrease the count of `s[i]`. Once `M` is not satisfied, we could add more elements by moving right pointer `j` to the right and continue the search.   