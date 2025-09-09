#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieveOfEratosthenes(int n) {
    
    vector<bool> prime(n + 1, true);  // initially assume all numbers are prime
    prime[0] = prime[1] = false;      // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= n; p++) {
        
        if (prime[p]) {
            
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }

        }
    }
    
    return prime;
}

void printPrimes(vector<bool> prime) {
    
    for (int i = 2; i < prime.size(); i++) {
        if (prime[i]) cout << i << " ";
    }

    cout << endl;
}

int main() {
    int n = 100;
    
    vector<bool> prime = sieveOfEratosthenes(n);

    cout << "Prime numbers up to " << n << " are:\n";
    
    printPrimes(prime);

    return 0;
}
