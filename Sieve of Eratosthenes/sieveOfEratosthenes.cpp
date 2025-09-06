#include <bits/stdc++.h>
using namespace std;

// Function to perform Sieve of Eratosthenes
// Marks all prime numbers up to n
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true); // initially assume all are primes
    isPrime[0] = isPrime[1] = false;   // 0 and 1 are not primes

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            // Mark multiples of i as non-prime
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

int main() {
    int n;
    cout << "Enter the limit: ";
    cin >> n;

    vector<bool> isPrime = sieve(n);

    cout << "Prime numbers up to " << n << " are:\n";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
