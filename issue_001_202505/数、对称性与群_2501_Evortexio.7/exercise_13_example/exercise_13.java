import java.util.ArrayList;
import java.util.List;

public class PseudoPrime {
    public static void main(String[] args) {
        List<Integer> pseudoPrimes = new ArrayList<>();
        int[] aValues = {3, 24, 37};
        int n = 4;
        while (pseudoPrimes.size() < 3) {
            if (!isPrime(n)) {
                boolean match = true;
                for (int a : aValues) {
                    if (modPow(a, n, n) != a % n) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    pseudoPrimes.add(n);
                }
            }
            n++;
        }
        System.out.println(pseudoPrimes);
    }

    private static boolean isPrime(int n) {
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

    private static int modPow(int a, int b, int mod) {
        if (mod == 1) return 0;
        int result = 1;
        a = a % mod;
        while (b > 0) {
            if ((b & 1) == 1)
                result = (result * a) % mod;
            b >>= 1;
            a = (a * a) % mod;
        }
        return result;
    }
}