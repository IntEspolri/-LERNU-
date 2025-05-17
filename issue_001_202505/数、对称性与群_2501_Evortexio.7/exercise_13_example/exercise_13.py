def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    w = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += w
        w = 6 - w
    return True

def find_pseudo_primes():
    a_values = [3, 24, 37]
    pseudo_primes = []
    n = 4
    while len(pseudo_primes) < 3:
        if not is_prime(n):
            if all(pow(a, n, n) == a % n for a in a_values):
                pseudo_primes.append(n)
        n += 1
    return pseudo_primes

print(find_pseudo_primes())