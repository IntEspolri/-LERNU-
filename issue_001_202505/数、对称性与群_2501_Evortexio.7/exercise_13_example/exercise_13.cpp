#include <iostream>
#include <vector>

using namespace std;

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

vector<int> find_pseudo_primes() {
    vector<int> a_values = {3, 24, 37};
    vector<int> pseudo_primes;
    int n = 4;
    while (pseudo_primes.size() < 3) {
        if (!is_prime(n)) {
            bool match = true;
            for (int a : a_values) {
                if (mod_pow(a, n, n) != a % n) {
                    match = false;
                    break;
                }
            }
            if (match) pseudo_primes.push_back(n);
        }
        n++;
    }
    return pseudo_primes;
}

int main() {
    vector<int> result = find_pseudo_primes();
    cout << "[" << result[0] << ", " << result[1] << ", " << result[2] << "]" << endl;
    return 0;
}