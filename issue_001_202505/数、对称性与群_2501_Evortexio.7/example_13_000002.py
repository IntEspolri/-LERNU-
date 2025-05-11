print("Welcome learning group theory! This is an example program.")
a=2
b=3
c=5
d=7
for p in range(2,999999,1):
    while a**p % p == a % p :
        while b**p % p == b % p :
            while c**p % p == c % p :
                while d**p % p == d % p :
                    print(p)
