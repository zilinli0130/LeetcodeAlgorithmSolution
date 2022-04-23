# 204. Count Primes

###### Tag: Math

###### Time: O(N*loglogN)
###### Space: O(N)

Sieve of Eratosthenes (埃拉托斯特尼筛法)

To find out the count of prime number withint `[2,n)`, we only need to loop through all the integers between `[2,sqrt(n)]`. If we encounter a prime number, we
could find out that all its multiples are not prime number since their multiple is the multiply of at least one prime number and other number. In such way, we 
could dramatically reduce the time complexity to `O(N*loglogN)`.



```
Follow-up: Find all the prime factor for a given number
Time: O(logN) for composite number, O(N) for prime number
Space: O(1)

vector<int> res;
int num = 100000, prime = 2;
while (num > 1) {

    cout << num << endl;
    if (num % prime == 0) {
        num /= prime;
        res.push_back(prime);
        continue;
    }
    prime++;
}

Check if a number n is prime number or not:
we need to only loop through all its factor in the range of [2, sqrt(n)]. 

Since for any random integers a,b which satisfy axb=n:
if a >= sqrt(n), then b <= sqrt(n)
if a <= sqrt(n), then b >= sqrt(n)

It means that if we can not find a random factor a inside the range of [2, sqrt(n)], we can not find its pair factor b inside the range of [sqrt(n), n-1]

```
