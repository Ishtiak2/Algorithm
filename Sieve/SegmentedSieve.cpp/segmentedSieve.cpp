#include <bits/stdc++.h>
using namespace std;

// Simple sieve to get primes up to sqrt(R)

vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p)
                isPrime[i] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; i++)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

// Segmented sieve to find primes in [L, R]
vector<int> segmentedSieve(long long L, long long R) {
    int limit = sqrt(R) + 1;
    vector<int> primes = simpleSieve(limit);

    int n = R - L + 1;
    vector<bool> isPrime(n, true);

    for (int p : primes) {
        
        long long start = (L / p) * p;
        if (start < L) start += p;

        for (long long j = start; j <= R; j += p) {
            if (j != p) { // don’t mark the prime itself
                isPrime[j - L] = false;
            }
        }
    }

    vector<int> segmentedPrimes;
    for (int i = 0; i < n; i++) {
        if (isPrime[i] && (i + L) > 1) {
            segmentedPrimes.push_back(i + L);
        }
    }

    return segmentedPrimes;
}

int main() {
    long long L = 10, R = 50;

    vector<int> segmentPrimes = segmentedSieve(L, R);

    cout << "Primes in range [" << L << ", " << R << "] are:\n";
    for (int it : segmentPrimes) cout << it << " ";
    cout << endl;

    return 0;
}
/*
https://www.youtube.com/watch?v=hacrJtF9WjI
*/