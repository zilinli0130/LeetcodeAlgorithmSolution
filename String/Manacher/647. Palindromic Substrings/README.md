# 647. Palindromic Substrings

###### Tag:  String, Manacher Algorithm

This is a template problem for the Manacher algorithm. We could first insert pseudo character `#` in between each character of the string `s` including the head and tail to make the length of string is odd number. It could guarantee that all the length of found palindrome inside `s` is odd number since there would not be ant two idential characters sitted right next to each other after inserting the `#` character.

Let's define `p[i]` as the max extended radius of palindromic string centered at index `i`,
`ctr` is the index with the max `p[i]` in which the most right side of the palindrom centered at `ctr` is at `maxR`
`j` is the point mirrored pointed w.r.t `ctr`

```
                                                              maxR
X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X
   ---- j --------           ctr            ------- i -------
   p[j]       p[j]                           p[i]       p[i]

```
Then we could derive the expression of `p[i]` as `p[i] = min(p[j], maxR - i)` due to the property of symmetry
The total number of palindrome is `sum{{p[i] + 1)/2} for i = 0,1,...n`/ The reason why we need to `/2` is to remove the pseudo effect of `#` character.