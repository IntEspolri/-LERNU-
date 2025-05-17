#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int i = 5;
    int w = 2;
    while (i * i <= n) {
        if (n % i == 0) return false;
        i += w;
        w = 6 - w;
    }
    return true;
}

int mod_pow(int a, int b, int mod) {
    if (mod == 1) return 0;
    int result = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return result;
}

int main() {
    int a_values[] = {3, 24, 37};
    int pseudo_primes[3];
    int count = 0;
    int n = 4;
    while (count < 3) {
        if (!is_prime(n)) {
            int match = 1;
            for (int i = 0; i < 3; i++) {
                int a = a_values[i];
                if (mod_pow(a, n, n) != a % n) {
                    match = 0;
                    break;
                }
            }
            if (match) pseudo_primes[count++] = n;
        }
        n++;
    }
    printf("[%d, %d, %d]\n", pseudo_primes[0], pseudo_primes[1], pseudo_primes[2]);
    return 0;
}