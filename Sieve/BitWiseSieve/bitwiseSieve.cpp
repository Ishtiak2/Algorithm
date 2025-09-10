#include <bits/stdc++.h>
using namespace std;

const int N = 100;              // limit for primes
int status[(N >> 5) + 1];       // bit array (compressed storage)

// Function to check if x is composite
bool isComposite(int x) {
    int block = x / 32;         // which integer in array
    int bit   = x % 32;         // which bit inside that integer
    int mask  = 1 << bit;       // create mask with 1 at 'bit'
    return (status[block] & mask) != 0;  // true if bit is set
}

// Function to mark x as composite
void setComposite(int x) {
    int block = x / 32;
    int bit   = x % 32;
    int mask  = 1 << bit;
    status[block] = status[block] | mask;      // set that bit to 1
}

// Bitwise sieve
void bitwiseSieve(int n) {
    

    for (int i = 3; i * i <= n; i += 2) {
        if (!isComposite(i)) {
            for (int j = i * i; j <= n; j += i * 2) {
                setComposite(j);   // mark multiples of i
            }
        }
    }

    // Print primes
    cout << 2 << " ";
    for (int i = 3; i <= n; i += 2) {
        if (!isComposite(i)) cout << i << " ";
    }
    cout << endl;
}

int main() {
    bitwiseSieve(N);
    return 0;
}

/*
time complexity is:  O( N log(logN) )
Space Complexity: O(N / 32) practically
*/