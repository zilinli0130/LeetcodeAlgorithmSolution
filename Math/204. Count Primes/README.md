# 204. Count Primes

###### Tag: Math

###### Time: O(N*loglogN)
###### Space: O(N)

Sieve of Eratosthenes (埃拉托斯特尼筛法)

To find out the count of prime number withint `[2,n)`, we only need to loop through all the integers between `[2,sqrt(n)]`. If we encounter a prime number, we
could find out that all its multiples are not prime number since their multiple is the multiply of at least one prime number and other number. In such way, we 
could dramatically reduce the time complexity to `O(N*loglogN)`.