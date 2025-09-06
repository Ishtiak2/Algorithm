#include <bits/stdc++.h>
using namespace std;

//Segmented Sieve of Eratosthenes, which is used to find prime numbers in a range [L, R], especially when R is very large (up to 10¹²) but the range size R - L is reasonably small (like 10⁶).
// Simple Sieve to generate all primes up to √R
vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}

// Segmented Sieve for range [L, R]
vector<int> segmentedSieve(long long L, long long R) {
    long long limit = sqrt(R) + 1;
    vector<int> primes = simpleSieve(limit);

    vector<bool> isPrime(R - L + 1, true);

    // Handle small L
    if (L == 1) isPrime[0] = false;

    for (int p : primes) {
        long long start = max(p * p, ((L + p - 1) / p) * p);

        for (long long j = start; j <= R; j += p) {
            isPrime[j - L] = false;
        }
    }

    vector<int> result;
    for (long long i = L; i <= R; i++) {
        if (isPrime[i - L]) result.push_back(i);
    }

    return result;
}

int main() {
    long long L, R;
    cout << "Enter the range [L, R]: ";
    cin >> L >> R;

    vector<int> primesInRange = segmentedSieve(L, R);

    cout << "Primes in the range [" << L << ", " << R << "] are:\n";
    for (int p : primesInRange) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
