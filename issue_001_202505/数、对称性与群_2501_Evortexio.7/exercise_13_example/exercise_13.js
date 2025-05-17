function isPrime(n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 === 0 || n % 3 === 0) return false;
    let i = 5;
    let w = 2;
    while (i * i <= n) {
        if (n % i === 0) return false;
        i += w;
        w = 6 - w;
    }
    return true;
}

function modPow(a, b, mod) {
    if (mod === 1) return 0;
    let result = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 === 1)
            result = (result * a) % mod;
        b = Math.floor(b / 2);
        a = (a * a) % mod;
    }
    return result;
}

function findPseudoPrimes() {
    const aValues = [3, 24, 37];
    const pseudoPrimes = [];
    let n = 4;
    while (pseudoPrimes.length < 3) {
        if (!isPrime(n)) {
            let match = true;
            for (const a of aValues) {
                if (modPow(a, n, n) !== a % n) {
                    match = false;
                    break;
                }
            }
            if (match) pseudoPrimes.push(n);
        }
        n++;
    }
    return pseudoPrimes;
}

console.log(findPseudoPrimes());